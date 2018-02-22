/*
 * 
 * 
 */



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

void timeBackward(float delayTime)
{
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  digitalWrite(leftBackwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  digitalWrite(leftForwards, LOW);
  digitalWrite(rightForwards, LOW);
  delay(delayTime*1000);
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
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  Serial.println("starting loop right");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop right");
}

void forwardFigEight()
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
}

void backwardFigEight()
{
  timeBackward(2);
  hardStop();
  turnRight(80);
  hardStop();
  timeBackward(2);
  hardStop();
  turnRight(70);
  hardStop();
  timeBackward(2);
  hardStop();
  turnRight(73);
  hardStop();
  timeBackward(4);
  hardStop();
  turnLeft(72);
  hardStop();
  timeBackward(2);
  hardStop();
  turnLeft(70);
  hardStop();
  timeBackward(1.7);
  hardStop();
  turnLeft(70);
  hardStop();
  timeBackward(1.6); //this was 3.1
  hardStop();
  
  
  turnLeft(10);    //this stops and corrects the angle 
  hardStop();
  timeBackward(1.3);
  hardStop();
}

void forwardFigEightTick()
{
  tickForward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickForward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickForward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickForward(400);
  hardStop();
  turnLeft(84);
  hardStop();
  tickForward(200);
  hardStop();
  turnLeft(84);
  hardStop();
  tickForward(200);
  hardStop();
  turnLeft(84);
  hardStop();
  tickForward(200);
  hardStop();
}

void backwardFigEightTick()
{
  tickBackward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickBackward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickBackward(200);
  hardStop();
  turnRight(84);
  hardStop();
  tickBackward(400);
  hardStop();
  turnLeft(84);
  hardStop();
  tickBackward(200);
  hardStop();
  turnLeft(84);
  hardStop();
  tickBackward(200);
  hardStop();
  turnLeft(84);
  hardStop();
  tickBackward(200);
  hardStop();
}
void loop()
{ 
  forwardFigEightTick();
  delay(1000);
  backwardFigEightTick();
  while(true); 
}
