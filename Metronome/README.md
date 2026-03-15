# Metronome

A lightweight Arduino library that generates periodic beats at a given tempo (BPM).

The library handles non-blocking timing using millis() and triggers a short beep through a StateBuzzer (or compatible) object.

## Features

	•	Non-blocking operation
	•	Tempo control in beats per minute (BPM)
	•	Simple start(), stop(), and update() interface
	•	No direct hardware control

## Installation

Copy the Metronome folder into your Arduino libraries directory, or install it as a ZIP library from the Arduino IDE.

## Minimal Example

```cpp
#include <StateBuzzer.h>
#include <Metronome.h>

StateBuzzer buzzer(4);
Metronome metro(buzzer);

void setup() {
  buzzer.begin();
  metro.start(92);   // 92 BPM
}

void loop() {
  buzzer.update();
  metro.update();
}
```

## Notes

	•	The beat interval is computed internally as 60000 / BPM.
	•	Call update() frequently from loop().
	•	The actual beep duration is handled by the buzzer driver.
:::
