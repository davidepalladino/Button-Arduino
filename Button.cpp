#include "Button.h"

Button::Button(unsigned short pin) {
    setPin(pin);
    setTimeLongPress(DEFAULT_LONG_PRESSURE);
    setPtrActionLong(NULL);
    setPtrActionShort(NULL);
}

Button::Button(unsigned short pin, unsigned long timeLongPress) : Button (pin) {
    setTimeLongPress(timeLongPress);
}

Button::Button(unsigned short pin, unsigned long timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong) : Button(pin, timeLongPress) {
    setPtrActionLong(ptrActionLong);
    setPtrActionShort(ptrActionShort);
}

void Button::setPin(unsigned short pin) {
    this->pin = pin;
    pinMode(getPin(), INPUT_PULLUP);
}

void Button::setTimeLongPress(unsigned long timeLongPress) {
    this->timeLongPress = timeLongPress;
}

void Button::setPtrActionShort(ptrProcedure ptrActionShort) {
    this->ptrActionShort = ptrActionShort;
}

void Button::setPtrActionLong(ptrProcedure ptrActionLong) {
    this->ptrActionLong = ptrActionLong;
}

unsigned short Button::getPin() {
    return this->pin;
}

unsigned long Button::getTimeLongPress() {
    return this->timeLongPress;
}

unsigned short Button::checkPress() {    
    /* Checking if is the first press. */
    if (digitalRead(getPin()) == HIGH && !getPressed()) {
        setPressed(true);
        setTimeOut(millis() + getTimeLongPress());

    /* Checking if is the long press. */
    } else if ((digitalRead(getPin()) == HIGH) && getPressed() && (millis() >= getTimeOut())) {
        setValuePress(-1);
        setPressed(false);
        
        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionLong != NULL) {
           this->ptrActionLong();
           
           while (digitalRead(getPin()) == HIGH); 
        }

    /* Checking if is the short press. */      
    } else if ((digitalRead(getPin()) == LOW) && getPressed() && (millis() < getTimeOut()) && (getValuePress() != -1)) {
        setValuePress(1);
        setPressed(false);

        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionShort != NULL) {
            this->ptrActionShort();
        }

    /* Checking if there is not a press. */
    } else if (digitalRead(getPin()) == LOW) {
        setValuePress(0);
        setPressed(false);
    }

    return getValuePress();
}

void Button::setTimeOut(unsigned long timeOut) {
    this->timeOut = timeOut;
}

void Button::setPressed(boolean pressed) {
    this->pressed = pressed;
}

void Button::setValuePress(short valuePress) {
    this->valuePress = valuePress;
}

unsigned long Button::getTimeOut() {
    return this->timeOut;
}

boolean Button::getPressed() {
    return this->pressed;
}

short Button::getValuePress() {
    return this->valuePress;
}
