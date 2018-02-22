const int PIN14 = 14;
const int PIN15 = 15;

void setup()
{
pinMode(PIN14, OUTPUT);
pinMode(PIN15, OUTPUT);

}

void loop() 
{
digitalWrite(PIN15, HIGH);
delay(1000);
digitalWrite(PIN15, LOW);
delay(1000);

digitalWrite(PIN14, HIGH);
delay(1000);
digitalWrite(PIN14, LOW);
delay(1000);
}
