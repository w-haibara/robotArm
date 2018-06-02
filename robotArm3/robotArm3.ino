#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define l 10.0 //アームの長さ
LiquidCrystal_I2C lcd(0x3f, 16, 2); //I2Cアドレスを指定
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int x,y; //ペン先の直行座標

void setup() {
  lcd.init(); //LCDを初期化
  // 制御信号を送る出力ピンの設定
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
}
void loop() {
  x = random(15);
  y = random(15);
 
  float s1,s2,s3,s4; //４つのサーボの回転角
  int penOff,r; /*ペンを下ろすときpenOff = 0
                  ペンを上げるときpenOff = 1 */
  r = sqrt(pow(x,2)+pow(y,2)); //極座標(r,s4)のrを定める
  
  //ゼロ割りが起きる前にエラーを出す
  if(y!=0){
    s1 = asin(x/(2*l))*(180/PI); //s1を定義
    s2 = s1*2; //s2を定義
    s3 = s1; //s3を定義
    s4 = atan(x/y)*(180/PI); //s4を定義
  }else{
      //print("ERROR! Make sure y and l are not ZERO");
  }
 
  servos(s1,s2,s3,s4); //サーボ４つまとめて動かす独自関数
  servoLCD(s1,s2,s3,s4); //s1,s2,s3,s4のそれぞれの値をLCDで表示する関数
 
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

void servoLCD(int s1, int s2, int s3,int s4){
  lcd.backlight(); //LCDのバックライトをつける
  lcd.setCursor(0, 0); //LCDの1段目に表示
  lcd.print(x);
  lcd.print(':');
  lcd.print(s1);
  lcd.print(':');
  lcd.print(s2);
 
  lcd.setCursor(0, 1); //LCDの1段目に表示
  lcd.print(y);
  lcd.print(':');
  lcd.print(s3);
  lcd.print(':');
  lcd.print(s4);
}