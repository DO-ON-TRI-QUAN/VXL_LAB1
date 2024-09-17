/*
 * exercise5.h
 *
 *
 *
 */

#include "main.h"

#ifndef INC_EXERCISE5_H_
#define INC_EXERCISE5_H_

// Arrays to hold the GPIO ports and pins for each pair of traffic light LEDs
GPIO_TypeDef* Traffic_LED_GPIO_Port[6] = {
    RED_1_GPIO_Port, YELLOW_1_GPIO_Port, GREEN_1_GPIO_Port,
    RED_2_GPIO_Port, YELLOW_2_GPIO_Port, GREEN_2_GPIO_Port
};

int Traffic_LED_Pin[6] = {
    RED_1_Pin, YELLOW_1_Pin, GREEN_1_Pin,
    RED_2_Pin, YELLOW_2_Pin, GREEN_2_Pin
};

int counter;
int LED_color;              // 0 = red, 1 = yellow, 2 = green
int current_traffic_light;  // Start with the first traffic light
int traffic_cycle_complete; // Flag to reset the counter

// Function to control the 4-way traffic lights
void fourWayTraffic(void)
{
    // Define LED indices for each color
    int red_LED[2] = {0, 3};    // Red LEDs    (0-based index: RED_1 and RED_2)
    int yellow_LED[2] = {1, 4}; // Yellow LEDs (0-based index: YELLOW_1 and YELLOW 2)
    int green_LED[2] = {2, 5};  // Green LEDs  (0-based index: GREEN_1 and GREEN_2)

    // Reset counter for the new traffic light
    if (traffic_cycle_complete) {
        counter = 0;
        traffic_cycle_complete = 0;
    }

    switch (LED_color)
    {
        case 0: // Red light

            // Turn off green light of the previous traffic light
        	if (current_traffic_light > 0) {
                HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[current_traffic_light - 1]], Traffic_LED_Pin[green_LED[current_traffic_light - 1]], GPIO_PIN_RESET);
        	} else {
                HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[current_traffic_light + 1]], Traffic_LED_Pin[green_LED[current_traffic_light + 1]], GPIO_PIN_RESET);
        	}

        	// Turn on red light for the current traffic light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[current_traffic_light]], Traffic_LED_Pin[red_LED[current_traffic_light]], GPIO_PIN_SET);

            // Countdown from 5 seconds
            display7SEG(5 - counter);

            if (counter >= 4) {
                counter = 0;
                LED_color = 1;  // Move to yellow
            }
            break;

        case 1: // Yellow light

            // Turn off red light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[current_traffic_light]], Traffic_LED_Pin[red_LED[current_traffic_light]], GPIO_PIN_RESET);

            // Turn on yellow LEDs for the current traffic light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[current_traffic_light]], Traffic_LED_Pin[yellow_LED[current_traffic_light]], GPIO_PIN_SET); // Yellow on

            // Countdown from 2 seconds
            display7SEG(3 - counter);

            if (counter >= 2) {
                counter = 0;
                LED_color = 2;  // Move to green

            }
            break;

        case 2: // Green light

            // Turn off yellow light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[current_traffic_light]], Traffic_LED_Pin[yellow_LED[current_traffic_light]], GPIO_PIN_RESET); // Yellow on

            // Turn on green LEDs for the current traffic light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[current_traffic_light]], Traffic_LED_Pin[green_LED[current_traffic_light]], GPIO_PIN_SET); // Green on

            // Countdown from 3 seconds
            display7SEG(4 - counter);

            if (counter >= 3) {
                counter = 0;
                LED_color = 0;  // Move back to red
                current_traffic_light = (current_traffic_light + 1) % 2; // Move to the next traffic light
                traffic_cycle_complete = 1;
            }
            break;
    }

    counter++;
}



#endif /* INC_EXERCISE5_H_ */
