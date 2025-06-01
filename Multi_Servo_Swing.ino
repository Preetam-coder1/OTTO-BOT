#include <Servo.h>
Servo s1, s2;
int s1_min = 0, s1_max = 180, s1_pos = s1_min;
int s2_min = 30, s2_max = 150, s2_pos = s2_min;
bool ds1 = 0, ds2 = 0;
unsigned long t1, t2;

void setup() {
  s1.attach(11);
  s2.attach(3);
  s1.write(s1_pos);
  s2.write(s2_pos);
}

void loop() {
  if (millis() - t1 > 10) {
    t1 = millis();
    (ds1 == 0) ? s1_pos++ : s1_pos--;
    if (s1_pos == s1_max || s1_pos == s1_min) ds1 = !ds1;
    s1.write(s1_pos);
  }
  if (millis() - t2 > 5) {
    t2 = millis();
    (ds2 == 0) ? s2_pos++ : s2_pos--;
    if (s2_pos == s2_max || s2_pos == s2_min) ds2 = !ds2;
    s2.write(s2_pos);
  }
}
