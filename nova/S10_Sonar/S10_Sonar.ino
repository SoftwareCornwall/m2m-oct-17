#include <NewPing.h>
int triggerPin = 4;
int echoPin = 5;
int maxDistance = 200;//do not change
int leftBackwards = 7;
int rightForwards = 12;
int leftEnable = 9;
int rightEnable = 10;
int leftForwards = 8;
int rightBackwards = 11;
int highSpeed = 100;
int leftCount;
int rightCount;

NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() 
{
  attachInterrupt(digitalPinToInterrupt(2), leftInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightInterrupt, RISING);
  Serial.begin(115200);
  pinMode(leftEnable, OUTPUT);
  pinMode(leftForwards, OUTPUT);
  pinMode(rightEnable, OUTPUT);
  pinMode(leftForwards, OUTPUT);
  pinMode(rightForwards, OUTPUT);
  pinMode(rightBackwards, OUTPUT);
  pinMode(leftBackwards, OUTPUT);
}

void hardStop()
{
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(leftBackwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  delay(600);
  digitalWrite(leftBackwards, LOW);
  digitalWrite(rightBackwards, LOW);
  digitalWrite(leftForwards, LOW);
  digitalWrite(rightForwards, LOW);
}

void leftInterrupt()
{
  leftCount++;
  Serial.print("left ");
  Serial.println(leftCount);
}

void rightInterrupt()
{
  rightCount++;
  Serial.print("right ");
  Serial.println(rightCount);
}

void turnLeft(int amountTurned)
{
  leftCount = 0;
  rightCount = 0;
  digitalWrite(leftBackwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  Serial.println("starting loop left");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop left");
}

void turnRight(int amountTurned)
{
  leftCount = 0;
  rightCount = 0;
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  Serial.println("starting loop right");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop right");
}
void timeForward(float delayTime)
{
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(leftBackwards, LOW);
  digitalWrite(rightBackwards, LOW);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  delay(delayTime*1000);
}


void loop() 
{ 
  analogWrite(rightEnable, highSpeed);
  analogWrite(leftEnable, highSpeed);
  digitalWrite(rightBackwards, LOW);
  digitalWrite(leftBackwards, LOW);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  
  long unsigned int distance = sonar.ping_cm();
  
  Serial.println(distance);
  
  while (((distance) > 20) || ((distance) = 0))
  {
    delay(50);
    distance = sonar.ping_cm();
    Serial.println(distance);
  }
  hardStop();
  Serial.println(distance);
  turnRight(84);
  
  hardStop();
  timeForward(3);
  hardStop();
  while (true);
}
