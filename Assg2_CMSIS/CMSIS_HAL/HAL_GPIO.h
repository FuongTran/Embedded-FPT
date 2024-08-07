#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "Driver_GPIO.h"

void HAL_GPIO_InitLed();
void HAL_GPIO_Delay200us();
void HAL_GPIO_Delay1s();
void HAL_GPIO_DutyCycle2s(uint32_t duty);
void HAL_GPIO_Mode1();
void HAL_GPIO_Mode2();

#endif // HAL_GPIO_H
