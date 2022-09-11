// C++ code
#include <Servo.h>

const int led_left = 9;
const int res_left = 10;

const int led_right = 3;
const int res_right = 5;

Servo leftServo;
Servo rightServo;

void setup()
{
  Serial.begin(9600);
  pinMode(led_left,OUTPUT);
  pinMode(res_left,INPUT);
  pinMode(led_right,OUTPUT);
  pinMode(res_right,INPUT);
 
  leftServo.attach(13);
  rightServo.attach(12);
}

void loop()
{
  /*
  write(1300) --> clockwise at full speed
  write(1400) --> clockwise at half speed
  write(1500) --> stop
  write(1600) --> anticlockwise at half speed
  write(1700) --> anticlockwise at full speed
  */
 
  //Moving Forware for 3 sec
  //Left clockwise -- Right anticlockwise
 
  tone(led_left, 38000, 58);
  delay(1);                         // Wait 1 ms
  int l = digitalRead(res_left);
  Serial.println(l);

  delay (100);
 
  tone(led_right, 38000, 58);
  delay(1);                         // Wait 1 ms
  int r = digitalRead(res_right);
  Serial.println(r);
 
  if (l == 1 && r == 0) {
    //Turn Left
    //All clockwise
    Serial.println("trun left");
    leftServo.writeMicroseconds(1400);
    rightServo.writeMicroseconds(1400);
    delay(1000);
  }
  if (l == 0 && r == 1) {
    //Turn Right
    //All anticlockwise
    Serial.println("trun right");
    leftServo.writeMicroseconds(1600);
    rightServo.writeMicroseconds(1600);
    delay(600);
  }
 
  if (l == 0 && r == 0) {
    //Reverse for 3 sec
    Serial.println("return");
    leftServo.writeMicroseconds(1400);
    rightServo.writeMicroseconds(1600);
    delay(1000);
  }
 
  Serial.println("go ahead ");
  leftServo.writeMicroseconds(1400);
  rightServo.writeMicroseconds(1600);
  delay(1000);

}
