#include "Servo.h"

#define servoPin 9

Servo myservo;

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  myservo.attach(9);
}

void loop() {
  myservo.write(60);
  delay(2000);
  myservo.write(0);
  delay(2000);
}