/*
 * exercise6.h
 *
 *
 *
 */

#ifndef INC_EXERCISE6_H_
#define INC_EXERCISE6_H_

// Arrays to hold the GPIO ports and pins for each LED
GPIO_TypeDef* LED_GPIO_Port[12] = {
    LED_1_GPIO_Port, LED_2_GPIO_Port, LED_3_GPIO_Port, LED_4_GPIO_Port,
    LED_5_GPIO_Port, LED_6_GPIO_Port, LED_7_GPIO_Port, LED_8_GPIO_Port,
    LED_9_GPIO_Port, LED_10_GPIO_Port, LED_11_GPIO_Port, LED_12_GPIO_Port
};

int LED_Pin[12] = {
    LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin,
    LED_5_Pin, LED_6_Pin, LED_7_Pin, LED_8_Pin,
    LED_9_Pin, LED_10_Pin, LED_11_Pin, LED_12_Pin
};

int current_LED = 0;
int previous_LED = 11;

void clockSequence(void)
{
	    // Turn off the previous LED
	    HAL_GPIO_WritePin(LED_GPIO_Port[previous_LED], LED_Pin[previous_LED], GPIO_PIN_RESET);

	    // Turn on the current LED
	    HAL_GPIO_WritePin(LED_GPIO_Port[current_LED], LED_Pin[current_LED], GPIO_PIN_SET);

	    // Update previous LED before moving to the next one
	    previous_LED = current_LED;

	    // Move to the next LED in the sequence
	    current_LED = (current_LED + 1) % 12;

}

#endif /* INC_EXERCISE6_H_ */
