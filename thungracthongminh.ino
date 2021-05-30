//Desgine by Lựu
#include<Servo.h>
Servo myservo;
int servoPin=A0;

int enbA=3;
int in1 = 2;       
int in2 = 4;        
int in3 = 6;        
int in4 = 7;  
int enbB=5;      


const int echo=8;
const int trig=9;
const int echo1=A5;
const int trig1=A4;
const int mattrai=11;
const int matphai=10;

unsigned long thoigian, thoigian1; 
int khoangcach, khoangcach1;          
//int khoangcachtrai, khoangcachphai;
void setup() {
  // put your setup code here, to run once:
   
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);   

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);

  pinMode(mattrai,INPUT);
  pinMode(matphai,INPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);


  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(0);
  //delay(1000);
  //myservo.write(90);
 // delay(1000);
  //myservo.write(135);
  //delay(1000);
  //myservo.write(90);
//  delay(1000);
 
}

void loop()
{
  theosauvatdan(100);
 if(dungyen())
  {monapthung();}
  
}

void dithang(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
void dunglai(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void disangphai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo-20);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
void disangtrai(int tocdo)
{
  analogWrite(enbA, tocdo-20);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}



void dokhoangcach()
{

  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(echo, HIGH);

  khoangcach = thoigian / 2 / 29.412;

}
void dokhoangcach1()
{

  digitalWrite(trig1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig1, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian1 = pulseIn(echo1, HIGH);

  khoangcach1 = thoigian1 / 2 / 29.412;

}
//Theo sau vật dẫn
void theosauvatdan(int tocdo)
{
  int gtmatphai = digitalRead(matphai);
  int gtmattrai = digitalRead(mattrai);
  
  khoangcach = 0;
  dokhoangcach();
 // Serial.print(gtmatphai);
  //Serial.print(gtmattrai);
  //Serial.println(khoangcach);
  if(khoangcach<=20 && khoangcach>4 ){
    if((gtmattrai==0 && gtmatphai==0) || (gtmattrai==1 && gtmatphai==1))
    {
      dithang(tocdo);Serial.println("Di Toi");
    }
    else if (gtmattrai!=0 && gtmatphai==0)
    {
      disangphai(tocdo);Serial.println("Di Sang Phai");
    }
    else if(gtmattrai==0 && gtmatphai!=0)
    {
       disangtrai(tocdo);Serial.println("Di Sang Trai");
    }
  }
    
  else if(khoangcach>20){dunglai();Serial.println("Dung lai");}//myDFPlayer.play(7); delay(2000);}
  else if(khoangcach<3){
    dilui(tocdo);Serial.println("Di Lui");
    }
  else if(khoangcach>=3 && khoangcach<=4){
    dunglai();Serial.println("Dung lai");
    }
}
//Mo nap thung
void monapthung()
{
  khoangcach1=0;
  dokhoangcach1();
  Serial.println(khoangcach1);
  if(khoangcach1<=20)
  {
    myservo.write(60);
    delay(3000);
    myservo.write(0);
    
  }
}
//Kiem tra thung rac co dung yen hay khong, neu dung yen thi moi cho phep mo nap
boolean dungyen()
{
  khoangcach=0;
  dokhoangcach();
  if (khoangcach>20)
  {return true;}
  else{return false;} 
}
