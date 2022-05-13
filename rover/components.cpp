// Low level component control code for the rover
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson


#include "Arduino.h"
#include "pins.h"
#include "components.h"

// Turn motor 1 in reverse.
void motor1Reverse() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

// Turn motor 1 forwards
void motor1Forwards() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, HIGH);
}

// Turn motor 2 in reverse
void motor2Reverse() {
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}

// Turn motor 2 forwards
void motor2Forwards() {
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, HIGH);
  digitalWrite(inputPin4, LOW);
}

// Stop motor 1
void motor1Stop() {
  digitalWrite(enablePin1, LOW);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

// Stop motor 2
void motor2Stop() {
  digitalWrite(enablePin2, LOW);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}