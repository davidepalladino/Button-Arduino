/**
 Checking if the pressure is short or long.
 by Davide Palladino <https://github.com/davidepalladino>

 modified on 4th May 2020
 by Davide Palladino
*/

#include <Button.h>

/* Creating of the button assigning the pin and the time (in milliseconds) for the long press. */
Button button1(4, 5000);

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* Checking the pressure and writing to Serial Monitor, if the press is short or long. */
    if (button1.checkPress() == 1) {
        Serial.println("SHORT PRESS!");
    } else if ((button1.checkPress() == -1) {
        Serial.println("LONG PRESS!");
    }
}