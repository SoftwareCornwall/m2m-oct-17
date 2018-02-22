int greenLeft = 9;
int redLeft = 8;
int yellowLeft = 7;
int greenRight = 10;
int yellowRight = 12;
int redRight = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(greenLeft, OUTPUT);
  pinMode(redLeft, OUTPUT);
  pinMode(yellowLeft, OUTPUT);
  
  pinMode(greenRight, OUTPUT);
  pinMode(yellowRight, OUTPUT);
  pinMode(redRight, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLeft, HIGH);   // left 110, right 110 (forwards)
  digitalWrite(redLeft, HIGH);  
  digitalWrite(yellowLeft, LOW); 
  
  digitalWrite(greenRight, HIGH); 
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, LOW);  
  delay(1000);                       // wait for 10 seconds

  digitalWrite(greenLeft, HIGH);   // left 100, right 100 (stoppeth)
  digitalWrite(redLeft, LOW); 
  digitalWrite(yellowLeft, LOW);  
  
  digitalWrite(greenRight, HIGH); 
  digitalWrite(yellowRight, LOW); 
  digitalWrite(redRight, LOW);
  delay(1000);

  digitalWrite(greenLeft, HIGH);   // left 101, right 101 (backwarth)
  digitalWrite(redLeft, LOW);  
  digitalWrite(yellowLeft, HIGH);  
  
  digitalWrite(greenRight, HIGH); 
  digitalWrite(yellowRight, LOW); 
  digitalWrite(redRight, HIGH);
  delay(1000);

  digitalWrite(greenLeft, HIGH);   // left 100, right 100 (stoppeth)
  digitalWrite(redLeft, LOW);  
  digitalWrite(yellowLeft, LOW);  
  
  digitalWrite(greenRight, HIGH); 
  digitalWrite(yellowRight, LOW); 
  digitalWrite(redRight, LOW);
  delay(1000);   
}
