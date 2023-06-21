/*
 * stm32f407xx_i2c_driver.c
 *
 *  Created on: Feb 20, 2019
 *      Author: admin
 */

#include "stm32f407xx_i2c_driver.h"
#include "stm32f407xx_rcc_driver.h"


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/





static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx);
static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx,uint8_t SlaveAddr);
static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx,uint8_t SlaveAddr);
static void I2C_ClearADDRFlag(I2C_Handle_t *pI2CHandle);
void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);


static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx){

	pI2Cx->CR1 |= (1 << I2C_CR1_START);

}

void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx){
	pI2Cx->CR1 |= (1 << I2C_CR1_STOP);
}

static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx,uint8_t SlaveAddr){

	SlaveAddr = SlaveAddr << 1;
	SlaveAddr &= ~(1);				//SlaveAddr is Slave address + r/nw bit=0
	pI2Cx->DR = SlaveAddr;
}


static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx,uint8_t SlaveAddr){

	SlaveAddr = SlaveAddr << 1;
	SlaveAddr |= 1;					//SlaveAddr is Slave address + r/nw bit=1
	pI2Cx->DR = SlaveAddr;
}

static void I2C_ClearADDRFlag(I2C_Handle_t *pI2CHandle){

	uint32_t dummyRead;

	//Check for Device Mode
	if(pI2CHandle->pI2Cx->SR2 & (1 << I2C_SR2_MSL)){
		//Device is in Master Mode

		if(pI2CHandle->TxRxState == I2C_BUSY_IN_RX){

			if(pI2CHandle->RxSize == 1){

				//First disable the ack
				I2C_ManageAcking(pI2CHandle->pI2Cx,DISABLE);

				//clear the ADDR flag ( read SR1 , read SR2 )
				dummyRead = pI2CHandle->pI2Cx->SR1;
				dummyRead = pI2CHandle->pI2Cx->SR2;
				(void)dummyRead;
			}
		}
		else{

			//clear the ADDR flag ( read SR1 , read SR2 )
			dummyRead = pI2CHandle->pI2Cx->SR1;
			dummyRead = pI2CHandle->pI2Cx->SR2;
			(void)dummyRead;
		}

	}
	else{
		//Device is in Slave Mode

		//clear the ADDR flag ( read SR1 , read SR2 )
		dummyRead = pI2CHandle->pI2Cx->SR1;
		dummyRead = pI2CHandle->pI2Cx->SR2;
		(void)dummyRead;
	}
}


/*
 * Peripheral Clock setup
 */

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi){

	if(EnorDi == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_PCLK_EN();
		}else if (pI2Cx == I2C2)
		{
			I2C2_PCLK_EN();
		}else if (pI2Cx == I2C3)
		{
			I2C3_PCLK_EN();
		}
	}
	else
	{
		//TODO
	}

}

/*
 * Init and De-init
 */
