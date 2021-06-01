/**
    Checking if the pressure with external resistor.

    @author Davide Palladino
    @contact me@davidepalladino.com
    @website www.davidepalladino.com
    @date 1st June, 2021
*/

#include <Button.h>

/**
 * Creating of the button assigning only the pin.
 * In this case will be utilized an external resistor.
 */
Button button1(4);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and writing to Serial Monitor, if is pressed. */
    if (button1.checkPress() == 1) {
        Serial.println("PRESSED!");
    }
}