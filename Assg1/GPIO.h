/*******************************************************************************
* Definitions
*******************************************************************************/
#ifndef GPIO_H
#define GPIO_H

#include "MKE16Z4.h"

#define DELAY_CNT_1s            (3750000)
#define DELAY_CNT_200us         ((DELAY_CNT_1s / 10000) * 2) // = 750
#define GREEN_LED_PIN           (1 << 4)

/*******************************************************************************
* Prototypes
*******************************************************************************/

/**
 * @brief Initialize the LED pin
 *
 * This function configures the necessary registers to initialize
 * the LED pin as an output and sets its initial state.
 */
void initLed();

/**
 * @brief Delay for approximately 200 microseconds
 *
 * This function creates a delay of approximately 200 microseconds
 * by running a loop with NOP instructions.
 */
void delay_200us();

/**
 * @brief Delay for approximately 1 second
 *
 * This function creates a delay of approximately 1 second
 * by running a loop with NOP instructions.
 */
void delay_1s();

/**
 * @brief Generate a PWM-like signal for 2 seconds with a specific duty cycle
 *
 * This function toggles the LED pin on and off to simulate a PWM signal
 * for 2 seconds, with the LED on for a duration proportional to the duty cycle.
 *
 * @param duty The duty cycle percentage (0-100)
 */
void duty_cycle_2s(uint32_t duty);
 */
#endif // GPIO_H
/*******************************************************************************
* EOF
*******************************************************************************/
