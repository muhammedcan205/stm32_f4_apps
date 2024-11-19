/*
 * LED_DRİVER.c
 *
 *  Created on: Dec 4, 2023
 *      Author: muham
 */
#include "led_driver.h"

#include "stm32f4xx_hal.h"



void user_led_init()
{
	//LED2 ==>  GPIOA - 5. pin

	// Enable Clock
	__HAL_RCC_GPIOD_CLK_ENABLE();

	// Select Mode
	// BIT 10: 1
	// BIT 11: 0
	GPIOD->MODER  &= ~(1 << 31); // Bit 11 : 0
  GPIOD->MODER  |=  (1 << 30); // Bit 10 : 1
  

	// Select Output Type
	// Bit 5 : 0
  GPIOD->OTYPER  &= ~(1<<15); // 0 - Push - pull output

	// Select Speed
	// Bit 10: 1
	// Bit 11: 0
  GPIOD->OSPEEDR &= ~(1 << 31); // Bit 11: 0
  GPIOD->OSPEEDR |=  (1 << 30); // Bit 10: 1


	// Pull-up pull-down
  // Bit 10 : 0
  // Bit 11 :	0
  GPIOD->PUPDR   &= ~(1 << 31); // No pull-up, no pull-down
	GPIOD->PUPDR   &= ~(1 << 30); // No pull-up, no pull-down
}


void user_led_toggle()
{
	GPIOD->ODR ^= (1<<15);
}


void user_led_set()
{
	// Bit 5 : 1
	GPIOD->BSRR = (1<<15);
}

void user_led_reset()
{
	// Bit 5 : 1
	GPIOD->BSRR = (0<<31);
}


