/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lwip.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
//#include "retarget.h"
#include "qpc.h"
#include "Shape.h"
#include "stdlib.h"  /*For malloc function*/
#include "time.h"
#include <inttypes.h>
#include "lwip/udp.h"
#include "string.h"
#include "sntp.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef  sTime;
RTC_DateTypeDef  sDate;


#define NTP_MSJ_BOYUT 48

static struct udp_pcb *NtpPcb;
static struct pbuf *NtpBuffer=NULL;
err_t NtpErr;
char Ntp_Message[NTP_MSJ_BOYUT];

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define UartHandle &huart3
#define RtcHandle  &hrtc
static uint16_t YearStart=2000;

uint16_t MsecArr[100]={0};
uint16_t MsecArrCntr=0;


//#define LOCALIP_1 192
//#define LOCALIP_2 168
//#define LOCALIP_3 0
//#define LOCALIP_4 5
//
//#define REMOTEIP_1 192
//#define REMOTEIP_2 168
//#define REMOTEIP_3 0
//#define REMOTEIP_4 1


#define LOCALIP_1 10
#define LOCALIP_2 42
#define LOCALIP_3 0
#define LOCALIP_4 10

#define REMOTEIP_1 10
#define REMOTEIP_2 42
#define REMOTEIP_3 0
#define REMOTEIP_4 1

#define NTP_PORT    123
#define NTP_LOCALPORT 5666


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

RTC_HandleTypeDef hrtc;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
static time_t  timestamp=0;
static struct tm 	currTime;
static uint16_t milliseconds=0;
long long int longtimestamp=0;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */


void udpNtpcallback(void *arg,struct udp_pcb *NtpPcb,struct pbuf *NtpBuffer,const ip_addr_t *addr,u16_t port);




void LocalNtp_Request(void)
{

//    NtpPcb = udp_new();

//    if (!NtpPcb)
//    {
//        LOCAL_NTP_DEBUG("[Error] UDP_NEW Failed! \r\n");
//        return;
//    }

    memset(Ntp_Message, 0, NTP_MSJ_BOYUT);

    Ntp_Message[0] = 0x1B;
//    IP4_ADDR(&DestIPaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
//    IP4_ADDR(&NtpPcb->remote_ip,REMOTEIP_1,REMOTEIP_2,REMOTEIP_3,REMOTEIP_4);

    NtpErr = udp_connect(NtpPcb, &NtpPcb->remote_ip, NTP_PORT);

//    udp_recv(NtpPcb, udpNtpcallback, NULL);

    if (NtpErr == ERR_OK)
    {
    	NtpBuffer = pbuf_alloc(PBUF_TRANSPORT, NTP_MSJ_BOYUT,  PBUF_REF);
        memcpy(NtpBuffer->payload, Ntp_Message, NTP_MSJ_BOYUT);

        NtpErr = udp_send(NtpPcb, NtpBuffer);

        if (NtpErr != ERR_OK)
        {
            udp_remove(NtpPcb);
        }

        pbuf_free(NtpBuffer);

    }
}



int8_t UdpNTP_Konf(void)
{
	NtpPcb = udp_new();
	IP4_ADDR(&NtpPcb->remote_ip,REMOTEIP_1,REMOTEIP_2,REMOTEIP_3,REMOTEIP_4);
	NtpPcb->remote_port = NTP_PORT;
	IP4_ADDR(&NtpPcb->local_ip,LOCALIP_1,LOCALIP_2,LOCALIP_3,LOCALIP_4);
	NtpPcb->local_port = NTP_LOCALPORT;
	NtpErr = udp_bind(NtpPcb, &NtpPcb->local_ip,NtpPcb->local_port);
	if(NtpErr == 0){
		udp_recv(NtpPcb, &udpNtpcallback, NULL);
	}
	return NtpErr;
}



void NtpMesajParcala(void)
{
    const unsigned long seventyYears = 2208988800UL;
    static unsigned long secsSince1900 = 0;
    struct tm *stmU;
    time_t epoch;

    secsSince1900 = (Ntp_Message[ 40 ] << 24) | (Ntp_Message[ 41 ] << 16) | (Ntp_Message[ 42 ] <<  8) | (Ntp_Message[ 43 ]);
    epoch = secsSince1900 - seventyYears;
	stmU = localtime(&epoch);
	sDate.Year = stmU->tm_year - 100;
	sDate.Month = stmU->tm_mon + 1;
	sDate.Date = stmU->tm_mday;
//	sTime.Hours = stmU->tm_hour + 3;
	sTime.Hours = stmU->tm_hour;
	sTime.Minutes = stmU->tm_min;
	sTime.Seconds = stmU->tm_sec;

	/** Initialize RTC and set the Time and Date*/
	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
		Error_Handler();
	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
		Error_Handler();
}

void udpNtpcallback(void *arg,struct udp_pcb *NtpPcb,struct pbuf *NtpBuffer,const ip_addr_t *addr,u16_t port)
{
	memset(Ntp_Message,0x00,NTP_MSJ_BOYUT);
	memcpy(Ntp_Message, NtpBuffer -> payload, NtpBuffer -> tot_len);
	pbuf_free(NtpBuffer);

	NtpMesajParcala();

}


