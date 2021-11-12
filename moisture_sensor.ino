int dpin0=5;
int apin0=1;
int apinval;
void setup() {
  // put your setup code here, to run once:
  pinMode(dpin0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("D0 value");
  Serial.println(digitalRead(dpin0));
  Serial.print("A0 value");
  apinval=analogRead(apin0);
  Serial.println(apinval);
  delay(1000);
}
