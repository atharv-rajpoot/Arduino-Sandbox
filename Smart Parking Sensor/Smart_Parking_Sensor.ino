const int PIN_TRIG =9;
const int PIN_ECHO =10;

const int gl=2;
const int yl=3;
const int rl=4;

const int buzzer =8;

void setup(){
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(gl, OUTPUT);
  pinMode(yl, OUTPUT);
  pinMode(rl, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  int duration = pulseIn(PIN_ECHO, HIGH);
  float distance = duration / 58;
  Serial.print("Distance: " );
  Serial.print(distance);

//turning off  all the led
digitalWrite(yl, LOW);
digitalWrite(gl, LOW);
digitalWrite(rl, LOW);

//
if(distance >100){
  digitalWrite(gl, HIGH);
}
else if( distance >50){
  digitalWrite(yl, HIGH);

  tone(buzzer,800);
  delay(300);
  noTone(buzzer);
  delay(700);
}
else if(distance > 20){
  digitalWrite(rl, HIGH);
  tone(buzzer,1000);
  delay(200);
  noTone(buzzer);
  delay(300);
}
else{
  digitalWrite(rl, HIGH);
  tone(buzzer,1500);
  delay(100);
  noTone(buzzer);
  delay(100);
}
  
}