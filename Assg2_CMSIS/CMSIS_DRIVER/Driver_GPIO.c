#include "Driver_GPIO.h"

#define DELAY_CNT_1s            (3750000)
#define DELAY_CNT_200us         ((DELAY_CNT_1s / 10000) * 2) // = 750
#define GREEN_LED_PIN           (1 << 4)

void Driver_GPIO_InitLed() {
    PCC->CLKCFG[PCC_PORTB_INDEX] |= 1 << 30;
    PORTB->PCR[4] |= 1 << 8;
    FGPIOB->PDDR |= 1 << 4;
    FGPIOB->PDOR |= 1 << 4;
}

void Driver_GPIO_Delay200us() {
    uint32_t index;
    for(index = 0; index < DELAY_CNT_200us; index++) {
        __asm("nop");
    }
}

void Driver_GPIO_Delay1s() {
    uint32_t index;
    for(index = 0; index < DELAY_CNT_1s; index++) {
        __asm("nop");
    }
}

void Driver_GPIO_DutyCycle2s(uint32_t duty) {
    uint32_t index;
    FGPIOB->PTOR |= 1 << 4;
    for(index = 1; index <= duty; index++) {
        Driver_GPIO_Delay200us();
    }
    FGPIOB->PTOR = 1 << 4;
    for(index = 1; index <= 100 - duty; index++) {
        Driver_GPIO_Delay200us();
    }
}

void Driver_GPIO_Toggle() {
    FGPIOB->PTOR |= GREEN_LED_PIN;
}
