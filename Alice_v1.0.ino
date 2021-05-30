//#include <AliceBody.h>
//#include <AliceHead.h>
#include "AliceBody.h"
#include "AliceHead.h"
// lcd
#define lcd_pin1 1
#define lcd_pin2 1
#define lcd_pin3 1
#define lcd_pin4 1
#define lcd_pin5 1
#define lcd_pin6 1
#define lcd_pin7 1
// red 
#define motion_pin 9
// L298
#define Motor1_Enb 3
#define Motor1_R 2
#define Motor1_B 4

#define Motor2_R 5
#define Motor2_B 7
#define Motor2_Enb 6
// Ultera Sonic srf04
#define trigger_pin 1
#define echo_pin 2
// hand 
#define left_arm_pin 1
#define right_arm_pin 1
#define left_wrist_pin 1
#define right_wrist_pin 1

int dis_state=0;
int motion_state=0;
void Controller(int motion);

Eye eye(trigger_pin,echo_pin);
Mouth mouth(lcd_pin1,lcd_pin2,lcd_pin3,lcd_pin4,lcd_pin5,lcd_pin6,lcd_pin7);
Wheels wheel(Motor1_Enb,Motor1_R,Motor1_B,Motor2_Enb,Motor2_R,Motor2_B);
Hands hand(left_arm_pin,right_arm_pin,left_wrist_pin,right_wrist_pin);

void setup() {
  Serial.begin(9600);
  setup_motion(motion_pin);
}

void loop() 
{
  // check motion 1 or 0 
  Controller(check_motion());

}

void Controller(int motion)
{
  if (motion == 1)
  {
    if (eye.distance() ==1){
      wheel.move('b',1000);
    }
    wheel.move('f',1000);
  }
  else
  {
    int rand = random(1,10);
    switch (rand) 
      {
        case 1:
          wheel.rotate('r',2000);
          break;
        case 2:
        wheel.rotate('l',2000);
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;                
        default:
          break;
      }

  }
}
  
