#include <StateButton.h>

StateButton button1(A1);

void setup() {
  Serial.begin(9600);
  button1.begin();
}

void loop() {
  button1.update();

  if (button1.pressed()) {
    Serial.println("Button clicked!");
  }

  if (button1.isDown()) {
    Serial.println("Button held");
  }
}
