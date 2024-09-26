/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "switch_intr.h"
#include "led.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
Blue LED will blink when switch is pressed -- Optimization Level 0

Blue LED will NOT blink when switch is pressed -- Optimization Level 3
*/

int main(void) {
	SystemInit();
	SwitchInit();
	char str[32];
	UartInit(9600);
	LedInit(LED_BLUE_PIN);

	uint32_t switchcount=1;
	while(1) {

		while(SwitchExtiFlag == 0)
			;
		DelayMs(200);

		sprintf(str,"count=%d\r\n",switchcount);
		UartPuts(str);
		switchcount++;

		SwitchExtiFlag = 0;
	}
	return 0;
}








