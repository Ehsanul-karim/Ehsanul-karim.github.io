
#define right_motor_forward 2
#define right_motor_backward 4
#define right_motor_speed 3
#define left_motor_forward 5
#define left_motor_backward 6
#define left_motor_speed 9



void setup() {
 
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT); 
  


}

void loop() {


    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);

    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);


    digitalWrite(left_motor_speed, 1);
    digitalWrite(right_motor_speed, 1);

    

}
