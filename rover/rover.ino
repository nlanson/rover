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
  Serial.begin(9600);
  // pinMode(echoPin, INPUT);
  // pinMode(trigPin, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(inputPin3, OUTPUT);
  pinMode(inputPin4, OUTPUT);
  servo.attach(8);

  delay(1500);
  roverForward(4000);
}


long callSensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin,HIGH);
  return duration/29/2;
}
// Main loop function
void loop()
{
  // // Drive forwards for 4000 ms
  // roverForward(4000);
  // delay(1000);
  long distance = callSensor();
  if (distance < 5)
  {
    stopRover();
    delay(2000);

    for (int pos = 0; pos <= 90; pos += 1) {
      servo.write(pos);
      delay(10);
      long distance = callSensor();
      if (distance < 5) {
        for (int pos = 90; pos<= -90; pos -=1) {
          long distance = callSensor();
        }
      }
    }
  } 

  // Turn right and then stop for 1000 ms
  // roverTurnLeft();
  // delay(1000);
}
