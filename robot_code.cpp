#include <Servo.h>
//����12�������Ӧ��arduino��Ľӿ�
Servo servo1;       //�м�������
Servo servo2;       //�м��Ҳ����
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
  //���ȴ����ǰ��
  for (int pos = 0; pos <= 60; pos++)
  {
    servo1.write(60-pos);        //�м��������������˷�����
    servo2.write(60-pos);        //������
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
  //���ȴ��������
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
  //���ȴ����
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
  //����
  servo1.attach(A0);                                 //�м䷴����ת��
  servo2.attach(A1);                                 //�м䷴����ת��
  servo3.attach(2);
  servo4.attach(3);
  servo5.attach(4);
  servo6.attach(5);
  //С��
  servo7.attach(6);       //ǰ��
  servo8.attach(7);
  servo9.attach(8);      //�м�
  servo10.attach(9);
  servo11.attach(10);    //����
  servo12.attach(11);

  pinMode(12,INPUT);  //����
//  pinMode(13,INPUT);  //����  
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
