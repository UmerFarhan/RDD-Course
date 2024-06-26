#include <Servo.h>
#include <NewPing.h>

const int trigPin = 10;
const int echoPin = 9;
#define maxDistance 400

int servoPin = 3;
Servo Servo1;
int angle = 0;
int blueLED = 5;
int yellowLED = 6;
int redLED = 7;

NewPing sonar(trigPin, echoPin, maxDistance);


void setup()
{
  
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Servo1.attach(servoPin);
  Serial.begin(9600);
  
}

void loop()
{
  delay(50);
  int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  angle = map(distance, 25 , 100, 0, 180);
  Servo1.write(angle);
  if (angle < 180 && angle != 0){
    (angle > 120) ? (digitalWrite(redLED, HIGH)) : (digitalWrite(redLED, LOW));
    (angle > 60) ? (digitalWrite(yellowLED, HIGH)) : (digitalWrite(yellowLED, LOW));
    (angle > 0) ? (digitalWrite(blueLED, HIGH)) : (digitalWrite(blueLED, LOW));
  }
  else{
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    Servo1.write(0);
  }
  delay(1000);
}