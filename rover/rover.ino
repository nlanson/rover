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
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(enablePin1, 8);
  pinMode(inputPin1, 7);
  pinMode(inputPin2, 6);
  pinMode(enablePin2, 9);
  pinMode(inputPin3, 3);
  pinMode(inputPin4, 4);
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
