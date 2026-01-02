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

