/*******************************************************************************
* Includes
*******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
* Function
*******************************************************************************/
void initLed() {
    /* Configure clock for PORTB */
    PCC->CLKCFG[PCC_PORTB_INDEX] |= 1 << 30;

    /* Configure MUX for PCR_4 */
    PORTB->PCR[4] |= 1 << 8;

    /* Set bit for PDOR */
    FGPIOB->PDDR |= 1 << 4;
    FGPIOB->PDOR |= 1 << 4;
    /* Or
     * FGPIOB->PSOR |= 1 << 4;
     */
}

/* 100hz -> period = 20ms -> 1% = 200us */
void delay_200us() {
    uint32_t index;

    for(index = 0; index < DELAY_CNT_200us; index++) {
        __asm("nop");
    }
}

void delay_1s() {
    uint32_t index;

    for(index = 0; index < DELAY_CNT_1s; index++) {
        __asm("nop");
    }
}

void duty_cycle_2s(uint32_t duty) {
    uint32_t index;

    FGPIOB->PTOR |= 1 << 4;
    for(index = 1; index <= duty; index++) {
        delay_200us();
    }

    FGPIOB->PTOR |= 1 << 4;
    for(index = 1; index <= 100 - duty; index++) {
        delay_200us();
    }
}
/*******************************************************************************
* EOF
*******************************************************************************/
