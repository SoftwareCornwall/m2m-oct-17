//global variables

int leftCount;
int rightCount;
int leftBackwards = 7;
int rightForwards = 12;
int leftEnable = 9;
int rightEnable = 10;
int leftForwards = 8;
int rightBackwards = 11;
int highSpeed = 90;

void setup() 
{
  Serial.begin(115200);
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
  digitalWrite(leftForwards, tHIGH);
  digitalWrite(rightBackwards, HIGH);
  Serial.println("starting loop right");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop right");
}

void loop()
{
  timeForward(2);
  hardStop();
  turnRight(80);
  hardStop();
  timeForward(2);
  hardStop();
  turnRight(70);
  hardStop();
  timeForward(2);
  hardStop();
  turnRight(73);
  hardStop();
  timeForward(4);
  hardStop();
  turnLeft(72);
  hardStop();
  timeForward(2);
  hardStop();
  turnLeft(70);
  hardStop();
  timeForward(0.75);
  hardStop();
  turnLeft(70);
  hardStop();
  timeForward(3.1);
  hardStop();
  while (true);
}
