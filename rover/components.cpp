// Low level component control code for the rover
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson


#include "components.h"

Servo servo;

void servoHalfRight() {
  delay(100);
  servo.write(45);
  delay(100);
}

void servoHalfLeft() {
  delay(100);
  servo.write(135);
  delay(100);
}
// Turn the servo to the right
void servoRight() {
  delay(100);
  servo.write(0);
  delay(100);
}

// Resets the servo's position to the centre
void servoReset() {
  delay(100);
  servo.write(90);
  delay(100);
}

// Turn the servo to the left
void servoLeft() {
  delay(100); 
  servo.write(180);
  delay(100);
}

// Take a sonar sensor measurement. 
// Value returned is the measured distance in centimetres.
long callSensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration/29/2;
}


// Turn motor 1 in reverse.
void motor1Reverse() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

// Turn motor 1 forwards
void motor1Forwards() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, HIGH);
}

// Turn motor 2 in reverse
void motor2Reverse() {
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}

// Turn motor 2 forwards
void motor2Forwards() {
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, HIGH);
  digitalWrite(inputPin4, LOW);
}

// Stop motor 1
void motor1Stop() {
  digitalWrite(enablePin1, LOW);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

// Stop motor 2
void motor2Stop() {
  digitalWrite(enablePin2, LOW);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}
