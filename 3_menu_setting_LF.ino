void motorspd() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address0) == 0) {
        mtrspeed = 10;
      }
      else if (EEPROM.read(address0) != 0) {
        mtrspeed = EEPROM.read(address0);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("MotorSpeed: ");
      lcd.print(mtrspeed);
      lcd.print("%  ");
      if (down()) {
        delay(200);
        if (mtrspeed<=90) {
          mtrspeed = mtrspeed + 10;
//          EEPROM.update(address, mtrspeed);
        }
      }
      else if (up()) {
        delay(200);
        if (mtrspeed>=30) {
          mtrspeed = mtrspeed - 10;
//          EEPROM.update(address, mtrspeed);
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address0, mtrspeed);
        back = 1;
        return setting();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setting();
      }
    }
  }
}

void algorithm() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
      if (EEPROM.read(address2) == 0) {
        algo = 0;
      }
      else if (EEPROM.read(address2) != 0) {
        algo = EEPROM.read(address2);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Algorithm : ");
      lcd.print(algo);
      lcd.print("  ");
      if (down()) {
        delay(200);
        if (algo<1) {
          algo = algo + 1;
//          EEPROM.update(address2, algo);
        }
      }
      else if (up()) {
        delay(200);
        if (algo>=0) {
          algo = 0;
//          EEPROM.update(address2, algo);
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address2, algo);
        back = 1;
        return setting();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setting();
      }
     }
  }
}

void threshold() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address1) == 0) {
        thresHoldlcd = 250;
      }
      else if (EEPROM.read(address1) != 0) {
        thresHoldlcd = map(EEPROM.read(address1),0, 255, 0, 1023)/10*10+10;
      }
    while (1) {
      thresHold = map(thresHoldlcd, 0, 1023, 0, 255) ;
      lcd.setCursor(0,0);
      lcd.print("Threshold : ");
      lcd.print(thresHoldlcd);
      lcd.print(" ");
      if (down()) {
        delay(200);
//        if (thresHoldlcd<=800) {
          thresHoldlcd = thresHoldlcd + 10;
//          EEPROM.update(address1, thresHold);
//        }
      }
      else if (up()) {
        delay(200);
//        if (thresHoldlcd>=200) {
          thresHoldlcd = thresHoldlcd - 10;
//          EEPROM.update(address1, thresHold);
//        }
      }
      else if (btnselect()) {
        delay(200);
         EEPROM.update(address1, map(thresHoldlcd, 0, 1023, 0, 255));
         back = 1;
         return setting();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setting();
      }
    }
  }
}
