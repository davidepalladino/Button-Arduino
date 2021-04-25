/**
 Checking if the pressure is short or long, with internal resistor
 by Davide Palladino <https://github.com/davidepalladino>

 modified on 25th April 2021
 by Davide Palladino
*/

#include <Button.h>

/**
 * Creating of the button assigning the pin, the constant "PULLUP" and the time (in milliseconds) for the long press.
 * If the board is an ESP family, the respective constant "PULLUP" is "INTERNAL_RESISTOR".
 */
Button button1(4, PULLUP, 5000);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and writing to Serial Monitor, if the press is short or long. */
    if (button1.checkPress() == 1) {
        Serial.println("SHORT PRESS!");
    } else if (button1.checkPress() == -1) {
        Serial.println("LONG PRESS!");
    }
}