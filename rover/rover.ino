// Rover code for ENGN1211
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

#include "pins.h"
#include "movement.h"
#include "components.h"

int pos = 0;

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
  servoReset(&pos);

  delay(5000);
}


// Main loop function
void loop()
{
  if (callSensor() < 2.5) {
    //Sweep
    servoRight(&pos);
    delay(500);
    long rd = callSensor();
    delay(500);
    servoLeft(&pos);
    delay(500);
    long ld = callSensor();
    delay(500);

    // Reset servo
    servoReset(&pos);
    delay(1000);
    
    //Turns
    if (rd < 5 && ld < 5) {
      roverTurnRight();
      roverTurnRight();
    } else if (rd > ld) {
      roverForwards();
      delay(375);
      roverTurnRight();
    } else {
      roverForwards();
      delay(375);
      roverTurnLeft();
    }
  } else {
    // Move forwards until distance is less than 2.5
    while (callSensor() > 2.5) {
      //roverRightOffset();
      roverForwards();
    }

    stopRover();
  }
} 
