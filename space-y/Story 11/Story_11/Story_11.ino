#include <NewPing.h>

const int triggerPin = 4;  
const int echoPin = 5;
const int maxDistance = 200; 

const int triggerPinDown = 13;
const int echoPinDown = 17;
const int maxDistanceDown = 200;


NewPing sonar(triggerPin,echoPin,maxDistance);
NewPing sonar2(triggerPinDown, echoPinDown,maxDistanceDown);
//declare variables
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
void enableMotors() //enable motors function
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
void forwardsMotion() //forwards motion function
{
  //Enable Forward
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void backwardsMotion() //backwards motion function
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
void leftTurn() //left turn function
{
  analogWrite(rightMotorForward, 155);
  analogWrite(leftMotorReverse, 155);
  delay(800);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorReverse, LOW);

}
void rightTurn() //right turn function
{
  analogWrite(rightMotorReverse, 155);
  analogWrite(leftMotorForward, 155);
  delay(950);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorReverse, LOW);
}


void leftSquare() //left square sequence
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

void backwardsLeftSquare()  // backwards left square sequence
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

void backwardsRightSquare() //backwards iright square sequence
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


void rightSquare() //Our Right square sequence
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
  forwardsMotion();
}

void loop() 
{
  delay(50);
  int distance = sonar2.ping_cm();
  if(distance>=17)
  {
    Serial.println(sonar2.ping_cm());
    Serial.println("I am more than dieing");
    hardStop();
    delay(100);
    backwardsMotion();
    delay(3000);
    hardStop();
    delay(100);
    leftTurn();
    forwardsMotion();
    delay(3000);
    hardStop();
    while(true);
    
  }
  
}
