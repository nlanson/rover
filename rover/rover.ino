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
  // Pin and serial initialisation.
  Serial.begin(9600);
  pinMode(enablePin1, OUTPUT);
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(inputPin3, OUTPUT);
  pinMode(inputPin4, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);


  // Servo initialisation.
  servo.attach(8);
  servoReset();
}



// Main loop function
void loop()
{
  if (callSensor() > 5) {
    roverForwards();
  } else {
    stopRover();
  }
}
