#include <Servo.h>

int trig = 9;
int echo = 10;


int motorA1 = 7;
int motorB1 = 6;

int motorA2 = 3;
int motorB2 = 4;

void setup()
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  // Get distance
  int distance = pingCm();
  
  if (distance < 30){
    // Move motor 1 forward
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorB1, LOW);
    // Move motor 2 forward
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB2, LOW);
  }
  
  else if (distance > 50){
    // Move motor 1 backward
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB1, HIGH);
    // Move motor 2 backward
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB2, HIGH);
  }
  else{
    // Stop Motor 1
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB1, LOW);
    // Stop Motor 2
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB2, LOW);
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