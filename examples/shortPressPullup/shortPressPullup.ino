/**
  Checking if the pressure is short or not, with internal resistor.
 by Davide Palladino <https://github.com/davidepalladino>

 modified on 4th May 2020
 by Davide Palladino
*/

#include <Button.h>

/**
 * Creating of the button assigning the pin and the constant "PULLUP". 
 * If the board is an ESP family, the respective constant "PULLUP" is "INTERNAL_RESISTOR".
 */
Button button1(4, PULLUP);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and writing to Serial Monitor, if is pressed. */
    if (button1.checkPress() == 1) {
        Serial.println("PRESSED!");
    }
}