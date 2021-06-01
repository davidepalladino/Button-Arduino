/**
    Checking if the pressure is short or not, with external resistor.

    @author Davide Palladino
    @contact me@davidepalladino.com
    @website www.davidepalladino.com
    @date 1st June, 2021
*/

#include <Button.h>

/**
 * Creating of the button assigning the pin and the time (in milliseconds) for the long press.
 */
Button button1(4, 5000);

short result = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the button and storing the result into this variable to next analysis. */
    result = button1.checkPress();

    /* Examining the previous result and writing if the pressure is short or long to Serial Monitor. */
    if (result == 1) {
        Serial.println("SHORT PRESS!");
    } else if (result == -1) {
        Serial.println("LONG PRESS!");
    }
}