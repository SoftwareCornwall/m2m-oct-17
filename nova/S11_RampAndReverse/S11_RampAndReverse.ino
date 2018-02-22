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

NewPing sonar(triggerPinDown, echoPinDown, maxDistance);

void setup() {
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
void tickForward(float ticks)
{
  leftCount = 0;
  rightCount = 0;  
  int rightDone = false;
  int leftDone = false;
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(leftBackwards, LOW);
  digitalWrite(rightBackwards, LOW);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);

  while (!(rightDone && leftDone))
  {
    if ((rightDone == false) && (rightCount >= ticks))
    {
      digitalWrite(rightBackwards, HIGH);
      rightDone = true;
      Serial.println("right is done");
    }
    if ((leftDone == false) && (leftCount >= ticks))
    {
      digitalWrite(leftBackwards, HIGH);
      leftDone = true;
      Serial.println("left is done");
    }
    delay(1);
  }
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

void tickBackward(float ticks)
{
  leftCount = 0;
  rightCount = 0;
  int rightDone = false;
  int leftDone = false;
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(leftBackwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  digitalWrite(leftForwards, LOW);
  digitalWrite(rightForwards, LOW);

  while (!(rightDone && leftDone))
  {
    if ((rightDone == false) && (rightCount > ticks))
    {
      digitalWrite(rightForwards, HIGH);
      rightDone = true;
      Serial.println("right is done");
    }
    if ((leftDone == false) && (leftCount > ticks))
    {
      digitalWrite(leftForwards, HIGH);
      leftDone = true;
      Serial.println("left is done");
    }
    delay(1);
  }
}


void loop() {
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(rightForwards, HIGH);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(leftBackwards, LOW);
  digitalWrite(rightBackwards, LOW);

  long unsigned int distance = sonar.ping_cm();
  Serial.println(distance);
  while (((distance) < 13) || ((distance) = 0))
  {
    delay(50);
    distance = sonar.ping_cm();
    Serial.println(distance);
  }
  hardStop();
  tickBackward(800);
  hardStop();
  turnLeft(84);
  tickForward(300);
  hardStop();
  while(true);
}
