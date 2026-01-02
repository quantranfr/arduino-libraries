#include "StateButton.h"

StateButton::StateButton(uint8_t buttonPin)
  : _buttonPin(buttonPin),
    _state(IDLE),
    _stateTime(0),
    _onPressed(nullptr) {}

void StateButton::begin() {
  pinMode(_buttonPin, INPUT);
}

void StateButton::update() {
  bool pressed = (digitalRead(_buttonPin) == LOW);

  switch (_state) {

    case IDLE:
      if (pressed) {
        transition(DEBOUNCE_PRESS);
      }
      break;

    case DEBOUNCE_PRESS:
      if (!pressed) {
        transition(IDLE); // false press
      } else if (millis() - _stateTime >= DEBOUNCE_MS) {
        if (_onPressed) {
          _onPressed();
        }
        transition(PRESSED);
      }
      break;

    case PRESSED:
      if (!pressed) {
        transition(DEBOUNCE_RELEASE);
      }
      break;

    case DEBOUNCE_RELEASE:
      if (pressed) {
        transition(PRESSED); // bounce
      } else if (millis() - _stateTime >= DEBOUNCE_MS) {
        transition(IDLE);
      }
      break;
  }
}

void StateButton::transition(State newState) {
  _state = newState;
  _stateTime = millis();
}

void StateButton::onPressed(OnPressedCallback callback) {
  _onPressed = callback;
}