void I2C_Init(I2C_Handle_t *pI2CHandle){


	uint32_t tempreg=0;

	//enable the clock for the i2cx peripheral
	I2C_PeriClockControl(pI2CHandle->pI2Cx,ENABLE);

	//ack control bit
	tempreg |= pI2CHandle->I2C_Config.I2C_AckControl << 10;
	pI2CHandle->pI2Cx->CR1 = tempreg;

	//configure the FREQ field of CR2
	tempreg = 0;
	tempreg |= (RCC_GetPCLK1Value() / 1000000U);
	pI2CHandle->pI2Cx->CR2 = (tempreg & 0x3F);

	//program the device own address
	tempreg = 0;
	tempreg |= pI2CHandle->I2C_Config.I2C_DeviceAddress << 1;
	tempreg |= ( 1 << 14);
	pI2CHandle->pI2Cx->OAR1 = tempreg;

	//CCR Calculations
	uint16_t ccr_value = 0;
	tempreg = 0;
	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <= I2C_SCL_SPEED_SM){
		//mode is standart mode
		ccr_value = (RCC_GetPCLK1Value() / (2 * pI2CHandle->I2C_Config.I2C_SCLSpeed) );
		tempreg |= (ccr_value & 0xFFF);
	}
	else{
		//mode is fast mode
		tempreg |= (1 << 15);

		tempreg |= (pI2CHandle->I2C_Config.I2C_FMDutyCycle << 14);

		if(pI2CHandle->I2C_Config.I2C_FMDutyCycle == I2C_FM_DUTY_2){

			ccr_value = (RCC_GetPCLK1Value() / (3 * pI2CHandle->I2C_Config.I2C_SCLSpeed));

		}
		else{

			ccr_value = (RCC_GetPCLK1Value() / (25 * pI2CHandle->I2C_Config.I2C_SCLSpeed));

		}

		tempreg |= (ccr_value & 0xFFF);
	}

	pI2CHandle->pI2Cx->CCR= tempreg;

	//TRISE Configuration
	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <= I2C_SCL_SPEED_SM){
		//mode is standart mode

		tempreg = (RCC_GetPCLK1Value() / 1000000U) + 1;

	}
	else{
		//mode is fast mode
		tempreg = ((RCC_GetPCLK1Value() * 300) / 1000000000U) + 1;
	}

	pI2CHandle->pI2Cx->TRISE = tempreg & 0x3F;




}


void I2C_DeInit(I2C_RegDef_t *pI2Cx){

}








/*
 * Data Send and Receive
 */

void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,uint8_t  *pTxbuffer , uint32_t Len , uint8_t SlaveAddr , uint8_t Sr){

	//1. Generate Start Condition
	I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

	//2. confirm that start generation is completed by the checking the SB flag in the SR1
	// Note: Until SB is cleared SCL will be streched (pulled to LOW)
	while( ! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_SB));

	//3. Send the address of the slave with r/nw bit set to w(0) (total 8 bits)
	I2C_ExecuteAddressPhaseWrite(pI2CHandle->pI2Cx,SlaveAddr);

	//4.Confirm that address phase is completed by checking the ADDR flag is the SR1
	while( ! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_ADDR));

	//5. Clear the ADDR flag according to its software sequence
	//   Note: Until ADDR is cleared SCL will be streched (pulled to LOW)
	I2C_ClearADDRFlag(pI2CHandle);

	//6. Send the Data until Len becomes 0

	while(Len > 0){
		while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_TXE)); //Wait till TXE is set
		pI2CHandle->pI2Cx->DR = *pTxbuffer;
		pTxbuffer++;
		Len--;
	}

	//when Len becomes zero wait for TXE=1 and BTF=1 before generating the STOP condition
	// Note: TXE=1, BTF=1, means that both SR and DR are empty and the next transmission should begin
	// when BTF=1 SCL will be streched (pulled to low)
	while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_TXE));
	while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_BTF));

	//8. Generate STOP condition and master not needd to wait for the completionof stop condition
	// Note: Generating STOP, automatically clears the BTF
	if(Sr == I2C_DISABLE_SR)
		I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

}


