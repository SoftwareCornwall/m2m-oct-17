
const int leftMotorReverse = 7; //Red
const int leftMotorForward = 8; //Yellow
const int leftMotorEnable = 9; //Blue
const int rightMotorReverse = 11; //Red
const int rightMotorForward = 12; //Yellow
const int rightMotorEnable = 10; //Blue

void enableMotors()
{
  //Enable Motors
  digitalWrite(leftMotorEnable, HIGH);
  digitalWrite(rightMotorEnable, HIGH);
}

void disableMotors()
{
  //Disable Motors
  digitalWrite(leftMotorEnable, LOW);
  digitalWrite(rightMotorEnable, LOW);
}

void forwardsMotion()
{
  //Enable Forward
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void backwardsMotion()
{
  //Enable Backwards 
  digitalWrite(leftMotorReverse, HIGH);
  digitalWrite(rightMotorReverse, HIGH);
}

void hardStop()
{
  digitalWrite(leftMotorReverse, HIGH);
  digitalWrite(rightMotorReverse, HIGH);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  digitalWrite(leftMotorReverse, LOW);
  digitalWrite(rightMotorReverse, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
}

void setup() 
{
  enableMotors();
}

void loop() 
{
  forwardsMotion();
  delay(1000);
  hardStop();
  delay(1000);
  backwardsMotion();
  delay(1000);
  hardStop();
  delay(1000);
}
