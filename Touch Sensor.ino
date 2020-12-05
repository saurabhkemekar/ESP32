int v;
void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  v = touchRead(4);
  Serial.println(v);
  if(v<80)
    digitalWrite(5,HIGH);
  else
    digitalWrite(5,LOW);
}
