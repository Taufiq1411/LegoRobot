void sensorcheck() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
    while (1) {
      sensor[0] = analogRead(A0);
      sensor[1] = analogRead(A2);
      sensor[2] = analogRead(A4);
      sensor[3] = analogRead(A6);
      lcd.setCursor(0,0);
      lcd.print(sensor[0]);
      lcd.setCursor(4,0);
      lcd.print(sensor[1]);
      lcd.setCursor(9,0);
      lcd.print(sensor[2]);
      lcd.setCursor(13,0);
      lcd.print(sensor[3]);
      if (btnback()) {
        lcd.clear();
        back = 1;
        return setCheck();
      }
      delay(100);
    }
  }
}

void logiccheck() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
    while (1) {
       sensor[0] = analogRead(A0);
       sensor[1] = analogRead(A2);
       sensor[2] = analogRead(A4);
       sensor[3] = analogRead(A6);
       byte off[8] = {
          B11111,
          B10001,
          B10001,
          B10001,
          B10001,
          B10001,
          B10001,
          B11111,
       };
       byte on[8] = {
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
       };
      thresHold = map(EEPROM.read(address1), 0, 255, 0, 1023);
      lcd.createChar(0, off);
      lcd.createChar(1, on);
      lcd.setCursor(3,0);
      if (sensor[0] > thresHold) {
        lcd.write(0);
      }
      else if (sensor[0] <= thresHold) {
        lcd.write(1);
      }
      lcd.setCursor(6,0);
      if (sensor[1] > thresHold) {
        lcd.write(0);
      }
      else if (sensor[1] <= thresHold) {
        lcd.write(1);
      }
      lcd.setCursor(9,0);
      if (sensor[2] > thresHold) {
        lcd.write(0);
      }
      else if (sensor[2] <= thresHold) {
        lcd.write(1);
      }
      lcd.setCursor(12,0);
      if (sensor[3] > thresHold) {
        lcd.write(0);
      }
      else if (sensor[3] <= thresHold) {
        lcd.write(1);
      }
      if (btnback()) {
        lcd.clear();
        back = 1;
        return setCheck();
      }
      delay(100);
    }
  }
}
