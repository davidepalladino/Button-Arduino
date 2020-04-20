#include "Button.h"

Button::Button(unsigned short pinButton) {
    setPinButton(pinButton);
    setTimeLongPress(DEFAULT_LONG_PRESSURE);
    setPtrActionLong(NULL);
    setPtrActionShort(NULL);
}

Button::Button(unsigned short pinButton, unsigned long timeLongPress) : Button (pinButton) {
    setTimeLongPress(timeLongPress);
}

Button::Button(unsigned short pinButton, unsigned long timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong) : Button(pinButton, timeLongPress) {
    setPtrActionLong(ptrActionLong);
    setPtrActionShort(ptrActionShort);
}

void Button::setPinButton(unsigned short pinButton) {
    this->pinButton = pinButton;
    pinMode(getPinButton(), INPUT_PULLUP);
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

unsigned short Button::getPinButton() {
    return this->pinButton;
}

unsigned long Button::getTimeLongPress() {
    return this->timeLongPress;
}

unsigned short Button::checkPress() {    
    /* Checking if is the first press. */
    if (digitalRead(getPinButton()) == HIGH && !getPressed()) {
        setPressed(true);
        setTimeOut(millis() + getTimeLongPress());

    /* Checking if is the long press. */
    } else if ((digitalRead(getPinButton()) == HIGH) && getPressed() && (millis() >= getTimeOut())) {
        setValuePress(-1);
        setPressed(false);
        
        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionLong != NULL) {
           this->ptrActionLong();
           
           while (digitalRead(getPinButton()) == HIGH); 
        }

    /* Checking if is the short press. */      
    } else if ((digitalRead(getPinButton()) == LOW) && getPressed() && (millis() < getTimeOut()) && (getValuePress() != 2)) {
        setValuePress(1);
        setPressed(false);

        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionShort != NULL) {
            this->ptrActionShort();
        }

    /* Checking if there is not a press. */
    } else if (digitalRead(getPinButton()) == LOW) {
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