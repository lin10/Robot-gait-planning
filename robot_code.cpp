#include <Servo.h>
//定义12个舵机对应的arduino板的接口
Servo servo1;       //中间左侧的足
Servo servo2;       //中间右侧的足
Servo servo3;        
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;
int BZleft;
int BZright;

void Advance()
{
  //大腿处舵机前进
  for (int pos = 0; pos <= 60; pos++)
  {
    servo1.write(60-pos);        //中间两条腿与其他退反方向
    servo2.write(60-pos);        //反方向
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);
    servo6.write(pos);

        servo10.write(60-pos);
    servo11.write(pos);
    servo8.write(pos);      
    delay(20);
  }
  for(int pos=60; pos>0; pos--)
  {
       servo8.write(pos);
       servo10.write(60-pos);
     servo11.write(pos);  
     delay(20); 
  }
  //大腿处舵机后退
  for (int pos = 60; pos >= 0; pos--)
  {
    servo1.write(60-pos);
    servo2.write(60-pos);
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);
    servo6.write(pos);

     servo7.write(pos);
     servo9.write(60-pos);
     servo12.write(pos);
  delay(20);
}
for(int pos=0;pos<=60 ;pos++)
{
  servo7.write(pos);
  servo9.write(60-pos);
  servo12.write(pos);
  delay(20);
  }
}

void Left()
{
    servo1.write(30);
    servo2.write(30);
    servo3.write(30);
    servo4.write(30);
    servo5.write(30);
    servo6.write(30);
  //大腿处舵机
  for (int pos = 0; pos <= 60; pos++)
{
           servo10.write(pos);
       servo11.write(pos);
       servo8.write(pos);      
    delay(20);
}
  for (int pos = 0; pos <= 60; pos++)
{
           servo7.write(pos);
       servo9.write(pos);
       servo12.write(pos);      
    delay(20);
}
  for(int pos=60; pos>0; pos--)
  {
       servo8.write(pos);
       servo10.write(pos);
     servo11.write(pos);  
     delay(20); 
  }
  for (int pos = 60; pos >= 0; pos--)
  {
           servo7.write(pos);
       servo9.write(pos);
       servo12.write(pos);
  delay(20);
   }
}
void setup()
{
  //大腿
  servo1.attach(A0);                                 //中间反方向转动
  servo2.attach(A1);                                 //中间反方向转动
  servo3.attach(2);
  servo4.attach(3);
  servo5.attach(4);
  servo6.attach(5);
  //小腿
  servo7.attach(6);       //前面
  servo8.attach(7);
  servo9.attach(8);      //中间
  servo10.attach(9);
  servo11.attach(10);    //后面
  servo12.attach(11);

  pinMode(12,INPUT);  //避障
//  pinMode(13,INPUT);  //避障  
}

void loop()
{   

  for (int b = 0; b=10000; b--)
  {
    BZleft=digitalRead(12);
 //   BZright=digitalRead(13);   && BZright==LOW  && BZright==HIGH
     if(BZleft==HIGH)
    {
      Advance();
    }
    if(BZleft==LOW)
    {
    Left();
    }
  }
}
