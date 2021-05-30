#ifndef ALICEBODY_H
#define ALICEBODY_H 
#include <Servo.h>

// Motion 
void  setup_motion(uint8_t motion_pin);
int  check_motion();

class Wheels
{
 public:
    Wheels(uint8_t Motor1_Enb,uint8_t Motor1_R,uint8_t Motor1_B,uint8_t Motor2_Enb,uint8_t Motor2_R,uint8_t Motor2_B);
    void rotate(char direction, long int time); // direction r -> right & l -> left
    void move(char direction,long int time); // direction f -> front & b -> back

  private:
    // Left
    uint8_t Motor1_Enb;
    uint8_t Motor1_R;
    uint8_t Motor1_B;
    // Right
    uint8_t Motor2_R;
    uint8_t Motor2_B;
    uint8_t Motor2_Enb;
  
  
};


class Hands
{
    public:
        Hands(uint8_t left_arm_pin, uint8_t right_arm_pin, uint8_t left_wrist_pin, uint8_t right_wrist_pin);
        // hand -> r or l
        void hand_move(char hand ,int direction); // direction 60,90,120,180
        void wrist_move(char hand, int state); // state 1->open & state 0-> close

    private:
    Servo Left_arm;
    Servo Right_arm;

    Servo Left_wrist;
    Servo Right_wrist;
};

#endif

 
