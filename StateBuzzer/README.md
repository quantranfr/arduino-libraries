# StateBuzzer

A lightweight Arduino library for controlling a buzzer using non-blocking timing.
It allows short beeps to be triggered without using delay(), making it suitable for event-driven sketches and cooperative multitasking patterns.

The library is designed to follow the same philosophy as StateButton:
simple state management with an update() method that must be called frequently from loop().

## Features

	•	Non-blocking buzzer control using millis()
	•	Simple beep(duration) interface
	•	Explicit on() and off() control
	•	Designed to work cleanly with event-driven sketches
	•	Minimal footprint and easy to integrate

## Installation

	1.	Download or clone this repository.
	2.	Copy the StateBuzzer folder into your Arduino libraries directory.

Typical location: `Documents/Arduino/libraries/`

Restart the Arduino IDE after installing.

## Basic Usage

```cpp
#include <StateBuzzer.h>

StateBuzzer buzzer(3);

void setup() {
  buzzer.begin();
}

void loop() {
  buzzer.beep(100);  // beep for 100 ms
  delay(1000);
}
```

## Minimal Non-Blocking Example

This example produces a 100 ms beep every second without blocking the main loop.

```cpp
#include <StateBuzzer.h>

StateBuzzer buzzer(3);

unsigned long lastBeep = 0;

void setup() {
  buzzer.begin();
}

void loop() {

  unsigned long now = millis();

  if (now - lastBeep >= 1000) {
    lastBeep = now;
    buzzer.beep(100);
  }

  buzzer.update();
}
```

## Design Philosophy

StateBuzzer focuses only on low-level buzzer control.
Higher-level behaviors such as:
	•	metronomes
	•	alarms
	•	rhythmic patterns

should be implemented in separate classes or sketches using StateBuzzer as the sound driver.

This separation keeps the library:
	•	simple
	•	reusable
	•	easy to maintain

## Example Integrations

StateBuzzer works well with event-driven components such as:
	•	button state machines
	•	timers
	•	metronomes
	•	schedulers

