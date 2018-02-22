const int lightLeftPin = 7;
const int lightMiddlePin = 6;
const int lightRightPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(lightLeftPin, INPUT);
  pinMode(lightMiddlePin, INPUT);
  pinMode(lightRightPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightLeft = analogRead(lightLeftPin);
  int lightMiddle = analogRead(lightMiddlePin);
  int lightRight = analogRead(lightRightPin);
  int total = lightLeft + lightMiddle + lightRight;
  /*Serial.print("Left: ");
  Serial.println(lightLeft);
  Serial.print("Middle: ");
  Serial.println(lightMiddle);
  Serial.print("Right: ");
  Serial.println(lightRight);*/
  Serial.println(total);
  delay(500);
}
