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
int LED_done1;                   // Flag to reset the counter
int LED_done2;

void fourWayTraffic(void)
{
    // Define LED indices for each color
    int red_LED[2] = {0, 3};    // Red LEDs    (RED_1 and RED_2)
    int yellow_LED[2] = {1, 4}; // Yellow LEDs (YELLOW_1 and YELLOW 2)
    int green_LED[2] = {2, 5};  // Green LEDs  (GREEN_1 and GREEN_2)

    // Reset counter everytime a pair of LEDs turn off
    if (LED_done1) {
        counter1 = 0;
        LED_done1 = 0;
    }

    if (LED_done2) {
        counter2 = 0;
        LED_done2 = 0;
    }

    // Explain:
    // traffic_light1 is first pair of traffic lights, traffic_light2 is the second one
    // red/yellow/green_LED[traffic_light1/2]: choose the LEDs of first (index 0) or second (index 1) pair of traffic lights
    // Traffic_LED_GPIO_Port[red/yellow/green_LED[traffic_light1/2]]: get the GPIO_Port/Pin of corresponding LEDs

    switch (LED_color1) // traffic_light1
    {
        case 0: // Red light

            // Turn off yellow light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light1]], Traffic_LED_Pin[yellow_LED[traffic_light1]], GPIO_PIN_RESET);

        	// Turn on red light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light1]], Traffic_LED_Pin[red_LED[traffic_light1]], GPIO_PIN_SET);

            // Countdown from 5 seconds
            display7SEG(5 - counter1);

            if (counter1 >= 4) {
                LED_color1 = 2;  // Move to green
                LED_done1 = 1;

            }
            break;

        case 1: // Yellow light

            // Turn off green light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[green_LED[traffic_light1]], Traffic_LED_Pin[green_LED[traffic_light1]], GPIO_PIN_RESET);

            // Turn on yellow light
            HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light1]], Traffic_LED_Pin[yellow_LED[traffic_light1]], GPIO_PIN_SET); // Yellow on

            // Countdown from 2 seconds
            display7SEG(2 - counter1);

            if (counter1 >= 1) {
                LED_color1 = 0;  // Move to red
                LED_done1 = 1;

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
                LED_color1 = 1;  // Move to yellow
                LED_done1 = 1;
           }
            break;
    }

    counter1++;


    switch (LED_color2) // traffic_light2
    {
        case 0: // Red light

        	// Turn off yellow light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[yellow_LED[traffic_light2]], Traffic_LED_Pin[yellow_LED[traffic_light2]], GPIO_PIN_RESET);

        	// Turn on red light
        	HAL_GPIO_WritePin(Traffic_LED_GPIO_Port[red_LED[traffic_light2]], Traffic_LED_Pin[red_LED[traffic_light2]], GPIO_PIN_SET);

            // Countdown from 5 seconds
            display7SEG1(5 - counter2);

            if (counter2 >= 4) {
                LED_color2 = 2;  // Move to green
                LED_done2 = 1;
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
                LED_color2 = 0;  // Move to red
                LED_done2 = 1;

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
                LED_color2 = 1;  // Move to yellow
                LED_done2 = 1;
            }
            break;
    }

    counter2++;
}

#endif /* INC_EXERCISE5_H_ */
