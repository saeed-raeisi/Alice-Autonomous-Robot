#include "Motor.h"
#include "eye.h"
#include "Motion.h"
Motor myMotor;
int dis_state=0;
int motion_state=0;
void setup() {
  Serial.begin(9600);
  setup_eye();
  setup_motion();
  myMotor.setup_motor();
}

void loop() 
{
  // i -> state 1-> right 2-> front 3->left
  for(int i=1;i<4;i++)
  {
  Serial.print("state");
  Serial.print("\t");
  Serial.print(i);
  dis_state=0;
  motion_state=0;
  //dis <10 -> 1   >10-> 2  else 0
  dis_state = eye_move(i);
  // motion 1 find else 0
  motion_state = check_motion();
  // 
  myMotor.start(dis_state,i,motion_state);
  }
}
  
