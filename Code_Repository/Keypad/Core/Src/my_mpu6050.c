/*
 * my_mpu6050.c
 *
 *  Created on: Jul 4, 2023
 *      Author: furkan
 */

#include "my_mpu6050.h"
#include "math.h"

#define X 0
#define Y 1
#define Z 2

const float RAD_TO_DEG =  180/M_PI;

uint32_t Prevtime,CurrTime;
float elapsedTime;

void mpu6050_detect(I2C_HandleTypeDef *h2cx){
	uint8_t ret_val=0;
	//Check is mpu6050 detect by constantly reading WHO_AM_I register
	while(ret_val != 104){
		HAL_I2C_Mem_Read(h2cx, MPU6050_HWADDR, WHO_AM_I_REG,1,&ret_val,1,100);
		HAL_Delay(10);
	}
}

uint8_t mpu6050_config(I2C_HandleTypeDef *h2cx){

	uint8_t temp_val = 0;
	//1. Configure power management register
	if(HAL_I2C_Mem_Write(h2cx, MPU6050_HWADDR, PWR_MGMT_1_REG,1,&temp_val,1,10) != HAL_OK) return 1;

	//2. Configure sample rate divider
	temp_val = 0x07;
	if(HAL_I2C_Mem_Write(h2cx, MPU6050_HWADDR, SMPLRT_DIV_REG,1,&temp_val,1,10) != HAL_OK) return 1;

	//3. Configure Gyroscope Register
	temp_val = 0x10;
	if(HAL_I2C_Mem_Write(h2cx, MPU6050_HWADDR, GYRO_CONFIG_REG,1,&temp_val,1,10) != HAL_OK) return 1;

	//4. Configure Accelerometer Register
	temp_val = 0x10;
	if(HAL_I2C_Mem_Write(h2cx, MPU6050_HWADDR, ACCEL_CONFIG_REG,1,&temp_val,1,10) != HAL_OK) return 1;

	CurrTime = HAL_GetTick();

	return 0;

}


uint8_t mpu6050_ConfigGyro(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu){

	uint8_t gyro_error = 0;

	if(gyro_error == 0){
		for(uint8_t i=0;i<200;i++){
			//1. Gyro output registered are queued consecutively.
			//	 so we can read 6 byte from starting first register(GYRO_XOUT_H)
			mpu6050_ReadGyro(h2cx,xmpu);

			/*---X---*/
			xmpu->GyroErrX = xmpu->GyroErrX + xmpu->RawGyro[X];
			/*---Y---*/
			xmpu->GyroErrY = xmpu->GyroErrY + xmpu->RawGyro[Y];

			if(i==199){
				xmpu->GyroErrX = xmpu->GyroErrX/200;
				xmpu->GyroErrY = xmpu->GyroErrY/200;
				gyro_error=1;
			}
		}
	}
}

uint8_t mpu6050_ConfigAccel(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu){

	uint8_t accel_error = 0;

	if(accel_error == 0){
		for(uint8_t i=0;i<200;i++){
			//1. Accel output registered are queued consecutively.
			//	 so we can read 6 byte from starting first register(ACCEL_XOUT_H)
			mpu6050_ReadAccel(h2cx,xmpu);


			/*---X---*/
			xmpu->AngleErrX = xmpu->AngleErrX + ((atan((xmpu->RawAccel[Y] )/sqrt(pow((xmpu->RawAccel[X] ),2) +
					          pow((xmpu->RawAccel[Z]),2)))*RAD_TO_DEG));

			/*---Y---*/
			xmpu->AngleErrY = xmpu->AngleErrY + ((atan(-1*(xmpu->RawAccel[X])/sqrt(pow((xmpu->RawAccel[Y]),2) +
					          pow((xmpu->RawAccel[Z]),2)))*RAD_TO_DEG));

			if(i==199)
			{
				xmpu->AngleErrX = xmpu->AngleErrX/200;
				xmpu->AngleErrY = xmpu->AngleErrY/200;
				accel_error=1;
			}
		}
	}
}

void mpu6050_ReadGyro(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu){

	//1. Gyro output registered are queued consecutively.
	//	 so we can read 6 byte from starting first register(ACCEL_XOUT_H)
	uint8_t GyroOut[6]={0};

	HAL_I2C_Mem_Read(h2cx, MPU6050_HWADDR, GYRO_XOUT_H_REG,1,GyroOut,6,100);

	xmpu->RawGyro[X] = ((int16_t)(GyroOut[0] << 8 | GyroOut[1]))/32.8;
	xmpu->RawGyro[Y] = ((int16_t)(GyroOut[2] << 8 | GyroOut[3]))/32.8;
	xmpu->RawGyro[Z] = ((int16_t)(GyroOut[4] << 8 | GyroOut[5]))/32.8;

}

void mpu6050_ReadAccel(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu){
	//1. Accel output registered are queued consecutively.
	//	 so we can read 6 byte from starting first register(ACCEL_XOUT_H)

	uint8_t AccelOut[6]={0};

	HAL_I2C_Mem_Read(h2cx, MPU6050_HWADDR, ACCEL_XOUT_H_REG,1,AccelOut,6,100);

	xmpu->RawAccel[X] = ((int16_t)(AccelOut[0] << 8 | AccelOut[1])) / 4096.0;
	xmpu->RawAccel[Y] = ((int16_t)(AccelOut[2] << 8 | AccelOut[3])) / 4096.0;
	xmpu->RawAccel[Z] = ((int16_t)(AccelOut[4] << 8 | AccelOut[5])) / 4096.0;


}



void mpu6050_CalcAngle(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu){
	Prevtime = CurrTime;
	CurrTime = HAL_GetTick();
	elapsedTime = (CurrTime - Prevtime)/1000.0; //in terms of seconds.

	mpu6050_ReadGyro(h2cx,xmpu);

	xmpu->RawGyro[X] = xmpu->RawGyro[X] - xmpu->GyroErrX;
	xmpu->RawGyro[Y] = xmpu->RawGyro[Y] - xmpu->GyroErrY;

	xmpu->GyroAngle[X] = xmpu->RawGyro[X] * elapsedTime;
	xmpu->GyroAngle[Y] = xmpu->RawGyro[Y] * elapsedTime;


	mpu6050_ReadAccel(h2cx,xmpu);

	xmpu->AccelAngle[X] = (atan((xmpu->RawAccel[Y] )/sqrt(pow((xmpu->RawAccel[X] ),2) +
							pow((xmpu->RawAccel[Z]),2)))*RAD_TO_DEG) - xmpu->AngleErrX;
	xmpu->AccelAngle[Y] = (atan(-1*(xmpu->RawAccel[X])/sqrt(pow((xmpu->RawAccel[Y]),2) +
							pow((xmpu->RawAccel[Z]),2)))*RAD_TO_DEG) - xmpu->AngleErrY;


	xmpu->TotalAngleX = 0.98 * (xmpu->TotalAngleX + xmpu->GyroAngle[X]) + 0.02 * xmpu->AccelAngle[X];
	xmpu->TotalAngleY = 0.98 * (xmpu->TotalAngleY + xmpu->GyroAngle[Y]) + 0.02 * xmpu->AccelAngle[Y];


}
