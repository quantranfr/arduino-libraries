#include "Metronome.h"

Metronome::Metronome(StateBuzzer& buzzer) : _buzzer(buzzer) {}

void Metronome::start(int bpm) {
  _interval = 60000UL / bpm;
  _lastBeat = millis();
  _running = true;
}

void Metronome::stop() {
  _running = false;
}

void Metronome::update() {

  if (!_running) return;

  if (millis() - _lastBeat >= _interval) {
    _lastBeat += _interval;
    _buzzer.beep(50);
  }
}
