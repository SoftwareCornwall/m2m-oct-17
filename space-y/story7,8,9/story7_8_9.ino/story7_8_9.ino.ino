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
  digitalWrite(leftMotorForward,HIGH );
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
void leftTurn()
{
  analogWrite(rightMotorForward, 155);
  analogWrite(leftMotorReverse, 155);
  delay(750);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorReverse, LOW);

}
void rightTurn()
{
  analogWrite(rightMotorReverse, 155);
  analogWrite(leftMotorForward, 155);
  delay(950);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorReverse, LOW);
}


void leftSquare() 
{
  for(int i = 1; i<= 3 ; i++)
  {
    forwardsMotion();
    delay(1000);
    hardStop();
    delay(500);
    leftTurn();
    hardStop();
    delay(500);
  }
  forwardsMotion();
  delay(860);
  hardStop();
  delay(500); 
}

void backwardsLeftSquare() 
{
  for(int i = 1; i<= 3 ; i++)
  {
    backwardsMotion();
    delay(1000);
    hardStop();
    delay(500);
    leftTurn();
    hardStop();
    delay(500);
  }
  backwardsMotion();
  delay(860);
  hardStop();
  delay(500); 
}

void backwardsRightSquare() 
{
  for(int i = 1; i<= 2 ; i++)
  {
    backwardsMotion();
    delay(1000);
    hardStop();
    delay(500);
    rightTurn();
    hardStop();
    delay(500);
  }
  backwardsMotion();
  delay(1300);
  hardStop();
  delay(500);
  rightTurn();
  hardStop();
  delay(500);
  backwardsMotion();
  delay(1150);
  hardStop();
  delay(500);
 
}


void rightSquare() 
{
  for(int i = 1; i<= 3 ; i++)
  {
    forwardsMotion();
    delay(1000);
    hardStop();
    delay(500);
    rightTurn();
    hardStop();
    delay(500);
  }
  forwardsMotion();
  delay(1200);
  hardStop();
  delay(500);
 
}

void setup() 
{
  enableMotors();
  Serial.begin(115200);
}

void loop() 
{
  rightSquare();
  leftSquare();
  delay(1000);
  backwardsLeftSquare();
  backwardsRightSquare();
  while(true);

}
