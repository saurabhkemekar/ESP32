#include "WiFi.h"
const char* ssid = "ESP32-wifi";
const char* password = "abcdefgh";

WiFiServer server(80);
String html = "<!DOCTYPE html> \
<html> \
<body> \
<form> \
<button name = \"LED\" button value =\"ON\" type = \"submit\"> LED ON</button> \
<button name = \"LED\" button value =\"OFF\" type = \"submit\"> LED OFF</button> \
</form> \
</body> \
</html> \
";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  WiFi.softAP(ssid,password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access point IP address");
  Serial.println(IP);
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(client)
  {
    String request = client.readStringUntil('\r');
    if(request.indexOf("LED=ON")>=0)digitalWrite(5,HIGH);
    if(request.indexOf("LED=OFF")>=0)digitalWrite(5,LOW);
    client.print(html);
    request="";
  }
}
