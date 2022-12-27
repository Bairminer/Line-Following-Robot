//Libraries
#include <Servo.h>
//defining pins and variables
#define leftsensor A4 
#define rightsensor A5 

//defining motors
Servo rightservo;
Servo leftservo;

//Sensitivity
int sensitivity = 400;

void setup() {
  pinMode(leftsensor,INPUT);
  pinMode(rightsensor,INPUT);
  rightservo.attach(9);
  leftservo.attach(10);
}

void loop(){
  if(analogRead(leftsensor)<=sensitivity && analogRead(rightsensor)<=sensitivity){
    //stop
    rightservo.write(0);
    leftservo.write(180);
  }
  //line detected by left sensor
  else if(analogRead(leftsensor)<=sensitivity && !analogRead(rightsensor)<=sensitivity){
    //turn left
    rightservo.write(180);
    leftservo.write(180);
  }
  //line detected by right sensor
  else if(!analogRead(leftsensor)<=sensitivity && analogRead(rightsensor)<=sensitivity){
    //turn right
    rightservo.write(0);
    leftservo.write(0);
  }
  //line detected by none
  else if(!analogRead(leftsensor)<=sensitivity && !analogRead(rightsensor)<=sensitivity){
    //stop
    rightservo.write(0);
    leftservo.write(180);
  }
}
