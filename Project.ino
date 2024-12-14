#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int A_base_Right_Echo = 3;
int A_base_Right_Trig = 2;
 
int B_base_Right_Echo = 7;
int B_base_Right_Trig = 6;

int A_base_Left_Echo = 9;
int A_base_Left_Trig =8;
 
int B_base_Left_Echo = 11;

int B_base_Left_Trig =10;

int Left_Long_Echo =5;
int Left_Long_Trig =4;

int Right_Long_Echo =14;
int Right_Long_Trig =15;

int Goal_A_Side =13;
int Goal_B_Side =12;

int A_base_Left_Distance =40;
int A_base_Right_Distance =34;

int B_base_Left_Distance =25;
int B_base_Right_Distance =35;

int Left_Long_Distance =110;
int Right_Long_Distance =1100;

float A_base_Left_Current_Distance =0;
float A_base_Right_Current_Distance =0;

float B_base_Left_Current_Distance =0;
float B_base_Right_Current_Distance =0;

float Left_Long_Current_Distance =0;
float Right_Long_Current_Distance =0;

int Goal_A =0;
int Goal_B =0;

int a=0;
int b=0;


float distance(int trig,int echo)
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float Time,Dis;
  Time = pulseIn(echo,HIGH);
  Dis = 0.0343*0.5*Time;
  return Dis;
}

void score(){
  
  lcd.init();
  

  lcd.setCursor(0,0);
  lcd.print("TAL ");
  lcd.setCursor(4,0);
  lcd.print(a);

  lcd.setCursor(6,0);
  lcd.print(":");


  lcd.setCursor(7,0);
  lcd.print(b);
  lcd.setCursor(9,0);
  lcd.print(" MASH");
  
  
  }

void setup() {

  
  
  pinMode(A_base_Right_Echo,INPUT);
  pinMode(A_base_Left_Echo,INPUT);
  pinMode(B_base_Right_Echo,INPUT);
  pinMode(B_base_Left_Echo,INPUT);
  pinMode(Left_Long_Echo,INPUT);
  pinMode(Right_Long_Echo,INPUT);

  pinMode(A_base_Right_Trig,OUTPUT);
  pinMode(A_base_Left_Trig,OUTPUT);
  pinMode(B_base_Right_Trig,OUTPUT);
  pinMode(B_base_Left_Trig,OUTPUT);
  pinMode(Left_Long_Trig,OUTPUT);
  pinMode(Right_Long_Trig,OUTPUT);

  pinMode(Goal_A_Side,INPUT);
  pinMode(Goal_B_Side,INPUT);


  lcd.backlight();

  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO ");
  lcd.setCursor(0,1);
  lcd.print("SOCCERBOT");
  score(); 

  delay(500);
 
  Serial.begin(9600);

  
}

void loop() {
  
 A_base_Left_Current_Distance = distance(A_base_Left_Trig,A_base_Left_Echo);
 A_base_Right_Current_Distance = distance(A_base_Right_Trig,A_base_Right_Echo);

 B_base_Left_Current_Distance = distance(B_base_Left_Trig,B_base_Left_Echo);
 B_base_Right_Current_Distance =distance(B_base_Right_Trig,B_base_Right_Echo);

 Left_Long_Current_Distance = distance(Left_Long_Trig, Left_Long_Echo);
 Right_Long_Current_Distance = distance(Right_Long_Trig, Right_Long_Echo);

 Goal_A = digitalRead(Goal_A_Side);
 Goal_B = digitalRead(Goal_B_Side);

// Serial.println(B_base_Right_Current_Distance);
// Serial.println(B_base_Right_Distance);


 if(!Goal_A)
  {
     a=a+1;
     Serial.print("Goal Talha");
     lcd.init();
     lcd.setCursor(0,0);
     lcd.print("GOAL TAL!!");
     score();
     delay(50);
  }




 if(!Goal_B)
 {
   b=b+1;
  
   Serial.print("Goal Mashfi");

   lcd.init();
   lcd.setCursor(0,0);
   lcd.print("GOAL MASH!!");
  
   score();
   delay(50);  
 }
Serial.println(Left_Long_Distance);
Serial.println(Left_Long_Current_Distance);
if(A_base_Left_Current_Distance < A_base_Left_Distance || B_base_Left_Current_Distance < B_base_Left_Distance || A_base_Right_Current_Distance < A_base_Right_Distance || B_base_Right_Current_Distance < B_base_Right_Distance ||Left_Long_Current_Distance < Left_Long_Distance )
{
  lcd.init();
  lcd.setCursor(6,0);
  lcd.print("OUT!");
  delay(5);
  
  score();

  }


 
}
