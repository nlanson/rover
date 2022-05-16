// Motor function delcarations
//
// Authors
//  - Noah Lanson

#include "Arduino.h"
#include "pins.h"
#include "components.h"

void roverForwards();
void roverBackward();
void roverTurnRight();
void roverTurnLeft();
void roverUTurn();
void stopRover();



// Sonar sweep structure
struct SonarSweep {
    int left;
    int diagLeft;
    int front;
    int diagRight;
    int right;
};

SonarSweep sonarSweep();