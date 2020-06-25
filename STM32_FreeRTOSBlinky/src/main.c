/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stdio.h"
#include "stdint.h"
#include <string.h>
#include "stm32f7xx.h"
#include "stm32f7xx_nucleo_144.h"

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;
UART_HandleTypeDef husart3 = {0};

void vTask1_handler(void *param);
void vTask2_handler(void *param);
static void prvUartSetup(void);
static void prvSetupHardware(void);

void Error_Handler(void)
{
}

void printmsg(char *msg);

char charmsg[250] = {0};

int main(void)
{
	//Required for timestamps on Segger system view tools
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->LAR = 0xC5ACCE55;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

	prvSetupHardware();

	sprintf(charmsg,"Hello world \r\n");
	printmsg(charmsg);

	//Start Segger system view
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();

	//Create task 1
	xTaskCreate(vTask1_handler, "Task_1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
	//Create task 2
	xTaskCreate(vTask2_handler, "Task_2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

	//start scheduler to run tasks
	vTaskStartScheduler();

	for(;;);
}


void vTask1_handler(void *param)
{
	char charmsg1[250] = {0};
	sprintf(charmsg1,"Task1 \r\n");
	while(1)
	{

			printmsg(charmsg1);
			vTaskDelay(10);
	}
}

void vTask2_handler(void *param)
{
	char charmsg2[250] = {0};
	sprintf(charmsg2,"Task2 \r\n");

	while(1)
	{
		printmsg(charmsg2);
		vTaskDelay(10);
	}
}

static void prvUartSetup(void)
{
	GPIO_InitTypeDef usart3_pin = {0};

	//1. Enable UART3 peripheral clock
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
	PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	__HAL_RCC_USART3_CLK_ENABLE();

	//2. Enable GPIO clock
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOE_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();


	//PD8 UART TX PD9 UART RX
	//3. Alternate function configuration
	usart3_pin.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	usart3_pin.Mode = GPIO_MODE_AF_PP;
	usart3_pin.Pull = GPIO_NOPULL;
	usart3_pin.Speed = GPIO_SPEED_FREQ_LOW;
	usart3_pin.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD,&usart3_pin);

    //4. Initialise UART
	husart3.Instance = USART3;
	husart3.Init.BaudRate = 9600;
	husart3.Init.WordLength = UART_WORDLENGTH_8B;
	husart3.Init.StopBits = UART_STOPBITS_1;
	husart3.Init.Parity = UART_PARITY_NONE;
	husart3.Init.Mode = UART_MODE_TX_RX;
	husart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	husart3.Init.OverSampling = UART_OVERSAMPLING_16;
	husart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	husart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	if (HAL_UART_Init(&husart3) != HAL_OK)
	{
		Error_Handler();
	}

}

static void prvSetupHardware(void)
{
	prvUartSetup();
}

void printmsg(char *msg)
{
	for(uint32_t i = 0; i < strlen(msg); i++)
	{
		char ch = msg[i];
		HAL_UART_Transmit(&husart3, (uint8_t *)&ch, 1, 0xFFFF);
	}
}
