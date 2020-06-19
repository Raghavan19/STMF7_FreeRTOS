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
#include "stm32f7xx.h"
#include "stm32f7xx_nucleo_144.h"

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

void vTask1_handler(void *param);
void vTask2_handler(void *param);


int main(void)
{

	//printf("Hello world \n");
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


	while(1)
	{
		//printf("Task 1 \n");
	}
}

void vTask2_handler(void *param)
{

	while(1)
	{
		//printf("Task 2 \n");
	}
}
