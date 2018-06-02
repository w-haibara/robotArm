#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2); //I2Cアドレスを指定
 
void setup(){
  lcd.init(); //LCDを初期化
}
 
void loop()
{
  int i = random(100); //iの値を0から100の乱数で定義
 
  lcd.backlight(); //LCDのバックライトをつける
 
  lcd.setCursor(0, 0);　      //LCDの1段目に表示
  lcd.print("Hello World!"); //文字列を表示
  lcd.setCursor(0,1);　       //LCDの2段目に表示
  lcd.print(i);          　   //変数の値を表示

  delay(500); //500ミリ秒停止
}