void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,uint8_t  *pRxbuffer , uint32_t Len , uint8_t SlaveAddr , uint8_t Sr){

	//1. Generate Start Condition
	I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

	//2. confirm that start generation is completed by the checking the SB flag in the SR1
	// Note: Until SB is cleared SCL will be streched (pulled to LOW)
	while( ! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_SB));

	//3. Send the address of the slave with r/nw bit set to w(0) (total 8 bits)
	I2C_ExecuteAddressPhaseRead(pI2CHandle->pI2Cx,SlaveAddr);

	//4.Confirm that address phase is completed by checking the ADDR flag is the SR1
	while( ! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_ADDR));

	//Procedure to read only 1 byte from slave
	if(Len == 1){

		//Disable Acking
		I2C_ManageAcking(pI2CHandle->pI2Cx,I2C_ACK_DISABLE);

		//Clear the ADDR flag
		I2C_ClearADDRFlag(pI2CHandle);

		//Wait until RXNE becomes 1
		while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_RXNE));

		// Generate STOP condition and master not needd to wait for the completionof stop condition
		// Note: Generating STOP, automatically clears the BTF
		if(Sr == I2C_DISABLE_SR)
			I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

		//Read Data in to Buffer
		*pRxbuffer = pI2CHandle->pI2Cx->DR;

	}


	//Procedure to read data from slave when Len > 1
	if(Len > 1){

		//Clear the Addr Flag
		I2C_ClearADDRFlag(pI2CHandle);

		//read the data until Len becomes zero
		for(uint32_t i=Len ; i > 0 ; i--){

			//Wait until RXNE becomes 1
			while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_RXNE));

			if(i == 2) //if last 2 bytes are remaining
			{
				//Disable Acking
				I2C_ManageAcking(pI2CHandle->pI2Cx,I2C_ACK_DISABLE);;

				// Generate STOP condition and master not need to wait for the completion of stop condition
				// Note: Generating STOP, automatically clears the BTF
				if(Sr == I2C_DISABLE_SR)
					I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
			}

			//Read the data from data register in to buffer
			*pRxbuffer = pI2CHandle->pI2Cx->DR;

			//increment the buffer address
			pRxbuffer++;

		}

	}

	//re-enable ACKing
	if(pI2CHandle->I2C_Config.I2C_AckControl == I2C_ACK_ENABLE){
		I2C_ManageAcking(pI2CHandle->pI2Cx,I2C_ACK_ENABLE);
	}
}


void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi){
	if(EnOrDi == I2C_ACK_ENABLE){
		//Enable the Ack
		pI2Cx->CR1 |= (1 << I2C_CR1_ACK);
	}
	else{
		//Disable the Ack
		pI2Cx->CR1 &= ~(1 << I2C_CR1_ACK);
	}
}


/*********************************************************************
 * @fn      		  - I2C_MasterSendDataIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  Complete the below code . Also include the function prototype in header file

 */
uint8_t  I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle,uint8_t *pTxBuffer, uint32_t Len,uint8_t SlaveAddr,uint8_t Sr)
{

	uint8_t busystate = pI2CHandle->TxRxState;

	if( (busystate != I2C_BUSY_IN_TX) && (busystate != I2C_BUSY_IN_RX))
	{
		pI2CHandle->pTxBuffer = pTxBuffer;
		pI2CHandle->TxLen = Len;
		pI2CHandle->TxRxState = I2C_BUSY_IN_TX;
		pI2CHandle->DevAddr = SlaveAddr;
		pI2CHandle->Sr = Sr;

		//Implement code to Generate START Condition
		I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

		//Implement the code to enable ITBUFEN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITBUFEN);

		//Implement the code to enable ITEVTEN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITEVTEN);


		//Implement the code to enable ITERREN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITERREN);

	}

	return busystate;

}



/*********************************************************************
 * @fn      		  - I2C_MasterReceiveDataIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Complete the below code . Also include the fn prototype in header file

 */
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle,uint8_t *pRxBuffer, uint32_t Len, uint8_t SlaveAddr,uint8_t Sr)
{

	uint8_t busystate = pI2CHandle->TxRxState;

	if( (busystate != I2C_BUSY_IN_TX) && (busystate != I2C_BUSY_IN_RX))
	{
		pI2CHandle->pRxBuffer = pRxBuffer;
		pI2CHandle->RxLen = Len;
		pI2CHandle->TxRxState = I2C_BUSY_IN_RX;
		pI2CHandle->RxSize = Len; //Rxsize is used in the ISR code to manage the data reception
		pI2CHandle->DevAddr = SlaveAddr;
		pI2CHandle->Sr = Sr;

		//Implement code to Generate START Condition
		I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

		//Implement the code to enable ITBUFEN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITBUFEN);

		//Implement the code to enable ITEVTEN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITEVTEN);


		//Implement the code to enable ITERREN Control Bit
		pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITERREN);

	}

	return busystate;
}




void I2C_SlaveSendData(I2C_RegDef_t *pI2Cx,uint8_t  data){

	pI2Cx->DR = data;
}

