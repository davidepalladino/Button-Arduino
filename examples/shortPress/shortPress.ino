/**
 Checking if the pressure is short or not.
 by Davide Palladino <https://github.com/davidepalladino>

 modified on 4th May 2020
 by Davide Palladino
*/

#include <Button.h>

/* Creating of the button assigning only the pin. */
Button button1(4);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and writing to Serial Monitor, if is pressed. */
    if (button1.checkPress() == 1) {
        Serial.prisntln("PRESSED!");
    }
}