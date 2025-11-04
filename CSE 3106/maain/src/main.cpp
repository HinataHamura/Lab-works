#include <Arduino.h>


void setup() {
  pinMode(PB0, OUTPUT); // Set pin B0 as output for LED
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(PB0, brightness); // Increase brightness
    delay(10); // Wait for 10 milliseconds
  }
  for (int brightness = 255; brightness >=0; brightness--) {
    analogWrite(PB0, brightness); // Increase brightness
    delay(10); // Wait for 10 milliseconds
  }
}