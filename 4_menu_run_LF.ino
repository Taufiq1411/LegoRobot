void runLine() {  
   while (1) {
    sensor[0] = analogRead(A0); //kiri
    sensor[1] = analogRead(A2); //tengah
    sensor[2] = analogRead(A4); //tengah
    sensor[3] = analogRead(A6); //kanan
    thresHold = EEPROM.read(address1);
    mtrspeed = EEPROM.read(address0);
//    lcd.setCursor(0,0);
//    lcd.print("Threshold : ");
//    lcd.print(thresHold*4);
//    lcd.setCursor(0,1);
//    lcd.print("MotorSpeed : ");
//    lcd.print(mtrspeed);
//    lcd.print("  ");
      lcd.setCursor(0,0);
      lcd.print(sensor[0]);
      lcd.setCursor(4,0);
      lcd.print(sensor[1]);
      lcd.setCursor(9,0);
      lcd.print(sensor[2]);
      lcd.setCursor(13,0);
      lcd.print(sensor[3]);
//      lcd.setCursor(0,1);
//      lcd.print("Threshold : ");
//      lcd.print(thresHold*4);
//    float mtrspeed = EEPROM.read(address);
        // lurus
        if (sensor[1] < thresHold*4 && sensor[2] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.55);
          analogWrite(ENB, mtrspeed*2.55);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Jalan Lurus     ");
        }
        // sensor kiri terbaca, belok kiri
        else if (sensor[0] < thresHold*4 && sensor[1] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.55);
          analogWrite(ENB, mtrspeed*1.27);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Belok Kiri      ");
        }
        // sensor kanan terbaca, belok kanan
        else if (sensor[2] < thresHold*4 && sensor[3] < thresHold*4) {
          analogWrite(ENA, mtrspeed*1.27);
          analogWrite(ENB, mtrspeed*2.55);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Belok Kanan     ");
        }
        // sensor kiri terbaca, belok kiri tajam
        else if (sensor[0] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.55);
          analogWrite(ENB, mtrspeed*2.55);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Belok Kiri      ");
        }
        // sensor kanan terbaca, belok kanan tajam
        else if (sensor[3] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.55);
          analogWrite(ENB, mtrspeed*2.55);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Belok Kanan     ");
        }
        // terbaca hanya 1 sensor lurus kiri, lurus agak nganan
        else if (sensor[1] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.3);
          analogWrite(ENB, mtrspeed*2.55);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Lurus Nganan    ");
        }
        // terbaca hanya 1 sensor lurus kanan, lurus agak ngiri
        else if (sensor[2] < thresHold*4) {
          analogWrite(ENA, mtrspeed*2.55);
          analogWrite(ENB, mtrspeed*2.3);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Lurus Ngiri     ");
        }
        // berhenti jika di kotak
        else if (sensor[0] < thresHold*4 && sensor[1] < thresHold*4 && sensor[2] < thresHold*4 && sensor[3] < thresHold*4) {
          analogWrite(ENA, mtrspeed*0);
          analogWrite(ENB, mtrspeed*0);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          lcd.setCursor(0,1);
          lcd.print("Berhenti di Kotak");
        }
        //jika sensor kanan dan kiri membaca
        else if (sensor[0] < thresHold*4 && sensor[3] < thresHold*4) {
            if (algo == 0) {
              // belok kiri
              analogWrite(ENA, mtrspeed*2.55);
              analogWrite(ENB, mtrspeed*2.55);
              digitalWrite(IN1, HIGH);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, LOW);
              digitalWrite(IN4, LOW);
            }
            else if (algo == 1) {
              // belok kanan
              analogWrite(ENA, mtrspeed*2.55);
              analogWrite(ENB, mtrspeed*2.55);
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
            }
        }

        
//        // stuck lurus, baca kiri, mundur dikit, belok kiri
//        else if (sensor[0] > thresHold*4) {
//          analogWrite(ENA, mtrspeed*2.55);
//          analogWrite(ENB, mtrspeed*2.55);
//          digitalWrite(IN1, HIGH);
//          digitalWrite(IN2, LOW);
//          digitalWrite(IN3, LOW);
//          digitalWrite(IN4, HIGH);
//          if (sensor[0] > thresHold*4 && sensor[1] > thresHold*4 && sensor[2] > thresHold*4) {
//            analogWrite(ENA, mtrspeed*2.55);
//            analogWrite(ENB, mtrspeed*2.55);
//            digitalWrite(IN1, LOW);
//            digitalWrite(IN2, HIGH);
//            digitalWrite(IN3, LOW);
//            digitalWrite(IN4, LOW);
//            }
//        }
//        // stuck lurus, baca kanan, mundur dikit, belok kanan
//        else if (sensor[0] > thresHold*4) {
//          analogWrite(ENA, mtrspeed*2.55);
//          analogWrite(ENB, mtrspeed*2.55);
//          digitalWrite(IN1, HIGH);
//          digitalWrite(IN2, LOW);
//          digitalWrite(IN3, LOW);
//          digitalWrite(IN4, HIGH);
//          if (sensor[1] > thresHold*4 && sensor[2] > thresHold*4 && sensor[3] > thresHold*4) {
//            analogWrite(ENA, mtrspeed*2.55);
//            analogWrite(ENB, mtrspeed*2.55);
//            digitalWrite(IN1, LOW);
//            digitalWrite(IN2, LOW);
//            digitalWrite(IN3, HIGH);
//            digitalWrite(IN4, LOW);
//          }
//        }
//        else {
//          analogWrite(ENA, mtrspeed*2.55);
//          analogWrite(ENB, mtrspeed*2.55);
//          digitalWrite(IN1, LOW);
//          digitalWrite(IN2, LOW);
//          digitalWrite(IN3, LOW);
//          digitalWrite(IN4, LOW);
//          lcd.setCursor(0,1);
//          lcd.print("Berhenti        ");
//        }
        if (btnback()) {
            analogWrite(IN1, 0);
            analogWrite(IN2, 0);
            analogWrite(IN3, 0);
            analogWrite(IN4, 0);
          back = 1;
          return setRun();
        }
     }
}
