// Low level component control function delcarations
//
// Authors
//  - Noah Lanson

#include "Arduino.h"
#include "pins.h"
#include <Servo.h>

extern Servo servo;

// Servo control function declarations
void servoRight();
void servoLeft();
void servoReset();

// Motor control function declarations
void motor1Reverse();
void motor1Forwards();
void motor2Reverse();
void motor2Forwards();
void motor1Stop();
void motor2Stop();

// Sonar sensor code
long callSensor();