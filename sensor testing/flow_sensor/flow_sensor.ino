#include <Wire.h>
#define SLAVE_ADDR 0x2E
#define ANSWERSIZE 9


void setup() {
 
  Wire.begin(); 
  Serial.begin(9600);
  delay(100);
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0x0006);
  delay(100);
  Wire.write(0x3608);
  Wire.endTransmission();
  delay(100);
  Serial.println("Connected");
}
void loop()
{

  Wire.requestFrom(SLAVE_ADDR,ANSWERSIZE); 
  byte X[9];
  int i;
  if(Wire.available()>ANSWERSIZE) {  
    for(i=0;i<9;i++){
     X[i] = Wire.read(); 
    }
  }
  Serial.print("Flow 8msb = ");
  Serial.print(X[0], BIN);
  Serial.print("   Flow 8lsb= ");
  Serial.print(X[1], BIN);
  Serial.print("   CRC= ");
  Serial.print(X[2], BIN);
  Serial.print("   Temp 8msb= ");
  Serial.print(X[3], BIN);
  Serial.print("   Temp 8lsb = ");
  Serial.print(X[4], BIN);
  Serial.print("   CRC= ");
  Serial.print(X[5], BIN);
  Serial.print("   Status Word 8msb= ");
  Serial.print(X[6], BIN);
  Serial.print("   Status Word 8lsb= ");
  Serial.print(X[7], BIN);
  Serial.print("   CRC = ");
  Serial.println(X[8], BIN);
  int flow, temp, statusWord;
  flow=(X[0]<<8)|X[1];
  temp=(X[3]<<8)|X[4];
  statusWord=(X[7]<<8)|X[8];
  Serial.print("flow: ");
  Serial.print(flow);
  Serial.print("  temp: ");
  Serial.print(temp);

  Serial.print("  Status Word: ");
  Serial.println(statusWord);
  delay(5000);
}
