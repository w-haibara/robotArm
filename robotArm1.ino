#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() {
  // 制御信号を送る出力ピンの設定
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
}
void loop() {
  servos(0,0,0,0);
  delay(1000);
  servos(180,180,180,180);
  delay(1000);
}
void servos(int servo1_angle,int servo2_angle,int servo3_angle,int servo4_angle){
  servo1.write(servo1_angle);
  servo2.write(servo2_angle);
  servo3.write(servo3_angle);
  servo4.write(servo4_angle);
}

