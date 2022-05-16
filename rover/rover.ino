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

  delay(5000);
}


// Main loop function
void loop()
{
  SonarSweep sweep = sonarSweep();
  bool canGoStraight = (sweep.front > 2.5) && (sweep.diagLeft > 5) & (sweep.diagRight > 5);
  bool canGoRight = (sweep.right > 5) && (sweep.diagRight > 5);
  bool canGoLeft = (sweep.left > 5) && (sweep.diagLeft > 5);

  // Make turns if needed. 
  // This series of statements does not take into accound if we can go straight but there
  // is a greater area to the left or right.
  if (!canGoStraight) {
    // If right is clear and right dist > left dist, turn right.
    // Else if left if clearn and left dist > right dist, turn left.
    // Else, turn around and go back.
    if (canGoRight && (sweep.right > sweep.left)) {
      roverTurnRight();
    } else if (canGoLeft & (sweep.left > sweep.right)) {
      roverTurnLeft();
    } else {
      roverUTurn();
    }
  }

  // Go forwards to next cell.
  roverForwards();
  delay(1500);
  stopRover();
} 
