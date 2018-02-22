int left1 = 9;
int left2 = 8;
int left3 = 7;
int right1 = 10;
int right2 = 12;
int right3 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(left3, OUTPUT);
  
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(right3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(left1, HIGH);   // left 110, right 110 (forwards)
  digitalWrite(left2, HIGH);  
  digitalWrite(left3, LOW);  
  
  digitalWrite(right1, HIGH); 
  digitalWrite(right2, HIGH); 
  digitalWrite(right3, LOW); 
  delay(1000);                       // wait for 10 seconds

  digitalWrite(left1, HIGH);   // left 100, right 100 (stoppeth)
  digitalWrite(left2, LOW); 
  digitalWrite(left3, LOW);  
  
  digitalWrite(right1, HIGH); 
  digitalWrite(right2, LOW); 
  digitalWrite(right3, LOW);
  delay(1000);

  digitalWrite(left1, HIGH);   // left 101, right 101 (backwarth)
  digitalWrite(left2, LOW);  
  digitalWrite(left3, HIGH);  
  
  digitalWrite(right1, HIGH); 
  digitalWrite(right2, LOW); 
  digitalWrite(right3, HIGH);
  delay(1000);

  digitalWrite(left1, HIGH);   // left 100, right 100 (stoppeth)
  digitalWrite(left2, LOW);  
  digitalWrite(left3, LOW);  
  
  digitalWrite(right1, HIGH); 
  digitalWrite(right2, LOW); 
  digitalWrite(right3, LOW);
  delay(1000);   
}
