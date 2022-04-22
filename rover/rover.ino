// Rover code for ENGN1211
//By Noah Lanson, Nathan Tein and CHristopher Tsirbas.

const int enablePin1 = 8; //H-bridge enable pin1, 1,2 EN
const int inputPin1 = 7; //H-bridge inputPin 1
const int inputPin2 = 6; //H-bridge inputPin 2
const int enablePin2 = 9; //H-bridge enable pin2, 3,4 EN
const int inputPin3 = 3; //H-bridge inputPin 3
const int inputPin4 = 4; //H-bridge inputPin 4
int incomingByte = 0;


void setup()
{
  Serial.begin(9600); //open serial port
  pinMode(enablePin1, 8);
  pinMode(inputPin1, 7);
  pinMode(inputPin2, 6);
  pinMode(enablePin2, 9);
  pinMode(inputPin3, 3);
  pinMode(inputPin4, 4);
  
}

void motor1Clockwise()
{
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

void motor1Anti()
{
  digitalWrite(enablePin1, HIGH);
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, HIGH);
}
  
void motor2Clockwise()
{
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}

void motor2Anti()
{
  digitalWrite(enablePin2, HIGH);
  digitalWrite(inputPin3, HIGH);
  digitalWrite(inputPin4, LOW);
}
  
void motor1Stop()
{
  digitalWrite(enablePin1, LOW);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, LOW);
}

void motor2Stop()
{
  digitalWrite(enablePin2, LOW);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, HIGH);
}

void roverForward()
{
  motor1Clockwise();
  motor2Clockwise();
}

void roverBackward()
{
  motor1Anti();
  motor2Anti();
}

void roverTurnRight()
{
  motor1Anti();
  motor2Clockwise();
}

void roverTurnLeft()
{
  motor1Clockwise();
  motor2Anti();
}

void stopRover()
{
  motor1Stop();
  motor2Stop();
}

void loop()
{
  roverForward();
  delay(100);
  stopRover();
  delay(100);
  roverTurnRight();
  delay(100);
}
