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

// Turn the rover to the right
void roverTurnRight() {
  motor1Forwards();
  motor2Reverse();
  delay(1487); // 1487 ms turns very close to 90 degrees.
  stopRover();
}

// Turn the rover to the left
// UNIMPLEMENTED
void roverTurnLeft() {
  motor1Reverse();
  motor2Forwards();
}

// Stop the rover
void stopRover() {
  motor1Stop();
  motor2Stop();
}