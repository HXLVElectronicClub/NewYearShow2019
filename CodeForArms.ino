#include <Servo.h>
Servo neckServo;
Servo shoulderServo;
Servo armServo;
Servo wristServo;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int aK_pin = 7;  
int neckangle = 73;
int shoulderangle = 124;
int armangle = 146;
int wristangle = 100;
int servo1angle = 90;
int servo2angle = 170;
int servo3angle = 45;
int servo4angle = 45;
int delaytime = 720;

void setup() {

  // put your setup code here, to run once:

  neckServo.attach(11);
  shoulderServo.attach(6);
  armServo.attach(10);
  wristServo.attach(9);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo3.write(45);
  servo4.write(45);
  pinMode(aK_pin, INPUT);
  digitalWrite(aK_pin, HIGH);
  Serial.begin(9600);
 
  while(1){
    if(digitalRead(aK_pin)==LOW)break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //111111111111111111111111111111
  neckServo.write(73);
  shoulderServo.write(124);
  armServo.write(146);
  wristServo.write(100);/**/
  servo1.write(90);
  servo2.write(170);/**/
  delay(delaytime);
  //22222222222222222222222222222
 neckServo.write(114);
  shoulderServo.write(81);
  armServo.write(74);
  wristServo.write(65);/**/
   servo1.write(135);
  servo2.write(90);/**/
  delay(delaytime);
  //33333333333333333333333333333
 neckServo.write(21);
  shoulderServo.write(83);
  armServo.write(74);
  wristServo.write(65);/**/
  servo1.write(180);
  servo2.write(170);/**/
  delay(delaytime);
  //44444444444444444444444444444
neckServo.write(109);
  shoulderServo.write(132);
  armServo.write(85);
  wristServo.write(71);/**/
   servo1.write(135);
  servo2.write(90);/**/
  delay(delaytime);
}  
