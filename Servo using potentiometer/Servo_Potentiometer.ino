#include<Servo.h>
Servo Servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Servo.attach(9);
}

void loop() {
int x=analogRead(A0);
int y=map(x,0,1023,0,180);

Servo.write(y);
delay(2000);
// Serial.println("angle is 0 degree");
// delay(2000);
// Servo.write(A0);
// Serial.println("angle is ninty degree");
// delay(2000);
// Servo.write(A0);
// Serial.println("angle is 180 degree");
// delay(2000);

}