uint8_t  I2C_SlaveReceiveData(I2C_RegDef_t *pI2Cx){

	return pI2Cx->DR ;
}





/*
 * IRQ Configuration and ISR handling
 */
void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi){

	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER3 |= ( 1 << (IRQNumber % 64) );
		}
	}else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 6 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER3 |= ( 1 << (IRQNumber % 64) );
		}
	}

}
void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){

	//1. first lets find out the ipr register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section  = IRQNumber %4 ;

	uint8_t shift_amount = ( 8 * iprx_section) + ( 8 - NO_PR_BITS_IMPLEMENTED) ;

	*(  NVIC_PR_BASE_ADDR + iprx ) |=  ( IRQPriority << shift_amount );

}



void I2C_CloseReceiveData(I2C_Handle_t *pI2CHandle)
{
	//Implement the code to disable ITBUFEN Control Bit
	pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITBUFEN);

	//Implement the code to disable ITEVFEN Control Bit
	pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITEVTEN);

	pI2CHandle->TxRxState = I2C_READY;
	pI2CHandle->pRxBuffer = NULL;
	pI2CHandle->RxLen = 0;
	pI2CHandle->RxSize = 0;

	if(pI2CHandle->I2C_Config.I2C_AckControl == I2C_ACK_ENABLE)
	{
		I2C_ManageAcking(pI2CHandle->pI2Cx,ENABLE);
	}

}

void I2C_CloseSendData(I2C_Handle_t *pI2CHandle)
{
	//Implement the code to disable ITBUFEN Control Bit
	pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITBUFEN);

	//Implement the code to disable ITEVFEN Control Bit
	pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITEVTEN);


	pI2CHandle->TxRxState = I2C_READY;
	pI2CHandle->pTxBuffer = NULL;
	pI2CHandle->TxLen = 0;
}


void I2CMasterHandleRXNEInterrupt(I2C_Handle_t *pI2CHandle){

	//We Have to do Data Reception
	if(pI2CHandle->RxSize == 1){
		*pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->DR;
		pI2CHandle->RxLen--;
	}

	if(pI2CHandle->RxSize > 1){

		if(pI2CHandle->RxLen == 2){
			//clear the ack bit
			I2C_ManageAcking(pI2CHandle->pI2Cx,DISABLE);
		}

		//read DR
		*pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->DR;
		pI2CHandle->pRxBuffer++;
		pI2CHandle->RxLen--;


	}

	if(pI2CHandle->RxLen == 0){

		//close the i2c data reception and botfiy the application

		// Generate STOP condition and master not need to wait for the completion of stop condition
		// Note: Generating STOP, automatically clears the BTF
		if(pI2CHandle->Sr == I2C_DISABLE_SR)
			I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

		//2. Close the i2c rx
			I2C_CloseReceiveData(pI2CHandle);

		//3. Notify the application
			I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_RX_CMPLT);

	}

}


void I2CMasterHandleTXEInterrupt(I2C_Handle_t *pI2CHandle){

	if(pI2CHandle->TxLen > 0){

		//1. Load the data in to DR
		pI2CHandle->pI2Cx->DR = *(pI2CHandle->pTxBuffer);

		//2. decrement the TxLen
		pI2CHandle->TxLen--;

		//3. Increment the Buffer Address
		pI2CHandle->pTxBuffer++;
	}

}

