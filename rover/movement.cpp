// Movement code for rover
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

#include "Arduino.h"
#include "pins.h"
#include "movement.h"
#include "components.h"


// Move the rover forwards for the specified duration
void roverForward(int duration) {
  motor1Forwards();
  motor2Forwards();
  delay(duration);
  stopRover();
}

// Move the rover backwards for the specified duration
void roverBackward(int duration) {
  motor1Reverse();
  motor2Reverse();
  delay(duration);
  stopRover();
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
