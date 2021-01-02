#define Motor1_Enb 3
#define Motor1_R 2
#define Motor1_B 4

#define Motor2_R 5
#define Motor2_B 7
#define Motor2_Enb 6
  /* 2-7 Driver Motor
       3 Enable 1
       2 IN1
       4 IN2
       5 IN3
       7 IN4
       6 Enable 2
  */    

class Motor
{
 public:
  void setup_motor();
  void go();
  void backMotor();
  void right();
  void left();
  void longRight();
  void longLeft();
  void start(int dis, int state,int motion);
  
  
};

void Motor::start(int dis, int state,int motion)
{
  //dis <10 -> 1   >10-> 2  else 0
  // motion 1 find else 0
  //state  1-> right 2-> front 3->left
  if (dis==2)
  {
    Serial.println("dis state 2 in motor ");
    if( state == 1)
    {
      if(motion==1) go();
      else right();
    }
     if( state == 2)
    {
      if(motion==1) go();
    }
    if( state == 3)
    {
      if(motion==1) go();
      else left();
    }
  }

  else if (dis == 1 )
  {
    Serial.println("dis state 1 in motor ");
    backMotor();
  }
  else {
    Serial.println("dis state 0 in motor ");
    // 1 go 2 long long right 3 long long left
    // 4 back 5 long left 6 long right
    int randNumber = random(1, 7);
    switch (randNumber) {
  case 1:
    go();
    break;
  case 2:
    longRight();
    longRight();
    break;
  case 3:
    longLeft();
    longLeft();
    break;
  case 4:
    backMotor();
    break;
  case 5:
    longLeft();
    break;
  case 6:
    longRight();
    break;                
  default:
    break;
}
  }
  
}

void Motor::setup_motor()
{
   for (int i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void Motor::go()
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

void Motor::backMotor()
{
 
   for (int k=64;k<128;k+=4)
    {   
      digitalWrite(Motor1_R, LOW);
      digitalWrite(Motor1_B, HIGH);
      digitalWrite(Motor2_R, LOW);
      digitalWrite(Motor2_B, HIGH);
      analogWrite(Motor1_Enb, k);
      analogWrite(Motor2_Enb, k);
      delay(10); 
    }
  delay(1000);
  digitalWrite(Motor1_Enb, LOW);
  digitalWrite(Motor2_Enb, LOW); 

}
  

void Motor::right()
{
  digitalWrite(Motor1_R, HIGH);
  digitalWrite(Motor1_B, LOW);
  analogWrite(Motor1_Enb, 120);
  delay(500);
  digitalWrite(Motor1_Enb, LOW);
  digitalWrite(Motor2_Enb, LOW);
  delay(5000);
}
void Motor::left()
{
  digitalWrite(Motor2_R, HIGH);
  digitalWrite(Motor2_B, LOW);
  //digitalWrite(6, HIGH);
  analogWrite(Motor2_Enb, 120);
  delay(500);
  digitalWrite(Motor1_Enb, LOW);
  digitalWrite(Motor2_Enb, LOW);
  delay(5000);
}

void Motor::longRight()
{
    digitalWrite(Motor1_R, HIGH);
  digitalWrite(Motor1_B, LOW);
  analogWrite(Motor1_Enb, 120);
  delay(1000);
  digitalWrite(Motor1_Enb, LOW);
  digitalWrite(Motor2_Enb, LOW);
  delay(5000);

}

void Motor::longLeft()
{
    digitalWrite(Motor2_R, HIGH);
  digitalWrite(Motor2_B, LOW);
  //digitalWrite(6, HIGH);
  analogWrite(Motor2_Enb, 120);
  delay(1000);
  digitalWrite(Motor1_Enb, LOW);
  digitalWrite(Motor2_Enb, LOW);
  delay(5000);
}
