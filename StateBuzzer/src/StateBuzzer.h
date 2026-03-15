#ifndef STATEBUZZER_H
#define STATEBUZZER_H

#include <Arduino.h>

class StateBuzzer {

  public:
    StateBuzzer(uint8_t pin);

    void begin();
    void update();

    void beep(unsigned long duration);
    void on();
    void off();

  private:
    uint8_t _pin;

    bool _beepActive = false;
    unsigned long _startTime = 0;
    unsigned long _duration = 0;
};

#endif