void UdpNtpVeriPaketiGonder(char arr[],uint8_t boyut,uint16_t port)
{
	  NtpBuffer = pbuf_alloc(PBUF_TRANSPORT,boyut, PBUF_POOL);
	  /* allocate pbuf from pool*/
	 if(NtpBuffer != NULL){
		/* copy data to pbuf */
		pbuf_take(NtpBuffer,arr,boyut);
		/* send udp data */
//		udp_send(NtpPcb,NtpBuffer);
		udp_sendto(NtpPcb, NtpBuffer, &NtpPcb->remote_ip, port);
	 }
		/* free pbuf */
		pbuf_free(NtpBuffer);
//		NtpBuffer = NULL;
}


void NtpIstekGonder(void)
{
    Ntp_Message[0] = 0x1B;
    UdpNtpVeriPaketiGonder(Ntp_Message,NTP_MSJ_BOYUT,NTP_PORT);
//	pbuf_free(NtpBuffer);
}


void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
{
	static RTC_TimeTypeDef sTime;
	static RTC_DateTypeDef sDate;
	static char message[50];
	static size_t size;

	// Get current time and date
	HAL_RTC_GetTime(hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(hrtc, &sDate, RTC_FORMAT_BIN);
	currTime.tm_year = sDate.Year + 100;
	currTime.tm_mday = sDate.Date;
	currTime.tm_mon =  sDate.Month - 1;
	currTime.tm_hour = sTime.Hours;
	currTime.tm_min = sTime.Minutes;
	currTime.tm_sec = sTime.Seconds;
	uint16_t mseconds = (sTime.SubSeconds * 1000) / (sTime.SecondFraction + 1);
	timestamp = (mktime(&currTime) * 1000 + mseconds);
	longtimestamp = timestamp;
	__NOP();

//	if(MsecArrCntr <100){
//		MsecArr[MsecArrCntr] = mseconds;
//		MsecArrCntr++;
//	}

	// Send time and date over uart
	size = sprintf(message, "Date: %2.2u-%2.2u-%4.4u\n\r", sDate.Date, sDate.Month, sDate.Year + YearStart);
	HAL_UART_Transmit(UartHandle, (uint8_t*)message, size, 50);
	size = sprintf(message, "Time: %2.2u:%2.2u:%2.2u:%3.3u\n\r", sTime.Hours, sTime.Minutes, sTime.Seconds, mseconds);
	HAL_UART_Transmit(UartHandle, (uint8_t*)message, size, 50);
	size = sprintf(message, "%lld\n\r",longtimestamp);
	HAL_UART_Transmit(UartHandle, (uint8_t*)message, size, 50);

	UdpNtpVeriPaketiGonder(message, size, (uint16_t)5667);

}


void Q_onAssert(char const *module, int loc);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
Shape s1; /*static allocation*/
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_RTC_Init();
  MX_LWIP_Init();
  /* USER CODE BEGIN 2 */
//  RetargetInit(&huart3);

  // Disable Wakeup Timer and configure it
  HAL_RTCEx_DeactivateWakeUpTimer(RtcHandle);


//  // Data
//  RTC_TimeTypeDef sTime;
//  RTC_DateTypeDef sDate;
//  char message[50];
//  uint8_t size;
//
//  // Uart HELLO
//  size = sprintf(message, "\n\rHello\n\r");
//  HAL_UART_Transmit(UartHandle, (uint8_t*)message, size, 50);
//
//  // Set date and time
//  sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
//  sDate.Date = 25;
//  sDate.Month = 5;
//  sDate.Year = 22; // from 0-99 (1972 == 72, start year = 1900)
//  HAL_RTC_SetDate(RtcHandle, &sDate, RTC_FORMAT_BIN);
//  sTime.Hours = 8;
//  sTime.Minutes = 57;
//  HAL_RTC_SetTime(RtcHandle, &sTime, RTC_FORMAT_BIN);

  // Start Wakeup timer with configuration (32768Hz / 16 = 2048) -> Counter = 2048
  HAL_RTCEx_SetWakeUpTimer_IT(RtcHandle, 2048-1, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

//  // Start Wakeup timer with configuration (32768Hz / 2 = 16384) -> Counter = 16384
//  HAL_RTCEx_SetWakeUpTimer_IT(RtcHandle, 9-1, RTC_WAKEUPCLOCK_RTCCLK_DIV2);


  UdpNTP_Konf();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  MX_LWIP_Process();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 31;
  hrtc.Init.SynchPrediv = 1023;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable the WakeUp
  */
  if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTON2_Pin BUTON1_Pin */
  GPIO_InitStruct.Pin = BUTON2_Pin|BUTON1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

  __NOP();

  NtpIstekGonder();
//  LocalNtp_Request();

}


void Q_onAssert(char const *module, int loc) {
    /* TBD: damage control */
    (void)module; /* avoid the "unused parameter" compiler warning */
    (void)loc;    /* avoid the "unused parameter" compiler warning */
    NVIC_SystemReset();
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
