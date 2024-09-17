/*
 * exercise1.h
 *
 *
 *
 */
#include "main.h"

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

int counter;

void twoLEDBlinky(void)
{
    if (counter == 0) {
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
    }

    if (counter >= 2) {
	    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	    counter = 0;
    }
    counter++;
}


#endif /* INC_EXERCISE1_H_ */
