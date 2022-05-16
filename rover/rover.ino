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

  delay(4000);
}


// Main loop function
void loop()
{
  SonarSweep sweep = sonarSweep();
  
  // Checks if the rover can go straight.
  // True if front distance > 2.5, diagonal distances > 8.
  bool canGoStraight = (sweep.front > 2.5) && (sweep.diagLeft > 8) && (sweep.diagRight > 8);
 
  // Checks if the rover can go left/right.
  // True if the left/right distances > 7.5 and corresponding diagonal distances > 7.5.
  bool canGoRight = (sweep.right > 7.5) && (sweep.diagRight > 7.5);
  bool canGoLeft = (sweep.left > 7.5) && (sweep.diagLeft > 7.5);

  // Make turns if needed.
  // If we can go straight, no turns will be made.
  //
  // Doing a straight 90degree will get the wheel stuck on the maze wall, 
  // so the rover will need to move a little forwards before or while turning.
  if (!canGoStraight) {
    // If the rover can go right and there is more distance to the right,
    //    turn right
    // Else if the rover can go left and there is more distance to the left,
    //    turn left
    // Otherwise
    //    do a u turn
    if (canGoRight && (sweep.right > sweep.left)) {
      roverTurnRight();
    } else if (canGoLeft && (sweep.left > sweep.right)) {
      roverTurnLeft();
    } else {
      roverUTurn();
    }
  }

  // Drive forwards to the next cell.
  roverForwards();
  delay(1750); // This timiing needs to be adjusted.
  stopRover();
} 
