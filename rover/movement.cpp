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
  delay(1300); // 1568 is good but little under after a few runs
  stopRover();
}
void roverRightOffset (){
  motor1Forwards();
  motor2Reverse();
  delay(10);
  stopRover();
}

// Turn the rover to the right
void roverTurnRight() {
  motor1Reverse();
  motor2Forwards();
  delay(1300);
  stopRover();
}

// Stop the rover
void stopRover() {
  motor1Stop();
  motor2Stop();
}

//Turns servo to the right
void turnServoToRight() {
  for (int pos = 0; pos <= 90; pos += 1) {
      servo.write(pos);
      delay(10);
      }
}

//Turns servo to the left
void turnServoToLeft() {
  for (int pos = 90; pos<= -90; pos -=1) {
    servo.write(pos);
    delay(10);
    }
}

//Centres the servo so that it's facing the direction the rover's moving.
void centreServo() {
  for (int pos = -90; pos <= 0; pos +=1) {
    servo.write(pos);
    }
}
