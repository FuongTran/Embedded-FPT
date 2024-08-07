#ifndef DRIVER_GPIO_H
#define DRIVER_GPIO_H

#include "MKE16Z4.h"

void Driver_GPIO_InitLed();
void Driver_GPIO_Delay200us();
void Driver_GPIO_Delay1s();
void Driver_GPIO_DutyCycle2s(uint32_t duty);
void Driver_GPIO_Toggle();

#endif // DRIVER_GPIO_H
