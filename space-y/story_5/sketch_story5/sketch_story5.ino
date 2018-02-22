const int leftMotorReverse = 7; //Red
const int leftMotorForward = 8; //Yellow
const int leftMotorEnable = 9; //Blue
const int rightMotorReverse = 11; //Red
const int rightMotorForward = 12; //Yellow
const int rightMotorEnable = 10; //Blue

volatile int leftPulseCounter = 0;
volatile int rightPulseCounter = 0;

void interruptLeftMotor()
{
  Serial.println("left pulse count: " );
  Serial.println(leftPulseCounter);
  leftPulseCounter++;
}

void interruptRightMotor()
{
  Serial.println("right pulse count: " );
  Serial.println(rightPulseCounter);
  rightPulseCounter++;
}

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

void straightLineCheck()
{
  while (leftPulseCounter != rightPulseCounter)
  {
    if(leftPulseCounter > rightPulseCounter)
    {
      digitalWrite(leftMotorEnable, LOW);
      digitalWrite(rightMotorEnable, HIGH);
    }
    else if(rightPulseCounter > leftPulseCounter)
    {
      digitalWrite(rightMotorEnable, LOW);
      digitalWrite(leftMotorEnable, HIGH);
    }
  }
  enableMotors();
}


void setup() 
{
  
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), interruptLeftMotor, RISING);
  attachInterrupt(digitalPinToInterrupt(3), interruptRightMotor, RISING);
  forwardsMotion();
  enableMotors();
  

}




void loop() 
{
  straightLineCheck();
  if(leftPulseCounter >= 833)
  {
    hardStop();
    disableMotors();
    while(true);
  }
}
