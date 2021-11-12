int LDRValue=0;
int lightSensitivity=300;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  LDRValue=analogRead(A0);
  Serial.println(LDRValue);
  delay(50);

  if(LDRValue>lightSensitivity) {
    digitalWrite(11,LOW);
  }
  else {
    digitalWrite(11,HIGH);
  }
}
