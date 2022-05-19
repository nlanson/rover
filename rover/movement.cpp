// Movement code for rover
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

#include "movement.h"

SonarSweep sonarSweep() {
  SonarSweep a;

  servoLeft();
  delay(100);
  a.left = callSensor();
  delay(100);

  servoHalfLeft();
  delay(100);
  a.diagLeft = callSensor();
  delay(100);

  servoReset();
  delay(100);
  a.front = callSensor();
  delay(100);

  servoHalfRight();
  delay(100);
  a.diagRight = callSensor();
  delay(100);

  servoRight();
  delay(100);
  a.right = callSensor();
  delay(100);

  servoReset();
  delay(100);

  return a;
}



// Move the rover forwards indefinately
void roverForwards() {
  motor1Forwards();
  motor2Forwards();
}

// Move the rover backwards indefinately
void roverBackward() {
  motor1Reverse();
  motor2Reverse();
}

// Turn the rover to the left
void roverTurnLeft() {
  motor1Forwards();
  motor2Reverse();
  delay(1440); // 1440 is good for rectangle test
  
  stopRover();
}

// Turn the rover to the right
void roverTurnRight() {
  motor1Reverse();
  motor2Forwards();
  delay(1400);
  stopRover();
}

void roverUTurn() {
  roverTurnRight();
  roverTurnRight();
}

// Stop the rover
void stopRover() {
  motor1Stop();
  motor2Stop();
}
