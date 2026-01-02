# StateButton

A lightweight Arduino library that implements a debounced push-button using a simple finite state machine. It triggers a callback once per valid button press.

## Features

- Reliable software debouncing
- Non-blocking (uses `millis()`)
- Event-based `onPressed()` callback
- Designed to be called from `loop()`

## Installation

Copy the `StateButton` folder into your Arduino `libraries` directory, or install it as a ZIP library from the Arduino IDE.

## Usage

```cpp
#include <StateButton.h>

StateButton button(2);

void onButtonPressed() {
  Serial.println("Button pressed!");
}

void setup() {
  Serial.begin(9600);
  button.begin();
  button.onPressed(onButtonPressed);
}

void loop() {
  button.update();
}
```

## Notes

* The button is assumed to be active LOW.
* Debounce time is fixed at 50 ms.
* Call update() frequently from loop().

