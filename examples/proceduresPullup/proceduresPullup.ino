/**
 Checking if the pressure is short or long, executing the relative procedure. In addition, will be set the internal resistor.
 by Davide Palladino <https://github.com/davidepalladino>

 modified on 4th May 2020
 by Davide Palladino
*/

#include <Button.h>

void procedureShortPress();
void procedureLongPress();

/* Creating of the button assigning the pin, the flag "PULLUP", the time (in milliseconds) for the long press and the pointers to the two procedures. */
Button button1(4, PULLUP, 5000, procedureShortPress, procedureLongPress);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and executing the relative procedure. */
    button1.checkPress();
}

/* Procedure for short press. */
void procedureShortPress() {
    Serial.println("SHORT PRESS!");
}

/* Procedure for long press. */
void procedureLongPress() {
    Serial.println("LONG PRESS!");
}