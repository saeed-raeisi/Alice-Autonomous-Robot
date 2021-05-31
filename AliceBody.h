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

    uint8_t Left_arm_pin;
    uint8_t Right_arm_pin;
    uint8_t Left_wrist_pin;
    uint8_t Right_wrist_pin;
};



Wheels::Wheels(uint8_t Motor1_Enb,uint8_t Motor1_R,uint8_t Motor1_B,uint8_t Motor2_Enb,uint8_t Motor2_R,uint8_t Motor2_B)
{
    pinMode(Motor1_Enb, OUTPUT);
    pinMode(Motor1_R, OUTPUT);
    pinMode(Motor1_B, OUTPUT);

    pinMode(Motor2_Enb, OUTPUT);
    pinMode(Motor2_R, OUTPUT);
    pinMode(Motor2_B, OUTPUT);
    this->Motor1_Enb = Motor1_Enb;
    this->Motor1_R = Motor1_R;
    this->Motor1_B = Motor1_B;

    this->Motor2_Enb = Motor2_Enb;
    this->Motor2_R = Motor2_R;
    this->Motor2_B = Motor2_B;
}

void Wheels::rotate(char direction, long int time)
{
    /* hi */
    if (direction == 'r')
    {
        digitalWrite(Motor1_R, HIGH);
        digitalWrite(Motor1_B, LOW);
//        analogWrite(Motor1_Enb, 120);
        digitalWrite(Motor1_Enb, HIGH);
        delay(time);
        digitalWrite(Motor1_Enb, LOW);
        digitalWrite(Motor2_Enb, LOW);
    }
    else
    {   
        digitalWrite(Motor2_R, HIGH);
        digitalWrite(Motor2_B, LOW);
//        analogWrite(Motor2_Enb, 120);
        digitalWrite(Motor2_Enb, HIGH);
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
  // arm pin
    this->Left_arm_pin = left_arm_pin;
    this->Right_arm_pin = right_arm_pin;    
 // wrist pin
    this->Left_wrist_pin = left_wrist_pin;
    this->Right_wrist_pin = right_wrist_pin;
}

void Hands::hand_move(char hand, int direction)
{
  Servo thisServo;

    if (hand == 'r'){
      thisServo.attach(Right_arm_pin);
      thisServo.write(direction);
    }
    else{
      thisServo.attach(Left_arm_pin);
       thisServo.write(direction);
    }
}

void Hands::wrist_move(char hand, int state)
{
    Servo thisServo;
    if (hand == 'r'){
      thisServo.attach(Right_wrist_pin);
        thisServo.write(state);
    }
    else{
      thisServo.attach(Left_wrist_pin);
        thisServo.write(state);
    }

}



void setup_motion(uint8_t motion_pin) 
{ 
  pinMode(motion_pin, INPUT); 
//  motion = motion_pin;
}
 
int check_motion(uint8_t motion_pin)
{
  
  int x= digitalRead(motion_pin);
 
  if(digitalRead(motion_pin)==HIGH)
  {
//    Serial.println("motion return  1 ");
//    Serial.println(x);
    return 1;
  }
  else
  {
//    Serial.println("motion  return 0 ");
    return 0;
  }
} 
