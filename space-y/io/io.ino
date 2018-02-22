
const int leftMotorReverse = 7; //Red
const int leftMotorForward = 8; //Yellow
const int leftMotorEnable = 9; //Blue
const int rightMotorReverse = 11; //Red
const int rightMotorForward = 12; //Yellow
const int rightMotorEnable = 10; //Blue

void setup() 
{
  
}

void loop() 
{
//Enable Motors
  digitalWrite(leftMotorEnable, HIGH);
  digitalWrite(rightMotorEnable, HIGH);
  
  //Enable Forward
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  delay(10000);
  
  //Stop Motors  
  digitalWrite(leftMotorReverse, HIGH);
  digitalWrite(rightMotorReverse, HIGH);
  delay(1000);
  
  //Enable Backwards
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  delay(1000);

  //Stop Motors
  digitalWrite(leftMotorReverse, LOW);
  digitalWrite(rightMotorReverse, LOW);

  //Disable Motors
  digitalWrite(leftMotorEnable, LOW);
  digitalWrite(rightMotorEnable, LOW);
  while(+
  true);
}
