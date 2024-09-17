/*
 * exercise10.h
 *
 *
 *
 */

#ifndef INC_EXERCISE10_H_
#define INC_EXERCISE10_H_

int hourPos = 0;     // Example input
int minutePos = 11;  //
int secondPos = 10;  //

void updateClock(int hrPos, int minPos, int secPos) {
	setNumberOnClock(hourPos);
	setNumberOnClock(minutePos);
	setNumberOnClock(secondPos);
}

void simpleAnalogClock(void) {
	// Reset the clock before running
    clearAllClock();

    // Turn on LEDs for hours, minutes, and seconds
    updateClock(hourPos, minutePos, secondPos);

    // Move the second hand forward
    secondPos++;
    if (secondPos > 11) {
        minutePos++;
        secondPos = 0;
    }

    // Move the minute hand forward when seconds overflow
    if (minutePos > 11) {
        hourPos++;
        minutePos = 0;
    }

    // Move the hour hand forward when minutes overflow
    if (hourPos > 11) {
        hourPos = 0;
    }
}

#endif /* INC_EXERCISE10_H_ */
