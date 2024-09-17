/*
 * exercise2.h
 *
 *
 *
 */

#include "main.h"

#ifndef INC_EXERCISE2_H_
#define INC_EXERCISE2_H_

int counter;
int LED_color; // 0 = red, 1 = yellow, 2 = green
int LED_cycle_complete; // Flag for LED cycle

void threeLEDBlinky(void)
{
   	if (LED_cycle_complete) {
	    counter = 0;
	    LED_cycle_complete = 0;
	}

	switch (LED_color) {
	        case 0: // Red light
	            HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);  // Red on
	            HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);  // Green and Yellow off
	            HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

	            if (counter >= 4) {
	                  counter = 0;
	                  LED_color = 1; // Move to yellow
	            }
	            break;

	        case 1: // Yellow light
                HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET); // Yellow on
	            HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET); // Red and Green off
	            HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);

	            if (counter >= 2) {
	                counter = 0;
	                LED_color = 2; // Move to green
	            }
	            break;

	        case 2: // Green light
	            HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET); // Green on
	            HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET); // Red and Yellow off
	            HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);

	            if (counter >= 3) {
	          	    counter = 0;
	          	    LED_color = 0; // Move back to red
	                LED_cycle_complete = 1;
	            }
	            break;
	 }

	 counter++;
}


#endif /* INC_EXERCISE2_H_ */
