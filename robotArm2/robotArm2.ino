#include <Servo.h>
#define l 10 //アームの長さ

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
  int x,y; //ペン先の直行座標
  float s1,s2,s3,s4; //４つのサーボの回転角
  int penOff,r; /*ペンを下ろすときpenOff = 0
                  ペンを上げるときpenOff = 1 */
  r = sqrt(pow(x,2)+pow(y,2)); //極座標(r,s4)のrを定める

  //ゼロ割りが起きる前にエラーを出す
  if(y!=0){
    s1 = asin(x/(2*l); //s1を定義
    s2 = s1*2; //s2を定義
    s3 = s1; //s3を定義
    s4 = atan(x/y); //s4を定義
  }else{
      print("ERROR! Make sure y and l are not ZERO");
  }
  servos(s1,s2,s3,s4); //サーボ４つまとめて動かす独自関数
  delay(1000); //１秒間停止
}

/* ４つのサーボの回転角
をそれぞれ指定して動かす関数 */
void servos(int servo1_angle,int servo2_angle,int servo3_angle,int servo4_angle){
  servo1.write(servo1_angle);
  servo2.write(servo2_angle);
  servo3.write(servo3_angle);
  servo4.write(servo4_angle);
}

