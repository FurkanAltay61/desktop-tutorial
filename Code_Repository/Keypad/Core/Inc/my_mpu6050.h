/*
 * my_mpu6050.h
 *
 *  Created on: Jul 4, 2023
 *      Author: furkan
 */

#ifndef INC_MY_MPU6050_H_
#define INC_MY_MPU6050_H_

#include "stm32f4xx.h"

#define MPU6050_HWADDR 0xD0    // 7bit address 0x68 << 1 = 0xD0

#define SMPLRT_DIV_REG		0x19
#define CONFIG_REG			0x1A
#define GYRO_CONFIG_REG		0x1B
#define ACCEL_CONFIG_REG	0x1C
#define MOT_THR_REG			0x1F




#define ACCEL_XOUT_H_REG	0x3B
#define ACCEL_XOUT_L_REG	0x3C
#define ACCEL_YOUT_H_REG	0x3D
#define ACCEL_YOUT_L_REG	0x3E
#define ACCEL_ZOUT_H_REG	0x3F
#define ACCEL_ZOUT_L_REG	0x40
#define TEMP_OUT_H_REG		0x41
#define TEMP_OUT_L_REG		0x42
#define GYRO_XOUT_H_REG		0x43
#define GYRO_XOUT_L_REG		0x44
#define GYRO_YOUT_H_REG		0x45
#define GYRO_YOUT_L_REG		0x46
#define GYRO_ZOUT_H_REG		0x47
#define GYRO_ZOUT_L_REG		0x48

#define PWR_MGMT_1_REG		0x6B
#define PWR_MGMT_2_REG		0x6C

#define WHO_AM_I_REG		0x75



typedef struct{
	float GyroErrX;
	float GyroErrY;
	float AngleErrX;
	float AngleErrY;
	float Temp;
	float RawGyro[3];
	float RawAccel[3];
	float GyroAngle[3];
	float AccelAngle[3];

	float TotalAngleX;
	float TotalAngleY;

}mpu6050;

void 	mpu6050_detect(I2C_HandleTypeDef *h2cx);
uint8_t mpu6050_config(I2C_HandleTypeDef *h2cx);
uint8_t mpu6050_ConfigGyro(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu);
uint8_t mpu6050_ConfigAccel(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu);
void    mpu6050_ReadGyro(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu);
void    mpu6050_ReadAccel(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu);
void 	mpu6050_CalcAngle(I2C_HandleTypeDef *h2cx, mpu6050 *xmpu);



#endif /* INC_MY_MPU6050_H_ */
