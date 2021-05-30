#ifndef ALICEHEAD_H
#define ALICEHEAD_H 

#include <Servo.h>
#include <LiquidCrystal.h>


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
    private:
    LiquidCrystal Mouth_lcd();

};
#endif
