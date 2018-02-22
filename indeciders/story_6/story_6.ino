int enableLeft = 9;
int redLeft = 8; 
int yellowLeft = 7;
int enableRight = 10;
int yellowRight = 12;
int redRight = 11;
int pulseCounter = 0;

volatile int leftCounter = 0, rightCounter = 0;

void leftMotorISR()
{
  leftCounter++;
  //Serial.println(leftCounter);
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
}

  
void forward() {
  analogWrite(enableRight, 0);
  analogWrite(enableLeft, 0);
  digitalWrite(redLeft, HIGH);  
  digitalWrite(yellowLeft, LOW);
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, LOW); 

  int error = abs(leftCounter - rightCounter);

  if(0 < error < 20){
    analogWrite(enableRight, 100);
    analogWrite(enableLeft, 100);
  }

  else{
    if(leftCounter > rightCounter) {
      while(error > 20) {
        analogWrite(enableRight, 100);
        analogWrite(enableLeft, 92);
      }
    }

    if(rightCounter > leftCounter) {
      while(error > 20) {
        analogWrite(enableLeft, 100);
        analogWrite(enableRight, 92);
      }
    }
  }
}



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

  while(leftCounter < 900)
    {
      forward();
      delay(1);
    }
      stoppeth();
      exit(0);
}

