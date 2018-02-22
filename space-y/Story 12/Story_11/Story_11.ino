#include <NewPing.h>    //Including the NewPing.h header file for the sensor pin

const int triggerPin = 4;     //Forward Sonar Trigger Pin
const int echoPin = 5;        //Forward Sonar Echo Pin
const int maxDistance = 200;  //Forward Sonar Maximum Distance

const int triggerPinDown = 13;    //Downward Sonar Trigger Pin
const int echoPinDown = 17;       //Downward Sonar Trigger Pin
const int maxDistanceDown = 200;  //Downward Sonar Maximum Distance

#define leftLightSensor A7      //Left Light Sensor Pin
#define middleLightSensor A6    //Middle Light Sensor Pin
#define rightLightSensor A2     //Right Light Sensor Pin

int leftSensorValue = 0;    //Value read from LEFT sensor pin
int middleSensorValue = 0;  //Value read from MIDDLE sensor pin
int rightSensorValue = 0;   //Value read from RIGHT sensor pin


NewPing forwardSonar(triggerPin,echoPin,maxDistance); //Foward sensor 'NewPing' 
NewPing downwardSonar(triggerPinDown, echoPinDown,maxDistanceDown);

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
void leftTurn(int turnTime)
{
  analogWrite(rightMotorForward, 155);
  analogWrite(leftMotorReverse, 155);
  delay(turnTime);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorReverse, LOW);

}
void rightTurn(int turnTime)
{
  analogWrite(rightMotorReverse, 155);
  analogWrite(leftMotorForward, 155);
  delay(turnTime);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorReverse, LOW);
}


/*void leftSquare() 
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
*/
int checkLightDirection(int ls, int ms, int rs) 
{
  if(ls < ms)
  {
    return 1; //1 = left turn

  }
  else if(rs < ms)
  {
    return 2; // 2 = right turn
  }
  else if(ms < ls && ms < rs)
  {
    return 3; // 3 = forwards direction
  }
  else
  {
    return 4; //turns 180
  }
}


void setup() 
{
  
  Serial.begin(115200);
  enableMotors();
  
}

void loop() 
{
  delay(50);
  int ls = analogRead(leftLightSensor);
  int ms = analogRead(middleLightSensor);
  int rs = analogRead(rightLightSensor);
  Serial.println(ls);
  Serial.println(ms);
  Serial.println(rs);
  
  int instruction = checkLightDirection(ls, ms, rs);
  
  if(instruction == 1)
  {
    leftTurn(50);
    Serial.println("Turning left");
  }
  else if(instruction == 2)
  {
    rightTurn(50);
    Serial.println("Turning right");
  }
  else if(instruction == 3)
  {
    forwardsMotion();
    Serial.println("Moving forwards");
  }
  else
  {
    leftTurn(1600);
    Serial.println("Turning 180");
  }

    
 
  
}
