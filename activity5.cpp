// C++ code
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

boolean lastButton = HIGH;
int state = 0;

void setup()
{
  lcd.init();
  lcd.backlight();  
  lcd.setCursor(0, 0);
  lcd.print("LED");
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  boolean currentButton = digitalRead(2);
  
  if (currentButton == LOW && lastButton == HIGH) {
    if (state == 0) {
      state++; 
    } else {
      state = 0;
    }
  }
	
  function(state);
  
  lastButton = currentButton;
}

void function(int state) {
  switch(state) {
    case 0:
    	digitalWrite(13, LOW);
        lcd.setCursor(4, 0);
  		lcd.print("OFF");
    	break;
    case 1:
    	digitalWrite(13, HIGH);
        lcd.setCursor(4, 0);
  		lcd.print("ON ");
    	break;
    
  }
  

  	delay(100);
}
