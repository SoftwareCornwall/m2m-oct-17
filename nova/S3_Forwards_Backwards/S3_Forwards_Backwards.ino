int left_enable = 9;
int left_forwards = 8;
int left_backwards = 7;
int right_enable = 10;
int right_forwards = 12;
int right_backwards = 1
1;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(left_enable, OUTPUT);
  pinMode(left_forwards, OUTPUT);
  pinMode(left_backwards, OUTPUT);
  pinMode(right_enable, OUTPUT);
  pinMode(right_forwards, OUTPUT);
  pinMode(right_backwards, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  forward();
  delay(10000);
  hardStop();
  delay(1000);
  backwards();
  delay(1000);
  hardStop();
  while (true);
}

void forward()
{
  digitalWrite(left_enable, HIGH);
  digitalWrite(right_enable, HIGH);
  digitalWrite(left_backwards, LOW);
  digitalWrite(right_backwards, LOW);
  digitalWrite(left_forwards, HIGH);
  digitalWrite(right_forwards, HIGH);
  
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

