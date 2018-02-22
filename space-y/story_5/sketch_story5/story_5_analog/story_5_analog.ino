const int leftMotorReverse = 7; //Red
const int leftMotorForward = 8; //Yellow
const int leftMotorEnable = 9; //Blue
const int rightMotorReverse = 11; //Red
const int rightMotorForward = 12; //Yellow
const int rightMotorEnable = 10; //Blue

volatile float leftPulseCounter = 0;
volatile float rightPulseCounter = 0;

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


void enableMotors(float leftMotorSpeed, float rightMotorSpeed)
{
  //Enable Motors
  analogWrite(leftMotorEnable, leftMotorSpeed );
  analogWrite(rightMotorEnable, rightMotorSpeed );
}

void disableMotors()
{
  //Disable Motors
  digitalWrite(leftMotorEnable, LOW);
  digitalWrite(rightMotorEnable, LOW);
}

void forwardsMotion()
{
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH );
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


void ratioCalculation()
{
  float pulseRatio;

  if(leftPulseCounter > rightPulseCounter)
  {
    pulseRatio = rightPulseCounter / leftPulseCounter;
  }
  else
  {
    pulseRatio = leftPulseCounter / rightPulseCounter;  
  }
  pulseRatio = pulseRatio * 255.00;
  if(leftPulseCounter > rightPulseCounter)
  {
    enableMotors(150, pulseRatio);
  }
  else
  {
    enableMotors(pulseRatio, 150);
  }
}



void setup() 
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), interruptLeftMotor, RISING);
  attachInterrupt(digitalPinToInterrupt(3), interruptRightMotor, RISING);
  enableMotors(150, 150);
  forwardsMotion();
  delay(1000);
  hardStop();
  delay(200);
  ratioCalculation();
  forwardsMotion(); 
}

void loop() 
{
 

  if(leftPulseCounter > 900 && rightPulseCounter > 900)
  {
    hardStop();
    while(true);  
  }
  

}
