int choose=0;
bool lasState= HIGH;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);  //Red
  pinMode(9,OUTPUT);  //Yellow
  pinMode(10,OUTPUT); //Green
  pinMode(3,OUTPUT); //Buzzer 

  pinMode(11,INPUT_PULLUP);
}

// x = ammount blnk ,, y == what light
void blink(int x, int y){

  for(int i=0;y>i;i++){
    digitalWrite(x,HIGH);
    tone(3,440);

        //blink
        delay(100);
        digitalWrite(x,LOW);
        delay(100);
        noTone(3);
  }
  
}
void loop() {
  
  bool curState = digitalRead(11);

    if(lasState==LOW && curState == HIGH){
      choose+=1;
      Serial.write(choose);
      switch(choose){
        case 0:
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        break;

        case 1:
        digitalWrite(8,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        tone(3,440);

        //blink
        delay(100);
        digitalWrite(8,LOW);
        noTone(3);

        break;

        case 2:
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);

        blink(9,3);

        break;

        case 3:
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);

        blink(10,5);
                choose=0;


        break;
        case 4:
        choose=-1;
        break;

      if(choose>5){
      }
      }
    }
  lasState=curState;
}
