void wirelessRobot(){
  if (radio.available()) {
    int dataPackage[6] = {};
    radio.read(&dataPackage, sizeof(dataPackage));
    lcd.setCursor(0,0);
    lcd.print("CONNECTED       ");

    joystickX = dataPackage[0];
    joystickY = dataPackage[1];
    action1 = dataPackage[2];
    action2 = dataPackage[3];
    action3 = dataPackage[4];
    action4 = dataPackage[5];

    Serial.print("{");
    for(int i=0; i<6; i++){
      Serial.print(dataPackage[i]);
      Serial.print(", ");
    }
    Serial.println("}");

    joystickAction();
    gripperAction();
  }
  else if (btnback()) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    back = 1;
    return setRun();
  }
  else {
    Serial.println("CONNECTION LOST");
    lcd.setCursor(0,0);
    lcd.print("CONNECTION LOST ");
  }
  delay(15);
}

void gripperAction(){
  if(action1 ==0){    //1 if active high, 0 if active low
    Serial.print("Gripper Turun");
    if (servoArmPos <= 110){
      servoArmPos+=1;
      servoArm.write(servoArmPos);
    }
  }
  else if(action2 == 0){
    Serial.print("Gripper Naik");
    if (servoArmPos > 40){
      servoArmPos-=1;
      servoArm.write(servoArmPos);
    }
  }
  else if(action3 == 0){
    Serial.print("Buka Gripper");
    if (servoGripPos <= 85){
      servoGripPos+=1;
      servoGrip.write(servoGripPos);
    }
  }
  else if(action4 == 0){
    Serial.print("Tutup Gripper");
    if (servoGripPos > 0){
      servoGripPos-=1;
      servoGrip.write(servoGripPos);
    }
  }
}

void joystickAction(){
  if(joystickY < 470) {
    Serial.print("Mundur");
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    speedRight = map(joystickY, 470, 0, 0, 255);
    speedLeft = map(joystickY, 470, 0, 0, 255);
  }
  else if(joystickY > 550) {
    Serial.print("Maju");
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    speedRight = map(joystickY, 550, 1023, 0, 255);
    speedLeft = map(joystickY, 550, 1023, 0, 255);
  }
  else{
    speedRight = 0;
    speedLeft = 0;
  }
  
  if(joystickX < 470) {
    x = map(joystickX, 470, 0, 0, 255);
    Serial.print("kiri");
    speedRight = speedRight - x;
    speedLeft = speedLeft + x;
  
    if (speedRight < 0){
      speedRight = 0;
    }
    if (speedLeft > 255){
      speedLeft = 255;
    }
  }
  
  if(joystickX > 550) {
    x = map(joystickX, 550, 1023, 0, 255);
    Serial.print("kanan");
    speedRight = speedRight + x;
    speedLeft = speedLeft - x;
  
    if (speedRight > 255){
      speedRight = 255;
    }
    if (speedLeft < 0){
      speedLeft = 0;
    }
  }
  
  //prevent buzzing
  if(speedRight < 30){
    speedRight = 0;
  }
  if(speedLeft < 30){
    speedLeft = 0;
  }
  
  analogWrite(ENA, speedRight);
  analogWrite(ENB, speedLeft);
}
