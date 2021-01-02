#include "pitches.h"
#include <Servo.h>
#define buzzer 8
#define servo 12
#define Trig 11
#define Echo 10
Servo myservo;
  // notes in the melody:
  int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
  };



void setup_eye();
int distance();
void note();
void setup_eye()
{
  pinMode(servo,OUTPUT);
  myservo.attach(servo);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}
int eye_move(int state){
  int dis=0;
  switch (state) {
    // Right
  case 1:
    myservo.write(0);
    dis=distance();
    delay(2000);
    return dis;
    break;
    // Front
  case 2:
    myservo.write(60);
    dis=distance();
    delay(2000);
    return dis;
    break;
    // Left
  case 3:
    myservo.write(180);
    dis=distance();
    delay(2000);
    return dis;
    break;  
  default:
    return dis;
    break;
}
  
//  myservo.write(0);
//  distance();
//  delay(2000);
//  myservo.write(60);
//  distance();
//  delay(2000);
//  myservo.write(180);
//  distance();
//  delay(2000);
}

int distance(){
  unsigned long Time ;
  float distance ;
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
 
  Time = pulseIn(Echo, HIGH);       
  distance = (Time / 2) * 0.03432 ; 
  if (Time < 30000) {
    if (distance > 10)
    {
       digitalWrite(buzzer, LOW);
       Serial.println("eye distance >10 return 2");
       Serial.println(distance);
       return 2; 
    }
    else{
       note();
      Serial.println("eye distance <10  return 1");
      Serial.println(distance); 
        return 1;
//      digitalWrite(buzzer, HIGH); 
//      delay(500);
//      digitalWrite(buzzer, LOW);
//      delay(500);

    }
    delay(500);
  }
  return 0; 
}

void note(){
    // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzzer);
  }
}
