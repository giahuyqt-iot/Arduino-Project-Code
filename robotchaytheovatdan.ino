
  
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      

const int echo=8;
const int trig=7;

int cbphai=2;
int cbtrai=13;

unsigned long thoigian; 
int khoangcach;          

void setup() {
  // put your setup code here, to run once:
   
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);   

  pinMode(cbtrai,INPUT);
  pinMode(cbphai,INPUT);

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
 
  Serial.begin(9600);


}

void loop()
{
  int gtcbphai = digitalRead(cbphai);
  int gtcbtrai = digitalRead(cbtrai);
  khoangcach = 0;
  dokhoangcach();
  Serial.print(gtcbphai);
  Serial.print(gtcbtrai);
  Serial.println(khoangcach);
  if(khoangcach<=25 && khoangcach>=5 ){
    if(gtcbtrai==0 && gtcbphai==0){
      dithang();Serial.println("Di Thang");
    }
    else if(gtcbtrai!=0 && gtcbphai==0){
      disangphai();
      Serial.println("Di Sang Phai");
    }
    else if(gtcbtrai==0 && gtcbphai!=0){
      disangtrai();
      Serial.println("Di Sang Trai");
  }
    else {dunglai();Serial.println("Dung lai");}
  }
  else if(khoangcach>25){dunglai();Serial.println("Dung lai");}
  else if(khoangcach<5 && gtcbtrai==0 && gtcbphai==0){
    dilui();Serial.println("Di Lui");
    }
}
void dithang()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
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
