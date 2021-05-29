#include "Motor.h"
#include "eye.h"
#include "Motion.h"
Motor myMotor;
int dis_state=0;
int motion_state=0;
void setup() {
  /* header set all library and class name and define 
   *  .c file all function stracture
   *  
   *  mega 
   * body and head 
   * body -> class wheels and hands 
   * 
     * wheels -> motor and some change
     * hands -> just servo and degree
   * 
   * head -> eye and abro and dahan 
   * 
   *  eye -> eye.h
   *  abro -> just servo 
   *  dahan -> just lcd
   * 
   * uno -> get signal and paly music 
   * 
   * 
   * robot after turn on    -> look right and left and strait go to less distance or go to moving object      or random move
   * robot after see -> smile and state 1 abro
   * robot after get wall -> sad an state 2 abro
   * robot after not found any thing get absolate and state 3 abro
   * 
   * robot have random choise 
   * 
   * 
  */
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
  
