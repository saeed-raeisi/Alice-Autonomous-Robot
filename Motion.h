#define buzzer 8
#define motion 9
 
void  setup_motion();
int  check_motion();
 
void setup_motion() { 
  pinMode(motion, INPUT); 
  pinMode(buzzer,OUTPUT);
}
 
int check_motion() {
  
  int x= digitalRead(motion);
 
  if(digitalRead(motion)==HIGH)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(5000);
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
