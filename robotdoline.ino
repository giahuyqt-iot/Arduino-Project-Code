                 
//Desgine by Lựu
  int stop_distance = 12;// Khoảng cách phát hiện vật cản
//Kết nối SRF 05 OR 04
  const int trigPin = 11; // kết nối chân trig với chân 11 arduino
  const int echoPin = 12; // kết nối chân echo với chân 12 arduino

//kết nối của 2 cảm biến hồng ngoại (dò line )
   int cbtrai=13;
   int cbphai=12;
   
//L298 kết nối arduino
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      

int maxspeed=30;

 int gtcbtrai;
  int gtcbphai;
  //int gtcbsau;


void setup() {
  pinMode(gtcbphai,INPUT); // chân cảm biến khai báo là đầu vào
  pinMode(gtcbtrai,INPUT);
    pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    
  Serial.begin(9600); 
  analogWrite(enbA, 120); // tốc độ động cơ a ban đầu 120 ( 0 - 255)
  analogWrite(enbB, 120);// tốc độ động cơ b ban đầu 120 ( 0 - 255)
  delay(3000);                              
  
}
void loop()
{
  gtcbtrai=digitalRead(cbtrai);
  gtcbphai=digitalRead(cbphai);
  //gtcbsau=digitalRead(cbsau);
//====================================
  if(gtcbtrai==0 && gtcbphai==0)
  {
    dithang();
  }
  else if(gtcbtrai!=0 && gtcbphai==0)
  {
    disangtrai();
  }
  else if(gtcbtrai==0 && gtcbphai!=0)
  {
    disangphai();
  }
  else {dunglai();}
  

}

void dithang()
{
  analogWrite(enbA, 70);
  analogWrite(enbB, 70);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);


}
void dunglai(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void disangphai()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 80);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void xoay()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}






 
