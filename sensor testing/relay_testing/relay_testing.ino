void setup() {
  pinMode(5,OUTPUT);
}

void loop() {
  digitalWrite(5,HIGH);   // motor runs for one sec
  delay(2000); 
  digitalWrite(5,LOW);    // motor stops for one sec  
  delay(2000);
}
