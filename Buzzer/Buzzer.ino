const int buttonpin =2;
const int buzzerpin =8;

void setup(){
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(buzzerpin, OUTPUT);
}

void loop(){
  int buttonstate = digitalRead(buttonpin);
  
  if (buttonstate == LOW){ //button is pressed
    tone(buzzerpin,1000);
  }
  else{
    noTone(buzzerpin);
  }
}