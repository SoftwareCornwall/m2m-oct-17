#include <NewPing.h>
int triggerPinFwd = 4;
int echoPinFwd = 5;
int echoPinDown = 17;
int triggerPinDown = 13;
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
const int lightLeftPin = 7;
const int lightMiddlePin = 6;
const int lightRightPin = 2;

NewPing sonar(triggerPinDown, echoPinDown, maxDistance);

void setup() {
  Serial.begin(115200);
  pinMode(lightLeftPin, INPUT);
  pinMode(lightMiddlePin, INPUT);
  pinMode(lightRightPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), leftInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightInterrupt, RISING);
  pinMode(leftEnable, OUTPUT);
  pinMode(leftForwards, OUTPUT);
  pinMode(rightEnable, OUTPUT);
  pinMode(leftForwards, OUTPUT);
  pinMode(rightForwards, OUTPUT);
  pinMode(rightBackwards, OUTPUT);
  pinMode(leftBackwards, OUTPUT);
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

void turnLeft(int amountTurned)
{
  leftCount = 0;
  rightCount = 0;
  digitalWrite(leftBackwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  digitalWrite(rightBackwards, LOW);
  digitalWrite(leftForwards, LOW);
  Serial.println("starting loop left");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop left");
}


void loop() {
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  int lightLeft = analogRead(lightLeftPin);
  int lightMiddle = analogRead(lightMiddlePin);
  int lightRight = analogRead(lightRightPin);
  int total = lightLeft + lightMiddle + lightRight;
  int lowestLight = 9000;
  int turnCount;
  long unsigned int distance = sonar.ping_cm();
  for(int i = 0; i < 20; i++)
  {
    if (total < lowestLight){
      lowestLight = total;
      turnCount = i;
    }
    turnLeft(13);
    hardStop();
    lightLeft = analogRead(lightLeftPin);
    lightMiddle = analogRead(lightMiddlePin);
    lightRight = analogRead(lightRightPin);
    total = lightLeft + lightMiddle + lightRight;
  }
  turnLeft((turnCount) * 9);
  hardStop();
  lightLeft = analogRead(lightLeftPin);
  lightMiddle = analogRead(lightMiddlePin);
  lightRight = analogRead(lightRightPin);
  total = lightLeft + lightMiddle + lightRight;
  while (total > lowestLight) {
    turnLeft(2);
    hardStop();
    lightLeft = analogRead(lightLeftPin);
    lightMiddle = analogRead(lightMiddlePin);
    lightRight = analogRead(lightRightPin);
    total = lightLeft + lightMiddle + lightRight;
    delay(200);
  } 
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  while (distance < 14 || distance == 0 ){
    delay(50);
    distance = sonar.ping_cm();
  }
  hardStop();
  while(true);
}
