int turning = 0;
int leftCount;
int rightCount;
int leftBackwards = 7;
int rightForwards = 12;
int leftEnable = 9;
int rightEnable = 10;
int leftForwards = 8;
int rightBackwards = 11;
int highSpeed = 100;

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
  delay(200);
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

void turnRight(int amountTurned)
{
  leftCount = 0;
  rightCount = 0;
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightBackwards, HIGH);
  Serial.println("starting loop");
  while ((leftCount < amountTurned ) || (rightCount < amountTurned))
  {
    delay(1);
  }
  Serial.println("finished loop");
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
  analogWrite(leftEnable, highSpeed);
  analogWrite(rightEnable, highSpeed);
  timeForward(1);
  hardStop();
  delay(300);
  turnRight(80);
  hardStop();
  delay(300);
  timeForward(1.3);
  hardStop();
  delay(300);
  turnRight(80);
  hardStop();
  delay(300);
  timeForward(1);
  hardStop();
  delay(300);
  turnRight(75);
  hardStop();
  delay(300);
  timeForward(1);
  hardStop();
  delay(300);
  turnRight(75);
  hardStop();
  while(true);
}
