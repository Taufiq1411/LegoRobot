void setting() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PENGATURAN");
    while (1) {
      switch (select) {
        case 0: 
          select = 3;
          break;
        case 1: 
          lcd.setCursor(0,1);
          lcd.print("   Set Kecepatan");
          motorspd();
          break;
        case 2: 
          lcd.setCursor(0,1);
          lcd.print("   Set Algoritma");
          algorithm();
          break;
        case 3: 
          lcd.setCursor(0,1);
          lcd.print("   Set Threshold");
          threshold();
          break;
        case 4: select = 1;
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
          return robotLF();
        }
     }
  }
  
}

void setTry() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("COBA");
    while (1) {
      switch (select) {
        case 0: 
          select = 2;
          break;
        case 1: 
          lcd.setCursor(0,1);
          lcd.print("   Telusur kanan");
          tkanan();
          break;
        case 2: 
          lcd.setCursor(0,1);
          lcd.print("    Telusur kiri");
          tkiri();
          break;
        case 3: select = 1;
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
          return robotLF();
        }
     }
  }
}

void setRun() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    while (1) {
      lcd.setCursor(0,0);
      lcd.print("Jalankan Robot");
      lcd.setCursor(0,1);
      lcd.print("LINE FOLLOWER ?");
      if (btnselect()) {
          lcd.clear();
          delay(200);
          runLine();
      }
      else if (btnback()) {
          lcd.clear();
          back = 1;
          return robotLF();
        }
    }
  }
}

void setCheck() {
  char select = 1;
  if (btnselect() || back == 1) {
    back = 0;
    delay(200);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CEK");
    while (1) {
      switch (select) {
        case 0: 
          select = 2;
          break;
        case 1: 
          lcd.setCursor(0,1);
          lcd.print("      Cek Sensor");
          sensorcheck();
          break;
        case 2:
          lcd.setCursor(0,1);
          lcd.print("      Cek Logika"); 
          logiccheck();
          break;
        case 3: select = 1;
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
          return robotLF();
        }
     }
  }
}
