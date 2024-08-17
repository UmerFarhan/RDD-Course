#include <Servo.h>

int trig = 9;
int echo = 10;


int motorA1 = 7;
int motorB1 = 6; 

int motorA2 = 3;
int motorB2 = 4;

int motorA3 = 12;
int motorB3 = 13;

int motorA4 = 11;
int motorB4 = 8;

int servoPin = 5; 

Servo Servo1;


int grabbed = 0;


void setup()
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorA3, OUTPUT);
  pinMode(motorB3, OUTPUT);
  pinMode(motorA4, OUTPUT);
  
  Servo1.attach(servoPin); 
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  // Get distance
  int distance = pingCm();
  
  if (distance < 30){
    moveForward();
  }
  
  else if (distance > 50){
    moveBackward();
  }
  else{
    stopMotors();
    grabItem();
  }
    
}

int pingCm(){
  
  // Send trigger pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Calculate time of flight
  long duration = pulseIn(echo, HIGH);
  
  return duration * 0.034 / 2;
}

void moveForward(){
  // Move motor 1 Forward
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorB1, LOW);
  // Move motor 2 Forward
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB2, LOW);
  // Move motor 3 Forward
  digitalWrite(motorA3, HIGH);
  digitalWrite(motorB3, LOW);
  // Move motor 4 Forward
  digitalWrite(motorA4, HIGH);
  digitalWrite(motorB4, LOW);
}

void moveBackward(){
  // Move motor 1 Backward
  digitalWrite(motorA1, LOW);
  digitalWrite(motorB1, HIGH);
  // Move motor 2 Backward
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB2, HIGH);
  // Move motor 3 Backward
  digitalWrite(motorA3, LOW);
  digitalWrite(motorB3, HIGH);
  // Move motor 4 Backward
  digitalWrite(motorA4, LOW);
  digitalWrite(motorB4, HIGH);
}

void stopMotors(){
  // Stop Motor 1
  digitalWrite(motorA1, LOW);
  digitalWrite(motorB1, LOW);
  // Stop Motor 2
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB2, LOW);
  // Stop Motor 3
  digitalWrite(motorA3, LOW);
  digitalWrite(motorB3, LOW);
  // Stop Motor 4
  digitalWrite(motorA4, LOW);
  digitalWrite(motorB4, LOW);
}


void grabItem(){
  if(grabbed == 0){
    grabbed = 1;
    // Turn grabber motor to grab item
    Servo1.write(90);
  }
}

void releaseItem(){
  if(grabbed == 1){
    Servo1.write(0);
    grabbed = 0;
  }
}

