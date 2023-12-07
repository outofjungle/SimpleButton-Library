#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

#include "Arduino.h"

class SimpleButton
{
public:
    SimpleButton(int pin);
    bool pressed();

    static const long DebounceDelay = 50;

private:
    int _pin;
    int _debouncedButtonState;
    int _lastButtonState;
    long _lastDebounceTime;
};

#endif
