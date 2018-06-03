/*
OSOYOO製のLCDを使用しています．
仕様については次は参照されたしてください．
http://osoyoo.com/2014/12/07/16x2-i2c-liquidcrystal-displaylcd/
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2); //I2Cアドレスを指定

void setup() {
  lcd.init(); //LCDを初期化
}

void loop() {
  /* 4つのサーボの回転角を定義 *
     (今回はLCDのテストのため、
     0から100の乱数で定義する) */
  int s1 = random(100);
  int s2 = random(100);
  int s3 = random(100);
  int s4 = random(100);

  servoLCD(s1,s2,s3,s4); //s1,s2,s3,s4のそれぞれの値をLCDで表示する関数
  delay(500); //500ミリ秒停止
}

void servoLCD(int s1, int s2, int s3,int s4){
  lcd.backlight(); //LCDのバックライトをつける

  lcd.setCursor(0, 0); //LCDの1段目に表示
  lcd.print("s1:");
  lcd.print(s1);
  lcd.print(" s2:");
  lcd.print(s2);

  lcd.setCursor(0, 1); //LCDの1段目に表示
  lcd.print("s3:");
  lcd.print(s3);
  lcd.print(" s4:");
  lcd.print(s4);
}
