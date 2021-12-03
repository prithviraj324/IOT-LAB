int calibTime=30;
long unsigned int lowIn;
long unsigned int pause=500;
boolean lockLow=true;
boolean takeLowTime;
int pirPin=3;
int buzzPin=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  digitalWrite(pirPin,LOW);
  Serial.print("Calibrating Sensor");

  for(int i=0;i<calibTime;i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Done");
  Serial.println("Sensor active");
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pirPin)==HIGH) {
    digitalWrite(buzzPin,HIGH);
    if(lockLow) {
      lockLow=false;
      Serial.println("--");
      Serial.print("motion detected at");
      Serial.print(millis()/1000);
      Serial.println("sec");
      delay(50);
    }
    takeLowTime=true;
  }
  if(digitalRead(pirPin)==LOW) {
    digitalWrite(buzzPin,LOW);
    if(takeLowTime) {
      lowIn=millis();
      takeLowTime=false;
    }
    if(!lockLow && millis()-lowIn>pause) {
      lockLow=true;
      Serial.print("Motion ended at ");
      Serial.print((millis()-pause)/1000);
      Serial.println("sec");
      delay(50);
    }
  }
}