void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle){

	//Interrupt handling for both master and slave mode of a device
	uint32_t temp1,temp2,temp3;

	temp1 = pI2CHandle->pI2Cx->CR2 & ( 1 << I2C_CR2_ITEVTEN);
	temp2 = pI2CHandle->pI2Cx->CR2 & ( 1 << I2C_CR2_ITBUFEN);
	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_SB);

	//1. Handle For interrupt generated by SB event
	//	Note : SB flag is only applicable in Master mode
	if(temp1 && temp3){
		//The interrupt is generated because of SB event
		//This block will not be executed in slave mode because for slave SB is always zero
		//In this block lets executed the address phase
		if(pI2CHandle->TxRxState == I2C_BUSY_IN_TX){
			I2C_ExecuteAddressPhaseWrite(pI2CHandle->pI2Cx,pI2CHandle->DevAddr);
		}
		else if(pI2CHandle->TxRxState == I2C_BUSY_IN_RX){
			I2C_ExecuteAddressPhaseRead(pI2CHandle->pI2Cx,pI2CHandle->DevAddr);
		}
	}

	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_ADDR);
	//2. Handle For interrupt generated by ADDR event
	//Note : When master mode : Address is sent
	//		 When Slave mode   : Address matched with own address
	if(temp1 && temp3){
		//ADDR Flag is Set
		I2C_ClearADDRFlag(pI2CHandle);
	}


	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_BTF);
	//3. Handle For interrupt generated by BTF(Byte Transfer Finished) event
	if(temp1 && temp3){
		//BTF Flag is Set
		if(pI2CHandle->TxRxState == I2C_BUSY_IN_TX){

			//make Sure that TXE is also set.

			if(pI2CHandle->pI2Cx->SR1 & (1 << I2C_SR1_TXE)){

				//BTF = 1, TXE = 1

				if(pI2CHandle->TxLen == 0){

					//1. Generate the STOP condition
					if(pI2CHandle->Sr == I2C_DISABLE_SR)
						I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

					//2. Reset all the member elements of the handle structure.
					I2C_CloseSendData(pI2CHandle);

					//3. Notify the application about the transmission complete.
					I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_TX_CMPLT);

				}

			}

		}else if(pI2CHandle->TxRxState == I2C_BUSY_IN_RX){
			;

		}

	}

	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_STOPF);
	//4. Handle For interrupt generated by STOPF event
	// Note : Stop detection flag is applicable only slave mode . For master this flag will never be set
	//The below code block will not be executed by the master since STOPF will not set in master mode
	if(temp1 && temp3){

		//STOPF Flag is Set

		//Clear the STOPF (i.e 1) Read SR1 2)Write to CR1
		pI2CHandle->pI2Cx->CR1 |= 0x0000;

		//3. Notify the application about Stopf event is detected.

		I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_STOP);

	}


	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_TXE);
	//5. Handle For interrupt generated by TXE event
	if(temp1 && temp2 && temp3){

		//Check for Device Mode
		if(pI2CHandle->pI2Cx->SR2 & (1 << I2C_SR2_MSL)){
			//TXE Flag is Set
			//We have to do data transmission
			if(pI2CHandle->TxRxState == I2C_BUSY_IN_TX){

				I2CMasterHandleTXEInterrupt(pI2CHandle);

			}

		}
		else{
			//slave mode
			if(pI2CHandle->pI2Cx->SR2 & (1 << I2C_SR2_TRA)){
				I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_DATA_REQ);
			}
		}

	}


	temp3 = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_RXNE);
	//6. Handle For interrupt generated by RXNE event
	if(temp1 && temp2 && temp3){

		//Check for Device Mode
		if(pI2CHandle->pI2Cx->SR2 & (1 << I2C_SR2_MSL)){

			//The device is master mode

			//RXNE Flag is Set
			if(pI2CHandle->TxRxState == I2C_BUSY_IN_RX){

				I2CMasterHandleRXNEInterrupt(pI2CHandle);

			}

		}
		else{
			//slave mode
			if(!(pI2CHandle->pI2Cx->SR2 & (1 << I2C_SR2_TRA))){
				I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_DATA_RCV);
			}
		}

	}


}


/*********************************************************************
 * @fn      		  - I2C_ER_IRQHandling
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Complete the code also define these macros in the driver
						header file
						#define I2C_ERROR_BERR  3
						#define I2C_ERROR_ARLO  4
						#define I2C_ERROR_AF    5
						#define I2C_ERROR_OVR   6
						#define I2C_ERROR_TIMEOUT 7

 */

