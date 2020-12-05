#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

char r;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("Saurabh ESP");
  Serial.println("The Device is ready to pair");
  pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  r = SerialBT.read();
  if(r =='1')
  {
    digitalWrite(5,'HIGH');
  }
  if(r=='0')
  {
    digitalWrite(5,LOW);
  }
  if (SerialBT.available()){
    Serial.write(r);
  }
  delay(20);
}
