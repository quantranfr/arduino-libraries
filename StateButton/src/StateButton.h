#ifndef STATE_BUTTON_H
#define STATE_BUTTON_H

#include <Arduino.h>

class StateButton {
public:
  typedef void (*OnPressedCallback)();

  StateButton(uint8_t buttonPin);

  void begin();
  void update();                 // to be called from loop()

  void onPressed(OnPressedCallback callback);

private:
  enum State {
    IDLE,
    DEBOUNCE_PRESS,
    PRESSED,
    DEBOUNCE_RELEASE
  };

  void transition(State newState);

  uint8_t _buttonPin;

  State _state;
  unsigned long _stateTime;

  OnPressedCallback _onPressed;

  static const unsigned long DEBOUNCE_MS = 50;
};

#endif
