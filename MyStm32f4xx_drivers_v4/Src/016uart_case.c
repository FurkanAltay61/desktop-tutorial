/*
 * uart_tx.c
 *
 *  Created on: Jan 22, 2019
 *      Author: admin
 */

#include<stdio.h>
#include<string.h>

#include "stm32f407xx_usart_driver.h"
#include "stm32f407xx_gpio_driver.h"



//we have 3 different messages that we transmit to arduino
//you can by all means add more messages
char msg[] = "Today is Monday !";

//reply from arduino will be stored here
char rx_buf[1024] ;

//USART_Handle_t usart2_handle;
DMA_Handle_t   pDMAHandle;



void USART2_Init(void)
{
	static USART_Handle_t usart2_handle;

	usart2_handle.pUSARTx = USART2;
	usart2_handle.USART_Config.Baud = USART_STD_BAUD_115200;
	usart2_handle.USART_Config.HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	usart2_handle.USART_Config.Mode = USART_MODE_TXRX;
	usart2_handle.USART_Config.NoOfStopBits = USART_STOPBITS_1;
	usart2_handle.USART_Config.WordLength = USART_WORDLEN_8BITS;
	usart2_handle.USART_Config.ParityControl = USART_PARITY_DISABLE;
	USART_Init(&usart2_handle);


	usart2_handle.phdma.pDMAStream = DMA1_Stream6;
	usart2_handle.phdma.pDMAConfig.Channel = DMA_CHANNEL_4;
	usart2_handle.phdma.pDMAConfig.Direction = DMA_MEMTOPER;
	usart2_handle.phdma.pDMAConfig.PeriphInc = DMA_PINC_DIS;
	usart2_handle.phdma.pDMAConfig.MemInc = DMA_MINC_EN;
	usart2_handle.phdma.pDMAConfig.Mode = DMA_NORMAL;
	usart2_handle.phdma.pDMAConfig.Priority = DMA_PRIO_LOW;
	usart2_handle.phdma.pDMAConfig.FIFOMode = DMA_FIFO_DIS;

	DMA_Init(&usart2_handle.phdma);


}

void 	USART2_GPIOInit(void)
{
	GPIO_Handle_t usart_gpios;

	usart_gpios.pGPIOx = GPIOA;
	usart_gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	usart_gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	usart_gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	usart_gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	usart_gpios.GPIO_PinConfig.GPIO_PinAltFunMode =7;

	usart_gpios.GPIO_PinConfig.GPIO_PinNumber  = GPIO_PIN_NO_2;
	GPIO_Init(&usart_gpios);

	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIO_Init(&usart_gpios);


}

void GPIO_ButtonInit(void)
{
	GPIO_Handle_t GPIOBtn,GpioLed;

	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GPIOBtn);

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

}

//
//void DMA1_Init(void){
//
//	//1. enable the peripheral clock for the dma1
//	DMA1_PCLK_EN();
//
//	//2. identify the stream which is suitable for your peripheral
//		 //channel 4 , stream 6
//
//	//3. Identify the channel number on which uart2 peripheral sends dma request
//		 //channel 4
//
//
//	DMA1_Stream6->CR &= ~(0x07 << DMA_SCR_CHSEL);
//
//	DMA1_Stream6->CR |=  (0x04 << DMA_SCR_CHSEL);
//
//	//4. Program the source address  (memory)
//	DMA1_Stream6->M0AR = (uint32_t)msg;
//
//	//5 . Program the destination address (peripheral )
//	DMA1_Stream6->PAR = (uint32_t) &usart2_handle.pUSARTx->DR;
//
//	//6. Program number of data items to send
//	DMA1_Stream6->NDTR = (uint32_t)sizeof(msg);
//
//	//7. The direction of data transfer . m2p, p2m , m2m
//	DMA1_Stream6->CR |= (0x1 << DMA_SCR_DIR);
//
//	//8. Program the source and destination data width .
//	DMA1_Stream6->CR &= ~(0x3 << DMA_SCR_PSIZE);
//	DMA1_Stream6->CR &= ~(0x3 << DMA_SCR_MSIZE);
//
//	//8.a ) Enable Memory Auto Increment
//	DMA1_Stream6->CR |= (1 << DMA_SCR_MINC);
//
//	//9. direct mode or fifo mode
//	DMA1_Stream6->FCR |= (0x01 << DMA_SFCR_DMDIS);
//
//	//10. Select the fifo threshold
//	DMA1_Stream6->FCR &= ~(0x03 << DMA_SFCR_FTH);
//	DMA1_Stream6->FCR |=  (0x03 << DMA_SFCR_FTH);
//
//	DMA1_Stream6->CR |= (1 << DMA_SCR_EN);
//
//}



void dma1_init(DMA_Handle_t *dmah){

	dmah->pDMAStream = DMA1_Stream6;
	dmah->pDMAConfig.Channel = DMA_CHANNEL_4;
	dmah->pDMAConfig.Direction = DMA_MEMTOPER;
	dmah->pDMAConfig.PeriphInc = DMA_PINC_DIS;
	dmah->pDMAConfig.MemInc = DMA_MINC_EN;
	dmah->pDMAConfig.Mode = DMA_NORMAL;
	dmah->pDMAConfig.Priority = DMA_PRIO_LOW;
	dmah->pDMAConfig.FIFOMode = DMA_FIFO_DIS;

	DMA_Init(dmah);

//	usart2_handle.phdma = dmah;
}



void uart_transmit_dma(USART_Handle_t *phuart,uint8_t *pData,uint8_t Size){

	phuart->phdma.pDMAStream->M0AR = (uint32_t)pData;
	phuart->phdma.pDMAStream->PAR = (uint32_t)&phuart->pUSARTx->DR;
	phuart->phdma.pDMAStream->NDTR = Size;
	phuart->phdma.pDMAStream->CR |= (1 << DMA_SCR_EN);
	phuart->pUSARTx->CR3 |= (1 << USART_CR3_DMAT);

}




void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

int main(void)
{
	static USART_Handle_t usart2_handle;

	USART2_GPIOInit();
    USART2_Init();
    USART_PeripheralControl(USART2,ENABLE);
//    DMA1_Init();
//    dma1_init(&pDMAHandle);

    //do forever
    while(1)
    {
		//wait till button is pressed
		while( ! GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) );

		//to avoid button de-bouncing related issues 200ms of delay
		delay();

		uart_transmit_dma(&usart2_handle, (uint8_t *)msg, sizeof(msg));

//		usart2_handle.pUSARTx->CR3 |= (1 << USART_CR3_DMAT);


    }


	return 0;
}









