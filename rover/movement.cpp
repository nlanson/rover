// Movement code for rover
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

#include "movement.h"
#include "components.h"

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
  delay(1568); // 1568 is good but little under after a few runs
  stopRover();
}

// Turn the rover to the right
// UNIMPLEMENTED
void roverTurnRight() {
  motor1Reverse();
  motor2Forwards();
}

// Stop the rover
void stopRover() {
  motor1Stop();
  motor2Stop();
}
