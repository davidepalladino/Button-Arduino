#include "Button.h"

Button::Button(uint8_t pin) : Button(pin, B_NOPULLUP, DEFAULT_LONG_PRESS) {}

Button::Button(uint8_t pin, input_t mode) : Button(pin, mode, DEFAULT_LONG_PRESS) {}

Button::Button(uint8_t pin, uint32_t timeLongPress) : Button(pin, B_NOPULLUP, timeLongPress) {}

Button::Button(uint8_t pin, input_t mode, uint32_t timeLongPress) {
    this->pin = pin;

    setMode(mode);
    setValuePress();

    pinMode(this->pin, this->mode);
    
    setTimeLongPress(timeLongPress);
}

void Button::setTimeLongPress(uint32_t timeLongPress) { this->timeLongPress = timeLongPress; }

uint32_t Button::getTimeLongPress() { return timeLongPress; }

int8_t Button::checkPress() {  
    /* Read and save the value for next analysis. */
    uint8_t valueRead = digitalRead(pin);

    /* Cheching if the button is pressed in this moment. */
    if (valueRead == valuePress) {
        /* Checking if is the first press or not. */
        if (!isPressed) {
            //Serial.println("Is pressed.");
            isPressed = true;

            /* Checking if is set the time of long press. If there is a value, will be set the timeout. */
            if (getTimeLongPress() > DEFAULT_LONG_PRESS) {
                timeOut = millis() + getTimeLongPress();
            }

        } else {
            /* Checking if is the long press. */
            if ((millis() >= timeOut) && (getTimeLongPress() > DEFAULT_LONG_PRESS) && !isLongPressed) {
                //Serial.println("Is long press on first time.");
                actualValue = -1;
                isLongPressed = true;
            } else if (isLongPressed) {
                actualValue = 0;
            } else {
                actualValue = 0;
            }
        }
    
    /* Else, the button is not pressed in this moment. */
    } else {
        /* Checking if is the short press, verifying if is set the "timeLongPress" or not. */      
        if (isPressed && (((actualValue != -1) && (millis() < timeOut) && !isLongPressed) || (getTimeLongPress() == DEFAULT_LONG_PRESS))) {
            //Serial.println("Is short press.");
            isPressed = false;
            isLongPressed = false;
            
            actualValue = 1;

        /* Else, is not a press. */
        } else {
            //Serial.println("Is not pressed.");
            isPressed = false;
            isLongPressed = false;
            
            actualValue = 0;
        }
    }
    
    return actualValue;
}

void Button::setMode(input_t mode) {
    /* Translation of "mode" parameter "B_NOPULLUP"/"B_PULLUP" to the rispective "INPUT"/"INPUT_PULLUP". */
    if (mode == B_NOPULLUP) {
        this->mode = INPUT;
    } else if (mode == B_PULLUP) {
        this->mode = INPUT_PULLUP;
    }
}

void Button::setValuePress() {
    /* Checking what is the value of press, "HIGH" if the mode is INPUT; "LOW" if is INPUT_PULLUP. */
    if (mode == INPUT) {
        valuePress = HIGH;
    } else if (mode == INPUT_PULLUP) {
        valuePress = LOW;
    }
}