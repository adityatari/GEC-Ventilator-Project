#include <Wire.h>
#define SLAVE_ADDR 0x2E
#define ANSWERSIZE 18


void setup() {
 
  Wire.begin(); 
  Serial.begin(9600);
  delay(100);
  Wire.beginTransmission(SLAVE_ADDR);
  delay(100);
  Wire.write(0x3FF9);
  Wire.endTransmission();
  delay(100);
  Serial.println("Connected");
}
void loop()
{

  Wire.requestFrom(SLAVE_ADDR,ANSWERSIZE); 
  
  Wire.write(0xE102);
  byte a[18];
  int i;
  if(Wire.available()>=ANSWERSIZE) { 
  for(i=0;i<18;i++){
    a[i]=Wire.read();
    Serial.print(a[i], BIN);
    Serial.print("  ");
  }
  }
  delay(2000);
  
}
