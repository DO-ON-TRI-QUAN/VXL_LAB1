/*
 * exercise7.h
 *
 *
 *
 */

#ifndef INC_EXERCISE7_H_
#define INC_EXERCISE7_H_

void clearAllClock(void)
{
    // Loop through all 12 LEDs and turn them off
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(LED_GPIO_Port[i], LED_Pin[i], GPIO_PIN_RESET); // Turn off each LED
    }
}

#endif /* INC_EXERCISE7_H_ */
