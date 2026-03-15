#include <StateBuzzer.h>

StateBuzzer buzzer(3);   // buzzer connected to pin 3

unsigned long lastBeep = 0;

void setup() {
  buzzer.begin();
}

void loop() {

  unsigned long now = millis();

  // trigger a beep every second
  if (now - lastBeep >= 1000) {
    lastBeep = now;
    buzzer.beep(900);   // beep for 100 ms
  }

  buzzer.update();
}
