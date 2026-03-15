#ifndef METRONOME_H
#define METRONOME_H

#include <Arduino.h>
#include "StateBuzzer.h"

class Metronome {

  public:
    Metronome(StateBuzzer& buzzer);

    void start(int bpm);
    void stop();
    void update();

  private:
    StateBuzzer& _buzzer;

    bool _running = false;

    unsigned long _interval;
    unsigned long _lastBeat;
};

#endif
