
#include <TM1637Display.h>

// TM1637 Display Connections
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

// HC-SR04 Sensor Connections
#define TRIG 9
#define ECHO 10

long duration;
float distance;

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  display.setBrightness(7);
  display.clear();

  Serial.begin(9600);

}

void loop() {

  // Send ultrasonic trigger pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Measure echo duration
  duration = pulseIn(ECHO, HIGH, 30000);

  // Check sensor response
  if (duration == 0) {

    display.showNumberDec(0, false);
    Serial.println("No echo detected");

  }
  else {

    // Calculate distance in centimeters
    distance = duration * 0.0343 / 2;

    // Display distance
    display.showNumberDec(
      (int)distance,
      false
    );

    // Serial Monitor output
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

  }

  delay(200);

}
