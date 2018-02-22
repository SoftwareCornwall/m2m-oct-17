int led1 = 15;
int led2 = 14;

void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}
  // put your main code here, to run repeatedly:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

