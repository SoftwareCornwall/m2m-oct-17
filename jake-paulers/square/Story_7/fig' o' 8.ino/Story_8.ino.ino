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
  analogWrite(LEFT_ENABLED, 150);
  digitalWrite(LEFT_REVERSE, LOW);
}

void Left_Motor_Reverse()
{
  analogWrite(LEFT_ENABLED, 150);
  analogWrite(LEFT_REVERSE, 255);
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
  analogWrite(RIGHT_FORWARD, 255);
  analogWrite(RIGHT_ENABLED, 150);
  digitalWrite(RIGHT_REVERSE, LOW);
}

void Right_Motor_Reverse()
{
  analogWrite(RIGHT_ENABLED, 150);
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

void Right_Turn()
{
  Left_Motor_Forward();
  Right_Motor_Reverse();
  Serial.println(leftcounter);
  Serial.println(rightcounter);
  delay(900);
  if (leftcounter >= 32 || rightcounter >= 32);
  {
    Serial.println("Right turn");
    Left_Motor_Full_Stop();
    Right_Motor_Full_Stop();
  }
}

void Left_Turn()
{
  Left_Motor_Reverse();
  Right_Motor_Forward();
  Serial.println(leftcounter);
  Serial.println(rightcounter);
  delay(900);
  if (leftcounter >= 32 || rightcounter >= 32);
  {
    Serial.println("Left turn");
    Left_Motor_Full_Stop();
    Right_Motor_Full_Stop();
  }
}

void Straight_Line()
{
  Left_Motor_Forward();
  Right_Motor_Forward();
  Serial.println(leftcounter);
  Serial.println(rightcounter);
  delay(500);
  if (leftcounter >= 150 || rightcounter >= 150)
  {
    Serial.println("Straight Line");
    Left_Motor_Full_Stop();
    Right_Motor_Full_Stop();
  }
}

void LeftMotorISR()
{
  // counts the pulses
  leftcounter++;
  //Mainloop();
}

void RightMotorISR()
{
  // counts the pulses
  rightcounter++;
  //Mainloop();
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

  if (leftcounter >= 111926 || rightcounter >= 111926)

  {
    Both_Motors_Full_Stop();
    Serial.println("end");
    delay (500);
    exit(0);
  }
}


void setup()
{
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);

  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHT_REVERSE, OUTPUT);
  pinMode(LEFT_ENABLED, OUTPUT);
  pinMode(RIGHT_ENABLED, OUTPUT);

  Serial.begin(115200);

  start_time = millis();
  
}

void loop()
{

  //for (int i=0; i <= 3; i++)
  {
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
    
    Right_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
    
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
    
    Right_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
    
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Right_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
  
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Right_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Left_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Left_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Left_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Left_Turn();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);

    Straight_Line();
    leftcounter = 0;
    rightcounter = 0;
    
    delay(2000);
    
    exit(0);
 }
 //# exit(0);
}

