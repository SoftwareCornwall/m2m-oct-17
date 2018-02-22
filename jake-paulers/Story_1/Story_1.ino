void setup()
{
pinMode(PIN3, OUTPUT);


}

void loop() 
{
digitalWrite(PIN3, HIGH);
delay(1000);
digitalWrite(PIN3, LOW);
delay(1000);

digitalWrite(PIN2, HIGH);
delay(1000);
digitalWrite(PIN2, LOW);
delay(1000);
}
