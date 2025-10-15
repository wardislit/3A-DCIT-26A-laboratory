#include <Servo.h>
Servo servo;
int lastState = HIGH;
int state = 0;
bool isStopped = false;
long holdTime;

void setup() {
  servo.attach(9);
  pinMode(8, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  
  int buttonState = digitalRead(8);
  if (isStopped) {
    digitalWrite(10, LOW);
    noTone(10);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    state = 0;
    isStopped = false;
  }
  
  if (buttonState == LOW && lastState == LOW) {
    if (millis() - holdTime >= 100) {
      forceStop();
    }
  }
  
  // Short press - change state
  if (buttonState == LOW && lastState == HIGH) {
    	holdTime = millis();
      	state++;
    	if (state >= 2) state = 0; 
  }
  
  // Do actions based on state
  if (state == 1) {
    servo.write(90);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    if (!isStopped) {   // Necessary specially it beeps after force stop confirms
    tone(10, 490);
    delay(300);
    digitalWrite(11, LOW);
    noTone(10);
    delay(300);
    }

  } else {
    servo.write(0);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    noTone(10);
  }
  
  lastState = buttonState;
}

void forceStop() {
  servo.write(0);
  noTone(10);
  
  // 3 warning beeps
  for (int i = 0; i < 3; i++) {
    tone(10, 1000);
    digitalWrite(11, HIGH);
    delay(150);
    noTone(10);
    digitalWrite(11, LOW);
    delay(150);
  }
  
  isStopped = true;
}
