int ledState1 = 0;
int ledState2 = 0;
int ledState3 = 0;
int buttonState;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(8);
  if (buttonState == LOW) {
    if (ledState1 == 1 && ledState2 == 1 && ledState3 == 0) {
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      ledState3 = 1;
    } else if (ledState1 == 1 && ledState2 == 0 && ledState3 == 0) {
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      ledState2 = 1;
    } else if (ledState1 == 0 && ledState2 == 0 && ledState3 == 0) {
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      ledState1 = 1;
    } else {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      ledState1 = 0;
      ledState2 = 0;
      ledState3 = 0;
    }

    delay(300);
  }
}
