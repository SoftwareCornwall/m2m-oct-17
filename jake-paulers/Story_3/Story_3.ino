const int LEFT_FORWARD = 8;
const int RIGHT_FORWARD = 12;
const int LEFT_REVERSE = 7;
const int RIGHT_REVERSE = 11 ;
const int LEFT_ENABLED = 9;
const int RIGHT_ENABLED = 10;

void Left_Motor_Forward()
{
   digitalWrite(LEFT_ENABLED, HIGH);
   digitalWrite(LEFT_FORWARD, HIGH);
   digitalWrite(LEFT_REVERSE, LOW);
}

void Left_Motor_Reverse()
{
   digitalWrite(LEFT_ENABLED, HIGH);
   digitalWrite(LEFT_REVERSE, HIGH);
   digitalWrite(LEFT_FORWARD, LOW);
}

void Left_Motor_Full_Stop()
{
   digitalWrite(LEFT_ENABLED, HIGH);
   digitalWrite(LEFT_REVERSE, HIGH);
   digitalWrite(LEFT_FORWARD, HIGH);
}

void Right_Motor_Forward()
{
   digitalWrite(RIGHT_ENABLED, HIGH);
   digitalWrite(RIGHT_FORWARD, HIGH);
   digitalWrite(RIGHT_REVERSE, LOW);
}

void Right_Motor_Reverse()
{
   digitalWrite(RIGHT_ENABLED, HIGH);
   digitalWrite(RIGHT_REVERSE, HIGH);
   digitalWrite(RIGHT_FORWARD, LOW);
}

void Right_Motor_Full_Stop()
{
   digitalWrite(RIGHT_ENABLED, HIGH);
   digitalWrite(RIGHT_REVERSE, HIGH);
   digitalWrite(RIGHT_FORWARD, HIGH);
}

void Both_Motors_Full_Stop()
{ 
  Left_Motor_Full_Stop();
  Right_Motor_Full_Stop();
}

void Both_Motors_Forward()
{
  Left_Motor_Forward();
  Right_Motor_Forward();  
}

void Both_Motors_Reverse()
{
  Left_Motor_Reverse();
  Right_Motor_Reverse();
}

void setup()
{
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHT_REVERSE, OUTPUT);
  pinMode(LEFT_ENABLED, OUTPUT);
  pinMode(RIGHT_ENABLED, OUTPUT);

  Both_Motors_Forward();
  delay(10000);
  Both_Motors_Full_Stop();
  delay(1000);
  Both_Motors_Reverse();
  delay(1000);
  Both_Motors_Full_Stop();
  delay(1000);
}
  

void loop() 
{

}
