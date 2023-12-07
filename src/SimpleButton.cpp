#include "Arduino.h"
#include "SimpleButton.h"

SimpleButton::SimpleButton(int pin)
{
    _pin = pin;
    _lastButtonState = LOW;
    _lastDebounceTime = 0;
}

bool SimpleButton::pressed()
{
    bool pressed = false;

    int currentButtonState = digitalRead(_pin);
    if (currentButtonState != _lastButtonState)
    {
        _lastDebounceTime = millis();
    }

    _lastButtonState = currentButtonState;
    if ((millis() - _lastDebounceTime) > DebounceDelay)
    {
        if (_debouncedButtonState != currentButtonState)
        {
            _debouncedButtonState = currentButtonState;
            if (_debouncedButtonState == HIGH)
            {
                pressed = true;
            }
        }
    }

    return pressed;
}
