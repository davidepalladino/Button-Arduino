#include "Button.h"

Button::Button(uint8_t pin) : Button(pin, NO_PULLUP, DEFAULT_LONG_PRESSURE, NULL, NULL) {}

Button::Button(uint8_t pin, input mode) : Button(pin, mode, DEFAULT_LONG_PRESSURE, NULL, NULL) {}

Button::Button(uint8_t pin, uint32_t timeLongPress) : Button(pin, NO_PULLUP, timeLongPress, NULL, NULL) {}

Button::Button(uint8_t pin, input mode, uint32_t timeLongPress) : Button(pin, mode, timeLongPress, NULL, NULL) {}

Button::Button(uint8_t pin, uint32_t timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong) : Button(pin, NO_PULLUP, timeLongPress, ptrActionShort, ptrActionLong) {}

Button::Button(uint8_t pin, input mode, uint32_t timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong) {
    setPin(pin);
    setMode(mode);

    setValuePress();

    pinMode(getPin(), getMode());
    
    setTimeLongPress(timeLongPress);

    setPtrActionShort(ptrActionShort);
    setPtrActionLong(ptrActionLong);
}

void Button::setTimeLongPress(uint32_t timeLongPress) {
    this->timeLongPress = timeLongPress;
}

void Button::setPtrActionShort(ptrProcedure ptrActionShort) {
    this->ptrActionShort = ptrActionShort;
}

void Button::setPtrActionLong(ptrProcedure ptrActionLong) {
    this->ptrActionLong = ptrActionLong;
}

uint32_t Button::getTimeLongPress() {
    return this->timeLongPress;
}

uint8_t Button::checkPress() {   
    /* Checking if is the first press. */
    if (digitalRead(getPin()) == getValuePress() && !getStatus()) {
        setStatus(true);

        /* Checking if is set the time of long press. If there is a value, will be set the timeout. */
        if (getTimeLongPress() > 0) {
            setTimeOut(millis() + getTimeLongPress());
        }

    /* Checking if is the long press. */
    } else if ((digitalRead(getPin()) == getValuePress()) && getStatus() && (millis() >= getTimeOut()) && (getTimeLongPress() > 0)) {
        setActualValue(-1);
        setStatus(false);

        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionLong != NULL) {
           this->ptrActionLong();
           
           while (digitalRead(getPin()) == HIGH); 
        }

    /* Checking if is the short press, verifying if is set the "timeLongPress" or not. */      
    } else if ((digitalRead(getPin()) == !getValuePress()) && getStatus() && (((getActualValue() != -1) && (millis() < getTimeOut())) || (getTimeLongPress() == 0))) {
        setActualValue(1);
        setStatus(false);

        /* If there is a pointer to a procedure, will be executed. */
        if (this->ptrActionShort != NULL) {
            this->ptrActionShort();
        }

    /* Checking if there is not a press. */
    } else if (digitalRead(getPin()) == !getValuePress()) {
        setActualValue(0);
        setStatus(false);
    }

    return getActualValue();
}

void Button::setPin(uint8_t pin) {
    this->pin = pin;
}

void Button::setMode(input mode) {
    /* Translation of "mode" parameter "NO_PULLUP"/"PULLUP" to the rispective "INPUT"/"INPUT_PULLUP". */
    if (mode == NO_PULLUP) {
        this->mode = INPUT;
    } else if (mode == PULLUP) {
        this->mode = INPUT_PULLUP;
    }
}

void Button::setValuePress() {
    /* Checking what is the value of press, "HIGH" if the mode is INPUT; "LOW" if is INPUT_PULLUP. */
    if (getMode() == INPUT) {
        valuePress = HIGH;
    } else if (getMode() == INPUT_PULLUP) {
        valuePress = LOW;
    }
}

void Button::setTimeOut(uint32_t timeOut) {
    this->timeOut = timeOut;
}

void Button::setStatus(boolean status) {
    this->status = status;
}

void Button::setActualValue(int8_t actualValue) {
    this->actualValue = actualValue;
}

uint8_t Button::getPin() {
    return this->pin;
}

uint8_t Button::getMode() {
    return this->mode;
}

uint8_t Button::getValuePress() {
    return this->valuePress;
}

uint32_t Button::getTimeOut() {
    return this->timeOut;
}

boolean Button::getStatus() {
    return this->status;
}

int8_t Button::getActualValue() {
    return this->actualValue;
}
