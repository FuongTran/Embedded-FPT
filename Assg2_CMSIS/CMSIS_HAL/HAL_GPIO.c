#include "HAL_GPIO.h"

void HAL_GPIO_InitLed() {
    Driver_GPIO_InitLed();
}

void HAL_GPIO_Delay200us() {
    Driver_GPIO_Delay200us();
}

void HAL_GPIO_Delay1s() {
    Driver_GPIO_Delay1s();
}

void HAL_GPIO_DutyCycle2s(uint32_t duty) {
    Driver_GPIO_DutyCycle2s(duty);
}

void HAL_GPIO_Mode1() {
    uint32_t count_ms = 0;
    uint32_t duty;
    while (count_ms < 8) {
        for (duty = 1; duty <= 100; duty++) {
            HAL_GPIO_DutyCycle2s(duty);
        }
        for (duty = 100; duty > 0; duty--) {
            HAL_GPIO_DutyCycle2s(duty);
        }
        count_ms += 4;
    }
}

void HAL_GPIO_Mode2() {
    uint32_t count_ms = 0;
    while (count_ms < 8) {
        Driver_GPIO_Toggle();
        HAL_GPIO_Delay1s();
        count_ms++;
    }
}
