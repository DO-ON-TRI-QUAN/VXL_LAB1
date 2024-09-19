/*
 * exercise5.h
 *
 *
 *
 */

#include "main.h"

#ifndef INC_EXERCISE5_H_
#define INC_EXERCISE5_H_

// Arrays to hold the GPIO ports and pins for each pair of traffic lights LEDs
GPIO_TypeDef* Traffic_LED_GPIO_Port[6] = {
    RED_1_GPIO_Port, YELLOW_1_GPIO_Port, GREEN_1_GPIO_Port,
    RED_2_GPIO_Port, YELLOW_2_GPIO_Port, GREEN_2_GPIO_Port
};

int Traffic_LED_Pin[6] = {
    RED_1_Pin, YELLOW_1_Pin, GREEN_1_Pin,
    RED_2_Pin, YELLOW_2_Pin, GREEN_2_Pin
};

int counter1;
int counter2;
int LED_color1 = 0;              // 0 = red, 1 = yellow, 2 = green
int LED_color2 = 2;
int traffic_light1 = 0;
int traffic_light2 = 1;
int traffic_cycle1_complete; // Flag to reset the counter
int traffic_cycle2_complete;

void fourWayTraffic(void)
{
    // Define LED indices for each color
    int red_LED[2] = {0, 3};    // Red LEDs    (0-based index: RED_1 and RED_2)
    int yellow_LED[2] = {1, 4}; // Yellow LEDs (0-based index: YELLOW_1 and YELLOW 2)
    int green_LED[2] = {2, 5};  // Green LEDs  (0-based index: GREEN_1 and GREEN_2)

    // Reset counter for the next pair of traffic lights
    if (traffic_cycle1_complete) {
        counter1 = 0;
        traffic_cycle1_complete = 0;
    }

    if (traffic_cycle2_complete) {
        counter2 = 0;
        traffic_cycle2_complete = 0;
    }


    switch (LED_color1)
    {
        case 0: // Red light

        	// Explain:
        	// traffic_light1 is first pair of traffic lights, traffic_light2 is the second one
        	// red/yellow/green_LED[traffic_light1/2]: choose the LEDs of first (index 0) or second (index 1) pair of traffic lights
        	// Traffic_LED_GPIO_Port[red/yellow/green_LED[traffic_light1/2]]: get the GPIO_Port/Pin of corresponding LEDs

            // Turn off yellow light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light1]], Traffic_LED_Pin[yellow_LED[traffic_light1]], GPIO_PIN_RESET);

        	// Turn on red light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light1]], Traffic_LED_Pin[red_LED[traffic_light1]], GPIO_PIN_SET);

            // Countdown from 5 seconds
            display7SEG(5 - counter1);

            if (counter1 >= 4) {
                counter1 = 0;
                LED_color1 = 2;  // Move to green
            }
            break;

        case 1: // Yellow light

            // Turn off green light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[traffic_light1]], Traffic_LED_Pin[green_LED[traffic_light1]], GPIO_PIN_RESET);

            // Turn on yellow light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light1]], Traffic_LED_Pin[yellow_LED[traffic_light1]], GPIO_PIN_SET); // Yellow on

            // Countdown from 2 seconds
            display7SEG(3 - counter1);

            if (counter1 >= 2) {
                counter1 = 0;
                LED_color1 = 0;  // Move to green

            }
            break;

        case 2: // Green light

            // Turn off red light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light1]], Traffic_LED_Pin[red_LED[traffic_light1]], GPIO_PIN_RESET); // Yellow on

            // Turn on green light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[traffic_light1]], Traffic_LED_Pin[green_LED[traffic_light1]], GPIO_PIN_SET); // Green on

            // Countdown from 3 seconds
            display7SEG(3 - counter1);

            if (counter1 >= 2) {
                counter1 = 0;
                LED_color1 = 1;  // Move back to yellow
                traffic_cycle1_complete = 1;
            }
            break;
    }

    counter1++;


    switch (LED_color2)
    {
        case 0: // Red light

        	// Explain:
        	// current_traffic_light = 0 is first pair of traffic lights, = 1 is the second one
        	// red/yellow/green_LED[current_traffic_light]: choose the LEDs of first (index 0) or second (index 1) pair of traffic lights
        	// Traffic_LED_GPIO_Port[red/yellow/green_LED[current_traffic_light - 1]]: get the GPIO_Port/Pin of corresponding LEDs

        	// Turn off yellow light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light2]], Traffic_LED_Pin[yellow_LED[traffic_light2]], GPIO_PIN_RESET);

        	// Turn on red light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light2]], Traffic_LED_Pin[red_LED[traffic_light2]], GPIO_PIN_SET);

            // Countdown from 5 seconds
            display7SEG1(6 - counter2);

            if (counter2 >= 5) {
                counter2 = 0;
                LED_color2 = 2;  // Move to yellow
            }
            break;

        case 1: // Yellow light

            // Turn off green light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[traffic_light2]], Traffic_LED_Pin[green_LED[traffic_light2]], GPIO_PIN_RESET);

            // Turn on yellow light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light2]], Traffic_LED_Pin[yellow_LED[traffic_light2]], GPIO_PIN_SET); // Yellow on

            // Countdown from 2 seconds
            display7SEG1(2 - counter2);

            if (counter2 >= 1) {
                counter2 = 0;
                LED_color2 = 0;  // Move to green

            }
            break;

        case 2: // Green light

            // Turn off red light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light2]], Traffic_LED_Pin[red_LED[traffic_light2]], GPIO_PIN_RESET); // Yellow on

            // Turn on green light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[traffic_light2]], Traffic_LED_Pin[green_LED[traffic_light2]], GPIO_PIN_SET); // Green on

            // Countdown from 3 seconds
            display7SEG1(3 - counter2);

            if (counter2 >= 2) {
                counter2 = 0;
                LED_color2 = 1;  // Move back to red
                traffic_cycle2_complete = 1;
            }
            break;
    }

    counter2++;
}

#endif /* INC_EXERCISE5_H_ */
