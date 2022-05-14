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
  // // Drive forwards for 4000 ms
  // roverForward(4000);
  // delay(1000);
  long distance = callSensor();
  //If statements checking what position the servo is in
    if (pos = 90) {
      //Turns the rover left and if there is no wall to the rover's left.
      if (distance > 5) { 
        centreServo();
        roverTurnLeft();
      }
      if (distance < 5) {
        turnServoToLeft();
      }
    }

    if (pos = -90) {
      if (distance < 5){
        centreServo();
        roverTurnRight();
        roverTurnRight();
      }
      if (distance > 5) {
        centreServo();
        roverTurnRight();
        }
    } 
    if (pos = 0) { //
      if (distance < 2.5) {
      stopRover();
      delay(2000);
      turnServoToRight();
      }
      else {
        roverForward();
        delay(500);
        }      
    }
} 

  // Turn right and then stop for 1000 ms
  // roverTurnLeft();
  // delay(1000);

