#include <Servo.h>

Servo esc;

void setup() {
  esc.attach(9);

  esc.writeMicroseconds(1000);   // Arm
  delay(3000);
}

void loop() {
  esc.writeMicroseconds(2000);   // Full throttle continuously
}
