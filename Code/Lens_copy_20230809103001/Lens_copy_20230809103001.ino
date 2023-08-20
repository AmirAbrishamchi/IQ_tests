
#include <stdio.h>
#include <Servo.h>
Servo servo1;
int servoPin = 9;
String teststr ="";
int pos = 0;    // variable to store the servo position
bool wipers = false;


enum State {open = 0, half = 90, closed = 180};
void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
  servo1.write(closed);
  delay(1000);
  servo1.write(half);
  delay(1000);
  servo1.write(open);
  delay(1000);
}

void loop() {
  Serial.println("Enter data:");
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  
  if (teststr == "open") {
    Serial.println("openning cover");
    servo1.write(0);
    delay(1000);
    
  } 
  else if(teststr == "close") {
    Serial.println("closing cover");
    servo1.write(closed);
    delay(1000);
  }
else if(teststr == "half") {
    Serial.println("setting to half open");
    servo1.write(half);
    delay(1000);
  }

}