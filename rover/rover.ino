// Rover code for ENGN1211
//
// Authors
//  - Christopher Tsirbas
//  - Nathan Tein
//  - Noah Lanson

// Sensor pins
#define echoPin _
#define trigPin _

// Motor 1 pins
#define enablePin1 8
#define inputPin1 7
#define inputPin2 6

// Motor 2 pins
#define enablePin2 9
#define inputPin3 3
#define inputPin4 4

// Setup function
void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT)
  pinMode(trigPin, OUTPUT)
  pinMode(enablePin1, 8);
  pinMode(inputPin1, 7);
  pinMode(inputPin2, 6);
  pinMode(enablePin2, 9);
  pinMode(inputPin3, 3);
  pinMode(inputPin4, 4);

}

// Main loop function
void loop()
{
  // Drive forwards for 4000 ms
  roverForward(4000);
  delay(1000);

  // Turn right and then stop for 1000 ms
  roverTurnRight();
  delay(1000);
}




/////////////////////////////
// MOTOR CONTROL FUNCTIONS //
/////////////////////////////

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

/////////////////////////////
// ROVER MOVEMENT FUNCTION //
/////////////////////////////


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
