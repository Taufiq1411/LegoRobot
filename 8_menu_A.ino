void setAvoider() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SETTINGS");
    while (1) {
      switch (select) {
        case 0: 
          select = 4;
          break;
        case 1: 
          lcd.setCursor(0,1);
          lcd.print(" Sensor Distance");
          setDistance();
          break;
        case 2: 
          lcd.setCursor(0,1);
          lcd.print("  Backward Speed");
          setBackwardSpeed();
          break;
        case 3: 
          lcd.setCursor(0,1);
          lcd.print("     Servo Speed");
          setServoSpeed();
          break;
        case 4: 
          lcd.setCursor(0,1);
          lcd.print("           Delay");
          setDelay();
          break;
        case 5: select = 1;
          break;
        }
        if (down()) {
          delay(200);
          select++;
        }
        else if (up()) {
          delay(200);
          select--;
        }
        else if (btnback()) {
          lcd.clear();
          back = 1;
          return robotA();
        }
     }
  }
  
}

void runAvoider() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Jalankan Robot");
      lcd.setCursor(0,1);
      lcd.print("AVOIDER ?");
      if (btnselect()) {
          lcd.clear();
          delay(200);
          runA();
      }
      else if (btnback()) {
          lcd.clear();
          back = 1;
          return robotA();
        }
    }
  }
}