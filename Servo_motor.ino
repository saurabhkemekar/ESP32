#include <Servo.h>

Servo myservo; //servo object

int p = 0;  // Motor Position

void setup() {
  // put your setup code here, to run once:

  myservo.attach(2);  //Motor Pin

}

void loop() {
  // put your main code here, to run repeatedly:
  for( p =0 ; p<=180 ;p+=1)
  {
    myservo.write(p); //write Position
    delay(20);
  }
  for (p = 180; p>= 0; p-=1)
  {
    myservo.write(p); // Write Position
    delay(20);  //Delay
  }
  
  }
