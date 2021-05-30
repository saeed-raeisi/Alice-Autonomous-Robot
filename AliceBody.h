/*

Wheels -> move & rotate
Hands -> hand_move & wrist_move


*/
#include <Servo.h>

// Motion 
uint8_t motion;
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



Wheels::Wheels(uint8_t Motor1_Enb,uint8_t Motor1_R,uint8_t Motor1_B,uint8_t Motor2_Enb,uint8_t Motor2_R,uint8_t Motor2_B)
{
    pinMode(Motor1_Enb, OUTPUT);
    pinMode(Motor1_R, OUTPUT);
    pinMode(Motor1_B, OUTPUT);

    pinMode(Motor2_Enb, OUTPUT);
    pinMode(Motor2_R, OUTPUT);
    pinMode(Motor2_B, OUTPUT);
}

void Wheels::rotate(char direction, long int time)
{
    /* hi */
    if (direction == 'r')
    {
        digitalWrite(Motor1_R, HIGH);
        digitalWrite(Motor1_B, LOW);
        analogWrite(Motor1_Enb, 120);
        delay(time);
        digitalWrite(Motor1_Enb, LOW);
        digitalWrite(Motor2_Enb, LOW);
    }
    else
    {   
        digitalWrite(Motor2_R, HIGH);
        digitalWrite(Motor2_B, LOW);
        analogWrite(Motor2_Enb, 120);
        delay(time);
        digitalWrite(Motor1_Enb, LOW);
        digitalWrite(Motor2_Enb, LOW);
    }
}

void Wheels::move(char direction,long int time)
{
    /* hi */
    if (direction == 'f')
    {
        for (int j=128;j<256;j+=4)
            {   
                digitalWrite(Motor1_R, HIGH);
                digitalWrite(Motor1_B, LOW);
                digitalWrite(Motor2_R, HIGH);
                digitalWrite(Motor2_B, LOW);
                analogWrite(Motor1_Enb, j);
                analogWrite(Motor2_Enb, j);
                delay(10);      
            }
        delay(1000);
        digitalWrite(Motor1_Enb, LOW);
        digitalWrite(Motor2_Enb, LOW);

    }
    else
    {

        for (int j=128;j<256;j+=4)
            {   
                digitalWrite(Motor1_R, LOW);
                digitalWrite(Motor1_B, HIGH);
                digitalWrite(Motor2_R, LOW);
                digitalWrite(Motor2_B, HIGH);
                analogWrite(Motor1_Enb, j);
                analogWrite(Motor2_Enb, j);
                delay(10);     
            }
        delay(1000);
        digitalWrite(Motor1_Enb, LOW);
        digitalWrite(Motor2_Enb, LOW);        

    }
}



Hands::Hands(uint8_t left_arm_pin, uint8_t right_arm_pin, uint8_t left_wrist_pin, uint8_t right_wrist_pin)
{
    pinMode(left_arm_pin,OUTPUT);
    pinMode(right_arm_pin,OUTPUT);

    pinMode(left_wrist_pin,OUTPUT);
    pinMode(right_wrist_pin,OUTPUT);

    Left_arm.attach(left_arm_pin);
    Right_arm.attach(right_arm_pin);

    Left_wrist.attach(left_wrist_pin);
    Right_wrist.attach(right_wrist_pin);
}

void Hands::hand_move(char hand, int direction)
{
    if (hand == 'r'){

    }
    else{

    }
}

void Hands::wrist_move(char hand, int state)
{
    if (hand == 'r'){

    }
    else{
        
    }

}



void setup_motion(uint8_t motion_pin) 
{ 
  pinMode(motion_pin, INPUT); 
  motion = motion_pin;
}
 
int check_motion()
{
  
  int x= digitalRead(motion);
 
  if(digitalRead(motion)==HIGH)
  {
    Serial.println("motion return  1 ");
    Serial.println(x);
    return 1;
  }
  else
  {
    Serial.println("motion  return 0 ");
    return 0;
  }
} 
