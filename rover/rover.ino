// Rover code for ENGN1211
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

const int enablePin1 = 8; //H-bridge enable pin1, 1,2 EN
const int inputPin1 = 7;  //H-bridge inputPin 1
const int inputPin2 = 6;  //H-bridge inputPin 2
const int enablePin2 = 9; //H-bridge enable pin2, 3,4 EN
const int inputPin3 = 3;  //H-bridge inputPin 3
const int inputPin4 = 4;  //H-bridge inputPin 4
int incomingByte = 0;


void setup() {
  Serial.begin(9600);
  pinMode(enablePin1, 8);
  pinMode(inputPin1, 7);
  pinMode(inputPin2, 6);
  pinMode(enablePin2, 9);
  pinMode(inputPin3, 3);
  pinMode(inputPin4, 4);
  
}

void motor1Reverse() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}
// Turn motor 1 Forwards
void motor1Forwards() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, HIGH);
}

// Turn motor 2 Reverse
void motor2Reverse() {
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}

// Turn 2 Forwards
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

// Move the rover forwards
void roverForward() {
  motor1Reverse();
  motor2Reverse();
}

// Move the rover backwards
void roverBackward() {
  motor1Forwards();
  motor2Forwards();
}

// Turn the rover to the right
void roverTurnRight() {
  motor1Forwards();
  motor2Reverse();
  delay(1000);
  motor1Stop();
  motor2Stop();
}

// Turn the rover to the left
void roverTurnLeft() {
  motor1Reverse();
  motor2Forwards();
}

// Stop the rover
void stopRover() {
  motor1Stop();
  motor2Stop();
}

void loop()
{
  motor1Forwards();
  motor2Forwards();
  delay(2000);
  motor1Stop();
  motor2Stop();
  delay(1000);
  roverTurnRight();
}
