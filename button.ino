int button=2;
int led=13;
int buttonState=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if(buttonState == HIGH) {
    digitalWrite(led,HIGH);
  }
  else if(buttonState == LOW) {
    digitalWrite(led,LOW);
  }
}
