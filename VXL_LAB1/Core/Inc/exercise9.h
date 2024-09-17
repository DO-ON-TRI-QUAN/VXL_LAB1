/*
 * exercise9.h
 *
 *
 *
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_

void clearNumberOnClock(int num)
{
	// Make sure that the input number is within the valid range (0 to 11)
   	num = num % 12;

    // Because of the starting index of the LEDs on clock is 0, for the LEDs to display exactly like the input...
	//... or display like a real life clock, num must be minus by 1
	if (num == 0) {
	    HAL_GPIO_WritePin(LED_GPIO_Port[11], LED_Pin[11], GPIO_PIN_RESET);
	} else {
        HAL_GPIO_WritePin(LED_GPIO_Port[num - 1], LED_Pin[num - 1], GPIO_PIN_RESET);
    }
}

#endif /* INC_EXERCISE9_H_ */
