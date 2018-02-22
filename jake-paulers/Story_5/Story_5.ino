const int LEFT_FORWARD = 8;
const int RIGHT_FORWARD = 12;
const int LEFT_REVERSE = 7;
const int RIGHT_REVERSE = 11 ;
const int LEFT_ENABLED = 9;
const int RIGHT_ENABLED = 10;
const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

int start_time = 0;
int current_time = 0;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

void Left_Motor_Forward()
{
   digitalWrite(LEFT_FORWARD, HIGH);
   analogWrite(LEFT_ENABLED, 255);
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
   digitalWrite(RIGHT_FORWARD, HIGH);
   analogWrite(RIGHT_ENABLED, 255);
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

void LeftMotorISR()
{
  // counts the pulses
  leftcounter++;
  Mainloop();
}

void RightMotorISR()
{
  // counts the pulses    
  rightcounter++;
  Mainloop();
}

void left_slow()
{
     analogWrite(LEFT_ENABLED, 0);
     digitalWrite(LEFT_REVERSE, LOW);
     digitalWrite(LEFT_FORWARD, HIGH);
}

void right_slow()
{
     analogWrite(RIGHT_ENABLED, 0);
     digitalWrite(RIGHT_REVERSE, LOW);
     digitalWrite(RIGHT_FORWARD, HIGH);
}

void timer()
{
    int current_time = millis();
  
    if (leftcounter >= 926 || rightcounter >= 926)

    {
     Both_Motors_Full_Stop();
     Serial.println("end");
      delay (500);
      exit(0);   
    }
}

void Mainloop() 
{  
  int difference = leftcounter-rightcounter;
  if(difference != 0)
  {
    
  }
  if (difference < 0)
  {
    right_slow();
    Serial.println("left stop");
    Serial.println(difference);
    timer();
    
  }
  else if (difference > 0)
    {
    
     left_slow();
     Serial.println("right stop");
     Serial.println(difference);

     timer();
  }
    Both_Motors_Forward(); 
    Serial.println("Forward");
    Serial.println(difference);
    timer();
}

/*void timer()
{
    int current_time = millis();
  
    if (leftcounter >= 960 || rightcounter >= 960);
    {
      Both_Motors_Full_Stop();
    
}
*/
void setup()
{
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHT_REVERSE, OUTPUT);
  pinMode(LEFT_ENABLED, OUTPUT);
  pinMode(RIGHT_ENABLED, OUTPUT);
  
  Serial.begin(115200);

  start_time = millis();

  
Both_Motors_Forward();
Serial.println("Main motors forward");
}

void loop()
{
//Both_Motors_Forward();
//Serial.println("Main motors forward");
timer();
}

