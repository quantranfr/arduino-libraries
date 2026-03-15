#include <StateBuzzer.h>
#include <Metronome.h>

StateBuzzer buzzer(3);
Metronome metro(buzzer);

void setup() {
  buzzer.begin();
  metro.start(92);   // 92 BPM
}

void loop() {
  buzzer.update();
  metro.update();
}

