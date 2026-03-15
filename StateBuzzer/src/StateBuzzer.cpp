#include "StateBuzzer.h"

StateBuzzer::StateBuzzer(uint8_t pin) {
  _pin = pin;
}

void StateBuzzer::begin() {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, HIGH);
}

void StateBuzzer::on() {
  digitalWrite(_pin, LOW);
}

void StateBuzzer::off() {
  digitalWrite(_pin, HIGH);
}

void StateBuzzer::beep(unsigned long duration) {
  on();
  _duration = duration;
  _startTime = millis();
  _beepActive = true;
}

void StateBuzzer::update() {

  if (_beepActive && millis() - _startTime >= _duration) {
    off();
    _beepActive = false;
  }

}
