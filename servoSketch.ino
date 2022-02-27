// Created by: Julian Rich
// Date: 26th Feb 2022
// Purpose: Used to wind an automatic watch while not in use. Simulates the movement of a human hand.
// Todo: Add RTC module to make the arduino run the movements while in work hours while no one is home, as servo is noisy.


#include <Servo.h>

int servoPin = 9;
int initialServoPosition = 0;
int currentPosition = initialServoPosition;
int pauseTime = 2000;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(initialServoPosition);
}

void loop() {
  changePosition(myServo.read(),'f');
  changePosition(myServo.read(),'b');
//    currentPosition += 45;
//    changePosition(myServo.read(),'f');
//    currentPosition = myServo.read();
//    if(currentPosition == 180){
//      changePosition(myServo.read(),'b');
//      changePosition(myServo.read(),'b');
//      changePosition(myServo.read(),'b');
//      changePosition(myServo.read(),'b');
//      currentPosition = myServo.read();
//    }
}

// Use b for backwards, f for forwards.
void changePosition(int currentPosition,char direction){
  int amountToMove = 180;// was 45
  if(direction == 'b'){
    myServo.write(currentPosition-amountToMove);
    Serial.println(myServo.read());
    delay(pauseTime);
  }
  else if(direction == 'f'){
    myServo.write(currentPosition+amountToMove);
    Serial.println(myServo.read());
    delay(pauseTime);
  }
}
