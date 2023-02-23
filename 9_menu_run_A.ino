int readPing(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  Serial.println(distanceCm);
  return distanceCm;
}
int lookRight()     
{  
  myservo.write(60);
  delay(500);
  readPing();
  delay(100);
  myservo.write(120);
  return readPing();
  
}

int lookLeft()      
{
  myservo.write(180);
  delay(500);
  readPing();
  delay(100);
  myservo.write(120);
  return readPing();

}
void moveStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void moveForward(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void moveBackward(){
  int backspeed = EEPROM.read(address4);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA,backspeed);
  analogWrite(ENB,backspeed);
}
void moveTurnLeft(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA,255);
  analogWrite(ENB,255);
}
void moveTurnRight(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA,255);
  analogWrite(ENB,255);
  
}
void runA(){
  int acc = EEPROM.read(address6);
  int dist = EEPROM.read(address3);
  int dlyservo = EEPROM.read(address5);  
  while (1){
    readPing();
//    if (btnback()) {
//      moveStop();
//      back = 1;
//      return runAvoider();
//    }
    if (btnback()) {
          moveStop();
          back = 1;
          return runAvoider();
        }
    while (distanceCm >= dist){
      readPing();
      moveForward();
      //Serial.println(distanceCm);
      if (acc < 255) {
        if (acc >= 255) {
          acc = 255;
          //Serial.println(acc);
        }
        else {
          acc++;
          //Serial.println(acc);
        }
      analogWrite(ENA,acc);
      analogWrite(ENB,acc);
      }
     if (btnback()) {
        moveStop();
        back = 1;
        return runAvoider();
      }
    }
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    int distanceRight = lookRight();
    delay(300);
    //delay(dlyservo);
    int distanceLeft = lookLeft();
    delay(300);
    //delay(dlyservo);
    if (distanceRight >= distanceLeft)
    {
      moveTurnRight();
      delay(800);
      moveStop();
    }
    else
    {
      moveTurnLeft();
      delay(800);
      moveStop();
    }
   if (btnback()) {
        moveStop();
        back = 1;
        return runAvoider();
      }
  }
}
