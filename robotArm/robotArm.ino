/*
  OSOYOO製のLCDを使用しています．
  仕様については次は参照してください．
  http://osoyoo.com/2014/12/07/16x2-i2c-liquidcrystal-displaylcd/
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define l 10.0 //アームの長さ

LiquidCrystal_I2C lcd(0x3f, 16, 2); //I2Cアドレスを指定
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int x = 0; //ペン先の直行座標
int y = 0;

void setup() {
  lcd.init(); //LCDを初期化

  // 制御信号を送る出力ピンの設定
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String preX = Serial.readStringUntil(';');
    x = preX.toInt();

    String preY = Serial.readStringUntil(';');
    y = preY.toInt();
  }

  float s1, s2, s3, s4; //４つのサーボの回転角
  int penOff, r; /*ペンを下ろすときpenOff = 0
                  ペンを上げるときpenOff = 1 */
  r = sqrt(pow(x, 2) + pow(y, 2)); //極座標(r,s4)のrを定める

  //ゼロ割りを回避する
  if (y != 0) {
    s1 = asin(x / (2 * l)) * (180 / PI); //s1を定義
    s2 = s1 * 2; //s2を定義
    s3 = s1; //s3を定義
    s4 = atan(x / y) * (180 / PI); //s4を定義
  }

  servos(s1, s2, s3, s4); //サーボ４つまとめて動かす独自関数
  servoLCD(s1, s2, s3, s4); //s1,s2,s3,s4のそれぞれの値をLCDで表示する関数

  delay(1000); //１秒間停止
}

void servos(int servo1_angle, int servo2_angle, int servo3_angle, int servo4_angle) {
  /* ４つのサーボの回転角
     をそれぞれ指定して動かす関数
  */
  servo1.write(servo1_angle);
  servo2.write(servo2_angle);
  servo3.write(servo3_angle);
  servo4.write(servo4_angle);
}

void servoMove() {
  //-------------
}

void servoLCD(float s1, float s2, float s3, float s4) {
  /* LCDに指定した座標とサーボの回転角を表示する関数
  */
  lcd.backlight(); //LCDのバックライトをつける
  lcd.setCursor(0, 0); //LCDの１段目に表示
  lcd.print("(");
  lcd.print(zeroPad(2, x));
  lcd.print(',');
  lcd.print(zeroPad(2, y));
  lcd.print(")");

  String sa = zeroPad(3, round(s1 * 10));
  String sb = zeroPad(3, round(s2 * 10));
  String sc = zeroPad(3, round(s3 * 10));
  String sd = zeroPad(3, round(s4 * 10));

  lcd.setCursor(0, 1); //LCDの２段目に表示
  lcd.print(sa);
  lcd.print(':');
  lcd.print(sb);
  lcd.print(':');
  lcd.print(sc);
  lcd.print(':');
  lcd.print(sd);

}

String zeroPad(int numLength, int num) {
  /* numをnumLength桁になるようにゼロ埋めしたString型の変数で返す関数
  */
  String NUM = String(num);
  String zero = "0";
  if (num == 0) {
    for (int i = 2; i <= numLength; i++) {
      zero.concat(NUM);
      NUM = zero;
      zero = "0";
    }
  } else {
    for (int i = 1; i <= numLength; i++) {
      if (num < pow(10, i - 1)) {
        zero.concat(NUM);
        NUM = zero;
        zero = "0";
      }
    }
  }
  return (NUM);
}
