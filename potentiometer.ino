int sensorValue=0;
int outputValue=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
  outputValue=map(sensorValue,0,1023,0,255);
  analogWrite(9,outputValue);
  Serial.println(sensorValue);
  Serial.println(outputValue);
  delay(100);
}
