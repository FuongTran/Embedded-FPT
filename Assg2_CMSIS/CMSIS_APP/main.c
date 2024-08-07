#include "HAL_GPIO.h"

int main() {
    HAL_GPIO_InitLed();
    while (1) {
        HAL_GPIO_Mode1();
        HAL_GPIO_Mode2();
    }
}