void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle)
{

	uint32_t temp1,temp2;

    //Know the status of  ITERREN control bit in the CR2
	temp2 = (pI2CHandle->pI2Cx->CR2) & ( 1 << I2C_CR2_ITERREN);


/***********************Check for Bus error************************************/
	temp1 = (pI2CHandle->pI2Cx->SR1) & ( 1<< I2C_SR1_BERR);
	if(temp1  && temp2 )
	{
		//This is Bus error

		//Implement the code to clear the buss error flag
		pI2CHandle->pI2Cx->SR1 &= ~( 1 << I2C_SR1_BERR);

		//Implement the code to notify the application about the error
	   I2C_ApplicationEventCallback(pI2CHandle,I2C_ERROR_BERR);
	}

/***********************Check for arbitration lost error************************************/
	temp1 = (pI2CHandle->pI2Cx->SR1) & ( 1 << I2C_SR1_ARLO );
	if(temp1  && temp2)
	{
		//This is arbitration lost error

		//Implement the code to clear the arbitration lost error flag
		pI2CHandle->pI2Cx->SR1 &= ~( 1 << I2C_SR1_ARLO);

		//Implement the code to notify the application about the error
		 I2C_ApplicationEventCallback(pI2CHandle,I2C_ERROR_ARLO);

	}

/***********************Check for ACK failure  error************************************/

	temp1 = (pI2CHandle->pI2Cx->SR1) & ( 1 << I2C_SR1_AF);
	if(temp1  && temp2)
	{
		//This is ACK failure error

	    //Implement the code to clear the ACK failure error flag
		pI2CHandle->pI2Cx->SR1 &= ~( 1 << I2C_SR1_AF);

		//Implement the code to notify the application about the error
		I2C_ApplicationEventCallback(pI2CHandle,I2C_ERROR_AF);
	}

/***********************Check for Overrun/underrun error************************************/
	temp1 = (pI2CHandle->pI2Cx->SR1) & ( 1 << I2C_SR1_OVR);
	if(temp1  && temp2)
	{
		//This is Overrun/underrun

	    //Implement the code to clear the Overrun/underrun error flag
		pI2CHandle->pI2Cx->SR1 &= ~( 1 << I2C_SR1_OVR);

		//Implement the code to notify the application about the error
		I2C_ApplicationEventCallback(pI2CHandle,I2C_ERROR_OVR);
	}

/***********************Check for Time out error************************************/
	temp1 = (pI2CHandle->pI2Cx->SR1) & ( 1 << I2C_SR1_TIMEOUT);
	if(temp1  && temp2)
	{
		//This is Time out error

	    //Implement the code to clear the Time out error flag
		pI2CHandle->pI2Cx->SR1 &= ~( 1 << I2C_SR1_TIMEOUT);

		//Implement the code to notify the application about the error
		I2C_ApplicationEventCallback(pI2CHandle,I2C_ERROR_TIMEOUT);
	}

}




/*
 * Other Peripheral Control APIs
 */
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi){

	if(EnOrDi == ENABLE)
	{
		pI2Cx->CR1 |= (1 << I2C_CR1_PE);
		//pI2cBaseAddress->CR1 |= I2C_CR1_PE_Bit_Mask;
	}else
	{
		pI2Cx->CR1 &= ~(1 << 0);
	}

}


uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx , uint32_t FlagName){

	if(pI2Cx->SR1 & FlagName){
		return FLAG_SET;
	}

	return FLAG_RESET;
}


/*
 * Application callback
 */
__weak void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle,uint8_t AppEv){

}





void I2C_SlaveEnableDisableCallbackEvents(I2C_Handle_t *pI2CHandle,uint8_t EnorDi)
{
	 if(EnorDi == ENABLE)
	 {
		 pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITEVTEN);
		 pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITBUFEN);
		 pI2CHandle->pI2Cx->CR2 |= ( 1 << I2C_CR2_ITERREN);
	 }else
	 {
		 pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITEVTEN);
		 pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITBUFEN);
		 pI2CHandle->pI2Cx->CR2 &= ~( 1 << I2C_CR2_ITERREN);
	 }

}









