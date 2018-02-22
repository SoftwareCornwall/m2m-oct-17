int enableLeft = 9;
int redLeft = 8; 
int yellowLeft = 7;
int enableRight = 10;
int yellowRight = 12;
int redRight = 11;

volatile int leftCounter = 0, rightCounter = 0;

int timeCounter = 0;

void leftMotorISR()
{
  leftCounter++;
  //Serial.println(leftCounter);
}

void rightMotorISR()
{
  rightCounter++;
  //Serial.println(rightCounter);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(enableLeft, OUTPUT);
  pinMode(redLeft, OUTPUT);
  pinMode(yellowLeft, OUTPUT);
  
  pinMode(enableRight, OUTPUT);
  pinMode(yellowRight, OUTPUT);
  pinMode(redRight, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightMotorISR, RISING);

  //Serial.begin(115200);
}
void leftForward() {
  analogWrite(enableLeft, 100);   // left 110, right 110 (forwards)
  //digitalWrite(greenLeft, HIGH);
  digitalWrite(redLeft, HIGH);  
  digitalWrite(yellowLeft, LOW); 
//  Serial.println("Left motor on");
}

void rightForward() {
  analogWrite(enableRight, 100); 
  //digitalWrite(greenRight, HIGH);
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, LOW); 
//  Serial.println("Right motor on");
}


void forward() {
  analogWrite(enableRight, 0);
  analogWrite(enableLeft, 0);
  digitalWrite(redLeft, HIGH);  
  digitalWrite(yellowLeft, LOW);
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, LOW); 

   
  if(leftCounter==rightCounter){
     analogWrite(enableRight, 100);
     analogWrite(enableLeft, 100);
  }

  if(leftCounter>rightCounter){
     analogWrite(enableRight, 100);
     analogWrite(enableLeft, 0);
  }

  if(rightCounter>leftCounter){
     analogWrite(enableLeft, 100);
     analogWrite(enableRight, 0);
  }
  
//  rightForward();
//  leftForward();
//  
//  while(leftCounter > rightCounter) {
//    //Serial.println(leftCounter);
//    //Serial.println(rightCounter);
//    stoppeth();
//    rightForward();
//    //Serial.println("stop left motor");
//  }
//  
//  while(rightCounter > leftCounter) {
//    //Serial.println(leftCounter);
//    //Serial.println(rightCounter);
//    stoppeth();
//    //Serial.println("stop right motor");
//    leftForward();
//  }
}
/*void stoppeth(){
  digitalWrite(greenLeft, HIGH);   // left 100, right 100 (stoppeth)
  digitalWrite(redLeft, LOW); 
  digitalWrite(yellowLeft, LOW);  
  
  digitalWrite(greenRight, HIGH); 
  digitalWrite(yellowRight, LOW); 
  digitalWrite(redRight, LOW);
  
 } */

 void stoppeth(){
  digitalWrite(enableLeft, HIGH);   // left 111, right 111 (stoppeth)
  digitalWrite(redLeft, HIGH); 
  digitalWrite(yellowLeft, HIGH);  
  
  digitalWrite(enableRight, HIGH); 
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, HIGH);
  
 }
void loop() {
  // put your main code here, to run repeatedly: 
  while(timeCounter < 10000)
    {
      forward();
      timeCounter++;
      delay(1);
    }
      stoppeth();
}
// analogueWrite - on Enable. Change High/Low between 90-255. Rename Variables

