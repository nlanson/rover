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
    long left;
    long diagLeft;
    long front;
    long diagRight;
    long right;
};

SonarSweep sonarSweep();