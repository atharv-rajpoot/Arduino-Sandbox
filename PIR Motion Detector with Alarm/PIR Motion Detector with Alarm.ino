const int pirpin = 2;
const int ledpin = 13;
const int buzzerpin = 8;

void setup() {
    pinMode(pirpin, INPUT);
    pinMode(ledpin, OUTPUT);
    pinMode(buzzerpin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int motion = digitalRead(pirpin);

    if (motion == HIGH) {
        Serial.println("Motion Detected");
        digitalWrite(ledpin, HIGH);
        tone(buzzerpin, 1500);
        delay(5000);
        digitalWrite(ledpin, LOW);
        noTone(buzzerpin);
        Serial.println("Alarm is OFF");
    }
}