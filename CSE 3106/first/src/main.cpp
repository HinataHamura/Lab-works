#include <Arduino.h>
const int LED = PA5;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH); // ON
  delay(500);
  digitalWrite(LED, LOW);  // OFF
  delay(500);
}


