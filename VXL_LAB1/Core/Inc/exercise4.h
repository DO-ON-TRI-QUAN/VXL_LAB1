/*
 * exercise4.h
 *
 *
 *
 */

#include "main.h"

#ifndef INC_EXERCISE4_H_
#define INC_EXERCISE4_H_

void display7SEG(int num)
{
    // Array of segment patterns for numbers 0 - 9
    int segment_patterns[10] = {
    		 0b01000000, // 0: segments a, b, c, d, e, f
    		 0b01111001, // 1: segments b, c
    		 0b00100100, // 2: segments a, b, d, e, g
			 0b00110000, // 3: segments a, b, c, d, g
  	         0b00011001, // 4: segments b, c, e, f
    		 0b00010010, // 5: segments a, c, d, f, g
    	     0b00000010, // 6: segments a, c, d, e, f, g
             0b01111000, // 7: segments a, b, c
    	     0b00000000, // 8: all segments
             0b00010000  // 9: segments a, b, c, d, f, g
    };

    // Get the segment pattern for the given number
    int pattern = segment_patterns[num];

    // Set each segment based on the pattern
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (pattern & 0b00000001) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 0
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (pattern & 0b00000010) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 1
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (pattern & 0b00000100) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 2
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (pattern & 0b00001000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 3
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (pattern & 0b00010000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 4
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (pattern & 0b00100000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 5
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (pattern & 0b01000000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 6
    // Each bit of num will AND with a specific binary number to determine which segments will be on, correspond to that number
}


#endif /* INC_EXERCISE4_H_ */
