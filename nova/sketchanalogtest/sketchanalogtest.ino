volatile int leftCount = 1; //left motor pulse
volatile int rightCount = 1; //right motor pulse 
float ratio = 0;
int leftEnable = 9;
int leftForwards = 8;
int leftBackwards = 7;
int rightEnable = 10;
int rightForwards = 12;
int rightBackwards = 11;
int highSpeed = 170;

void leftInterrupt()
{
  leftCount++;
  Serial.print("left ");
  Serial.println(leftCount);
}
void rightInterrupt()
{
  rightCount++;
  Serial.print("right ");
  Serial.println(rightCount);
}  

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), leftInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightInterrupt, RISING);
  pinMode(leftEnable, OUTPUT);
  pinMode(leftForwards, OUTPUT);
  pinMode(leftBackwards, OUTPUT);
  pinMode(leftEnable, OUTPUT);
  pinMode(rightForwards, OUTPUT);
  pinMode(rightBackwards, OUTPUT);
}

void loop() {
  for (int x=0; x<256; x++) {
     analogWrite(leftEnable, x);
      analogWrite(rightEnable, x);
      delay(1);
  }
  /*
  analogWrite(leftEnable, 0);
  analogWrite(rightEnable, 255);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, HIGH);
  delay(2000);
  digitalWrite(leftForwards, LOW);
  digitalWrite(rightForwards, LOW);
  delay(2000);
  digitalWrite(leftForwards, HIGH);
  digitalWrite(rightForwards, LOW);
  delay(2000);
  digitalWrite(leftForwards, LOW);
  digitalWrite(rightForwards, HIGH);
  while(true);*/

}
