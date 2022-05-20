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
  maze();
} 

// Level 1.1
void straightStopStraight() {
  roverForwards();
  delay(3000);
  stopRover();
  delay(1000);
  roverBackward();
  delay(3000);
}

// Level 1.2
void rectangle(bool clockwise) {
  auto turn = roverTurnRight;
  if (!clockwise) {
    turn = roverTurnLeft;
  }

  roverForwards();
  delay(3500);
  stopRover();
  delay(500);
  turn();
  delay(500);
}

// Level 2
void walledTurn() {
  while(callSensor() > 2.5) {
    roverForwards();
  }
  stopRover();
  
  SonarSweep sweep = sonarSweep();

  roverForwards();
  delay(350);
  if (sweep.left > sweep.right) {
    roverTurnLeft();
  } else {
    roverTurnRight();
  }
}



///////////////
// MAZE CODE //
///////////////

void maze() {
   SonarSweep sweep = sonarSweep();

  // Checks if the rover can go straight.
  bool canGoStraightRaw = (sweep.front > 2.5) && (sweep.diagRight > 9) && (sweep.diagLeft > 9);
  bool proceed = canGoStraightRaw;
  auto turnFunc = nextCellStraight;
  
  // Debug
  Serial.print(sweep.left);
  Serial.print(" | ");
  Serial.print(sweep.diagLeft);
  Serial.print(" | ");
  Serial.print(sweep.front);
  Serial.print(" | ");
  Serial.print(sweep.diagRight);
  Serial.print(" | ");
  Serial.print(sweep.right);
  Serial.print("\n");

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

    if (canGoStraight) {
      proceed = true;
    } else if (canGoRight) {
      roverForwards();
      delay(400);
      roverTurnRight();
      proceed = true;
      turnFunc = nextCellTurn;
    } else if (canGoLeft) {
      roverForwards();
      delay(400);
      roverTurnLeft();
      proceed = true;
      turnFunc = nextCellTurn;
    }
  }


  if (proceed) {
    turnFunc();
  } else {
    roverBackward();
    delay(5400);
    stopRover();
  }
}


void nextCellStraight() {
  roverForwards();
  delay(2750);
  stopRover();
}

void nextCellTurn() {
  roverForwards();
  delay(2400);
  stopRover();
}
