#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal Mouth_lcd(8,7,6,5,4,3,2);
byte Smile1[8]={ 
  B00000,
  B00000,
  B00001,
  B00001,
  B00100,
  B00100,
  B10000,
  B10000,};
byte Smile2[8]={ 
  B00001,
  B00101,
  B10100,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile3[8]={  
 B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile4[8]={  
 B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile5[8]={  
 B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile6[8]={ 
 B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile7[8]={  
  B10000,
  B10100,
  B00101,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000,};
byte Smile8[8]={  
  B00000,
  B00000,
  B00000,
  B10000,
  B10000,
  B00100,
  B00101,
  B00001,};

class Eye
{
    public:
        Eye(uint8_t trigger_pin, uint8_t echo_pin);
        int distance(unsigned int cm_distance = 0);
        void set_eyeBrow(char state); // state s , l , a
        void rotate_neck(char state); // l r m 

    private:
    uint8_t Trig;
    uint8_t Echo;

};


class Mouth
{
    public:
    Mouth(uint8_t lcd_pin1,uint8_t lcd_pin2,uint8_t lcd_pin3,uint8_t lcd_pin4,uint8_t lcd_pin5,uint8_t lcd_pin6,uint8_t lcd_pin7);
    void smiley_face();
    void angry_face();
    void faceless();
   

};




Eye::Eye(uint8_t trigger_pin, uint8_t echo_pin)
{
      pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
    this->Trig = trigger_pin;
    this->Echo = echo_pin;

}

int Eye::distance(unsigned int cm_distance)
{
  unsigned long Time ;
  float distance ;
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
 
  Time = pulseIn(Echo, HIGH);       
  distance = (Time / 2) * 0.03432 ; 
  if (Time < 30000) {
    if (distance > cm_distance)
    {
//       Serial.println("eye distance >10 return 2");
//       Serial.println(distance);
       return 2; 
    }
    else{
////      Serial.println("eye distance <10  return 1");
//      Serial.println(distance); 
        return 1;
    }
  }
  return 0; 

}


void Eye::set_eyeBrow(char state)
{
    /* s l a*/

}

void Eye::rotate_neck(char state)
{
    /* l r m */
    
}

Mouth::Mouth(uint8_t lcd_pin1,uint8_t lcd_pin2,uint8_t lcd_pin3,uint8_t lcd_pin4,uint8_t lcd_pin5,uint8_t lcd_pin6,uint8_t lcd_pin7)
{   // 11,10,9,5,4,3,2
    LiquidCrystal lcd(lcd_pin1,lcd_pin2,lcd_pin3,lcd_pin4,lcd_pin5,lcd_pin6,lcd_pin7);
    lcd.begin(16, 2);
    lcd.clear();
//    Mouth_lcd = lcd;
}

void Mouth::smiley_face()
{
    int index;
    Mouth_lcd.createChar(4, Smile1); 
    Mouth_lcd.createChar(5 , Smile2);                              
    Mouth_lcd.createChar(6 , Smile3);
    Mouth_lcd.createChar(7 , Smile4);
    Mouth_lcd.createChar(8 , Smile5);
    Mouth_lcd.createChar(9 , Smile6);
    Mouth_lcd.createChar(10 , Smile7);
    Mouth_lcd.createChar(11 , Smile8);

    

  for(index=4;index<12;index++){     
    Mouth_lcd.setCursor(index ,0);
    Mouth_lcd.write(index);              
  } 
}
