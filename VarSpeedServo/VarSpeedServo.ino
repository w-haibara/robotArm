#include <VarSpeedServo.h>

VarSpeedServo servo1, servo2;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(0, 90, false);
  servo2.write(40, 90, false);
}

void loop() {
  int i = 100;

  delay(500);

  servo1.write(180, i, false);
delay(180);
  servo2.write(0, i, true);
  servo2.write(40, i, true);


  servo1.write(0, i, false);

  servo2.write(40, i, true);


}
