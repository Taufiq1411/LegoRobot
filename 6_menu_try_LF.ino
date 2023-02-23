void tkanan() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
  while (1) {
    sensor[0] = analogRead(A0);
    sensor[1] = analogRead(A1);
    sensor[2] = analogRead(A2);
    thresHold = EEPROM.read(address1);
    lcd.setCursor(0,0);
    lcd.print("Threshold : ");
    lcd.print(thresHold*4);
   float DCspeed = EEPROM.read(address0);
        analogWrite(ENA, DCspeed*25.5);
        analogWrite(ENB, DCspeed*25.5);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        if (sensor[2] > thresHold*4) {
          analogWrite(ENA, DCspeed*25.5);
          analogWrite(ENB, DCspeed*25.5);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
        }
        if (btnback()) {
            analogWrite(IN1, 0);
            analogWrite(IN2, 0);
            analogWrite(IN3, 0);
            analogWrite(IN4, 0);
          back = 1;
          return setTry();
        }
       
     }
  }
}

void tkiri() {
  back = 0;
  if (btnselect() || back == 1) {
    delay(200);
    lcd.clear();
  while (1) {
    sensor[0] = analogRead(A0);
    sensor[1] = analogRead(A1);
    sensor[2] = analogRead(A2);
    thresHold = EEPROM.read(address1);
    lcd.setCursor(0,0);
    lcd.print("Threshold : ");
    lcd.print(thresHold*4);
   float DCspeed = EEPROM.read(address0);
        analogWrite(ENA, DCspeed*25.5);
        analogWrite(ENB, DCspeed*25.5);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        if (sensor[0] > thresHold*4) {
          analogWrite(ENA, DCspeed*25.5);
          analogWrite(ENB, DCspeed*25.5);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
        }
        if (btnback()) {
            analogWrite(IN1, 0);
            analogWrite(IN2, 0);
            analogWrite(IN3, 0);
            analogWrite(IN4, 0);
          back = 1;
          return setTry();
        }
       
     }
   }
}
