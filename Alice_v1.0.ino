//#include <AliceBody.h>
//#include <AliceHead.h>
#include <Servo.h>
#include "AliceBody.h"
#include "AliceHead.h"
// lcd
#define lcd_pin1 8
#define lcd_pin2 7
#define lcd_pin3 6
#define lcd_pin4 5
#define lcd_pin5 4
#define lcd_pin6 3
#define lcd_pin7 2
// HC-SR501 
#define motion_pin 24
// L298
#define Motor1_Enb 53
#define Motor1_R 52
#define Motor1_B 51

#define Motor2_R 50
#define Motor2_B 49
#define Motor2_Enb 48
// Ultera Sonic srf04
#define trigger_pin 23
#define echo_pin 22
// hand 
#define left_arm_pin 11
#define right_arm_pin 38
#define left_wrist_pin 12
#define right_wrist_pin 39


void Controller(int motion);


Eye eye(trigger_pin,echo_pin);
Mouth mouth(lcd_pin1,lcd_pin2,lcd_pin3,lcd_pin4,lcd_pin5,lcd_pin6,lcd_pin7);
Wheels wheel(Motor1_Enb,Motor1_R,Motor1_B,Motor2_Enb,Motor2_R,Motor2_B);
Hands hand(left_arm_pin,right_arm_pin,left_wrist_pin,right_wrist_pin);

void setup() {
//  Serial.begin(9600);
  pinMode(25,OUTPUT);
//  pinMode(24,OUTPUT);
  
//  digitalWrite(25, HIGH);
//  digitalWrite(24, HIGH);
  mouth.smiley_face();
  setup_motion(motion_pin);
}

void loop() 
{
  // check motion 1 or 0 
  Controller(check_motion(motion_pin));
}

void Controller(int motion)
{
  if (motion == 1)
  {
    
    if (eye.distance(10) == 1 ){
      wheel.move('b',1000);
    }
    wheel.move('f',1000);
  }
  else
  {
  hand.hand_move('l',60);
  delay(500);
    int rand = random(1,10);
    switch (rand) 
      {
        case 1:
          wheel.move('b',1000);
          break;
        case 2:
          wheel.move('f',1000);
          break;
        case 3:
          hand.hand_move('r',120);
          delay(500);
          hand.wrist_move('r', 60);
          break;
        case 4:
          hand.hand_move('l',120);
          delay(500);
          hand.wrist_move('l', 60);
          break;
        case 5:
        wheel.rotate('l',1000);
          break;
        case 6:
        wheel.rotate('l',1000);
          break;
       case 7:
        wheel.rotate('r',1000);
          break;
        case 8:
        wheel.rotate('r',1000);
          break; 
        case 9:
        wheel.rotate('r',1000);
          break; 
        case 10:
        wheel.rotate('r',1000);
          break;                  
        default:
          break;
      }

  }
}
  
