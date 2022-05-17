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
  pinMode(LED_BUILTIN, OUTPUT);


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
  bool canGoStraightRaw = (sweep.front > 2.5) && (sweep.diagRight > 7.5) && (sweep.diagLeft > 7.5);
  bool proceed = canGoStraightRaw;

  if (!proceed) {
    // Checks if the rover can go left/right.
    bool canGoStraight = (sweep.front > 5);
    bool canGoRight = (sweep.right > 7.5);
    bool canGoLeft = (sweep.left > 7.6);

    Serial.print(proceed);
    Serial.print(" | ");
    Serial.print(canGoLeft);
    Serial.print(" ");
    Serial.print(canGoStraight);
    Serial.print(" ");
    Serial.print(canGoRight);
    Serial.print("\n");
    
    if (canGoRight) {
      roverForwards();
      delay(400);
      roverTurnRight();
      proceed = true;
    } else if (canGoLeft) {
      roverForwards();
      delay(400);
      roverTurnLeft();
      proceed = true;
    } else if (canGoStraight) {
      proceed = true;
    }
  }


  if (proceed) {
    nextCell();
  } else {
    roverBackward();
    delay(2500);
    stopRover();
  }
  
} 


void nextCell() {
  roverForwards();
  delay(2500);
  stopRover();
}

bool XOR(bool a, bool b)
{
    return (a + b) % 2;
}
