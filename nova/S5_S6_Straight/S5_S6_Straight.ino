volatile int left_count = 1; //left motor pulse
volatile int right_count = 1; //right motor pulse 
float ratio = 0;
int left_enable = 9;
int left_forwards = 8;
int left_backwards = 7;
int right_enable = 10;
int right_forwards = 12;
int right_backwards = 11;
int highSpeed = 120;

// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), leftInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightInterrupt, RISING);
  pinMode(left_enable, OUTPUT);
  pinMode(left_forwards, OUTPUT);
  pinMode(left_backwards, OUTPUT);
  pinMode(right_enable, OUTPUT);
  pinMode(right_forwards, OUTPUT);
  pinMode(right_backwards, OUTPUT);
}

void leftInterrupt()
{
  left_count++;
  Serial.print("left ");
  Serial.println(left_count);
}
void rightInterrupt()
{
  right_count++;
  Serial.print("right ");
  Serial.println(right_count);
}  
// the loop function runs over and over again forever

/* Not used
 *  
 *  
void noWig()
{
  if (right_count-left_count < 0)
  {
    while (left_count-right_count > 10)
    {
      analogWrite(left_forwards, 0);
      analogWrite(right_forwards, highSpeed); 
    }
  
  }
  if (left_count-right_count < 0)
  {
    while (right_count-left_count > 10)
    {
      analogWrite(right_forwards, 0);
      analogWrite(left_forwards, highSpeed);
    }
  }
  hardStop();
} 
*/

void time_forward(int delay_time)
{
  analogWrite(left_enable, highSpeed);
  analogWrite(right_enable, highSpeed);
  digitalWrite(left_backwards, LOW);
  digitalWrite(right_backwards, LOW);
  digitalWrite(left_forwards, HIGH);
  digitalWrite(right_forwards, HIGH);
  delay(delay_time*1000);
 //This is the defined instructions that are called when 'forwards' is used. 
}

void backwards()
{
  digitalWrite(left_enable, HIGH);
  digitalWrite(right_enable, HIGH);
  digitalWrite(left_forwards, LOW);
  digitalWrite(right_forwards, LOW); 
  digitalWrite(left_backwards, HIGH);
  digitalWrite(right_backwards, HIGH);
}

void hardStop()
{
  digitalWrite(left_enable, HIGH);
  digitalWrite(right_enable, HIGH);
  digitalWrite(left_backwards, HIGH);
  digitalWrite(right_backwards, HIGH);
  digitalWrite(left_forwards, HIGH);
  digitalWrite(right_forwards, HIGH);
  
}
void loop() 
{
  int left_speed, right_speed;
  time_forward(2);
  //find out which side is faster first
  if(left_count>right_count)
  {
    ratio = (float)right_count/(float)left_count;
    left_speed = highSpeed * ratio;
    right_speed = highSpeed;
  }
  else
  {
    ratio = (float)left_count/(float)right_count;
    right_speed = highSpeed * ratio;
    left_speed = highSpeed;
  }
  
  analogWrite(left_enable, left_speed);
  analogWrite(right_enable, right_speed);
  digitalWrite(left_backwards, LOW);
  digitalWrite(right_backwards, LOW);
  digitalWrite(left_forwards, HIGH);
  digitalWrite(right_forwards, HIGH);
  delay (2000);
  if(left_count>right_count)
  {
    ratio = (float)right_count/(float)left_count;
    left_speed = highSpeed * ratio;
    right_speed = highSpeed;
  }
  else
  {
    ratio = (float)left_count/(float)right_count;
    right_speed = highSpeed * ratio;
    left_speed = highSpeed;
  }
  analogWrite(left_enable, left_speed);
  analogWrite(right_enable, right_speed);
  digitalWrite(left_backwards, LOW);
  digitalWrite(right_backwards, LOW);
  digitalWrite(left_forwards, HIGH);
  digitalWrite(right_forwards, HIGH);
//  Serial.print("ratio ");
//  Serial.println(ratio);
  delay(6000);

  //noWig();

  
//  noWig();
//  analogWrite(left_forwards, left_speed);
//  analogWrite(right_forwards, right_speed);
//  delay(4000);
//  noWig();
  hardStop();
  while (true);
}
