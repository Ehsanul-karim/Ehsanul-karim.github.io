#define right_motor_forward 4
#define right_motor_backward 5
#define right_motor_speed 3
#define left_motor_forward 7
#define left_motor_backward 6
#define left_motor_speed 9
#define spl 25
#define spr 25


char x;
int spd = 255;
void setup() {
  pinMode(A0,INPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  bluetooth();                                                                                                           
   //motor(10*spl, 10*spr);
}
