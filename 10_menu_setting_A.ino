void setDistance() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address3) == 0) {
        distance = 5;
      }
      else if (EEPROM.read(address3) != 0) {
        distance = EEPROM.read(address3);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print("cm  ");
      if (down()) {
        delay(200);
        if (distance<50) {
          distance = distance + 5;
        }
      }
      else if (up()) {
        delay(200);
        if (distance>5) {
          distance = distance - 5;
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address3, distance);
        back = 1;
        return setAvoider();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setAvoider();
      }
    }
  }

}
void setBackwardSpeed() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address4) == 0) {
        backward = 100;
      }
      else if (EEPROM.read(address4) != 0) {
        backward = EEPROM.read(address4);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Speed: ");
      lcd.print(backward);
      //lcd.print("cm  ");
      if (down()) {
        delay(200);
        if (backward<255) {
          backward = backward + 5;
        }
      }
      else if (up()) {
        delay(200);
        if (backward>50) {
          backward = backward - 5;
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address4, backward);
        back = 1;
        return setAvoider();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setAvoider();
      }
    }
  }
}
void setServoSpeed() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address5) == 0) {
        servospeed = 1000;
      }
      else if (EEPROM.read(address5) != 0) {
        servospeed = EEPROM.read(address5);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Delay Speed: ");
      lcd.print(servospeed);
      //lcd.print("cm  ");
      if (down()) {
        delay(200);
        if (servospeed<1000) {
          servospeed = servospeed + 100;
        }
      }
      else if (up()) {
        delay(200);
        if (servospeed>100) {
          servospeed = servospeed - 100;
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address5, servospeed);
        back = 1;
        return setAvoider();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setAvoider();
      }
    }
  }
}
void setDelay() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
      if (EEPROM.read(address6) == 0) {
        acceleration = 50;
      }
      else if (EEPROM.read(address6) != 0) {
        acceleration = EEPROM.read(address6);
      }
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Delay: ");
      lcd.print(acceleration);
      //lcd.print("cm  ");
      if (down()) {
        delay(200);
        if (acceleration<50) {
          acceleration = acceleration + 10;
        }
      }
      else if (up()) {
        delay(200);
        if (acceleration>10) {
          acceleration = acceleration - 10;
        }
      }
      else if (btnselect()) {
        delay(200);
        EEPROM.update(address6, acceleration);
        back = 1;
        return setAvoider();
      }
      else if (btnback()) {
        lcd.clear();
        back = 1;
        return setAvoider();
      }
    }
  }
}