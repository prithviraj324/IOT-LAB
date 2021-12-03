#include<SoftwareSerial.h>
//#include<NewPing.h>
int sensorPin=A0;
int sensorVal=0;
int led=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal=analogRead(sensorPin);
  Serial.println(sensorVal);
  if(sensorVal<500)
  {
    Serial.println("Fire Detected");
    digitalWrite(led,HIGH);
    delay(1000);
  }
  digitalWrite(led,LOW);
  delay(sensorVal);

}
