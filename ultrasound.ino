const int trigPin=2;
const int echoPin=4;
const int buzzPin=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPin,INPUT);
  long duration=pulseIn(echoPin,HIGH);
  long inches=mtoi(duration);
//for buzzer part
  if(inches<5) 
    digitalWrite(buzzPin,HIGH);
  else 
    digitalWrite(buzzPin,LOW);
  
  long cm=mtoc(duration);

  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm ");
  delay(500);
}

long mtoi(long microseconds) {
  return microseconds/74/2;
}
long mtoc(long microseconds) {
  return microseconds/29/2;
}

