int left1 = 9;
int left2 = 8;
int left3 = 7;
int right1 = 10;
int right2 = 12;
int right3 = 11;


volatile int leftCounter = 0, rightCounter = 0;

void LeftMotorISR()
{
  leftCounter++;
}

void RightMotorISR()
{
  rightCounter++;
}

void setup() {
  // put your setup code here, to run once:
attachInterrupt(digitalPinToInterrupt(2), LeftMotorISR, RISING);
attachInterrupt(digitalPinToInterrupt(3), RightMotorISR, RISING);
}
void forward() {
  digitalWrite(left1, HIGH);   // left 110, right 110 (forwards)
  digitalWrite(left2, HIGH);  
  digitalWrite(left3, LOW); 
  
  digitalWrite(right1, HIGH); 
  digitalWrite(right2, HIGH); 
  digitalWrite(right3, LOW); 
  delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
}
// analogueWrite - on Enable. Change High/Low between 90-250. Rename Variables

