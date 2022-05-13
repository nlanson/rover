// Rover code for ENGN1211
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

#include "pins.h"
#include "movement.h"
#include "components.h"

// Setup function
void setup() {
  Serial.begin(9600);
  // pinMode(echoPin, INPUT);
  // pinMode(trigPin, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(inputPin3, OUTPUT);
  pinMode(inputPin4, OUTPUT);
}

// Main loop function
void loop()
{
  // Drive forwards for 4000 ms
  roverForward(4000);
  delay(1000);

  // Turn right and then stop for 1000 ms
  roverTurnRight();
  delay(1000);
}
