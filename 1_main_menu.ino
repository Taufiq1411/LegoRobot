#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <EEPROM.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

LiquidCrystal_I2C lcd(0x27,16,2);

RF24 radio(48, 47); // CE, CNS

Servo myservo, servoArm, servoGrip;

int mtrspd=0;
int mtrspeed=0;
int distance=0;
int backward=0;
int servospeed=0;
int acceleration = 0;
int thresHold=0;
int thresHoldlcd;
int address0 = 0;
int address1 = 1;
int address2 = 2;
int address3 = 3;
int address4 = 4;
int address5 = 5;
int address6 = 6;


int trigPin = 46;
int echoPin = 44;
long duration;
int distanceCm;

char back;

int IN1 = 30;
int IN2 = 27;
int IN3 = 29;
int IN4 = 31;
int ENA = 10;
int ENB = 12;

//AFD
int joystickX;
int joystickY;
int x;
int y;
int speedRight;
int speedLeft;
int action1, action2, action3, action4;
int servoArmPos = 90;//servo position
int servoGripPos = 0;//servo position
const byte addressNRF[6] = {8,4,5,2,1};

int algo=0;
int sensor[4];

void setup() {
  //AFD
  radio.begin();
  radio.openReadingPipe(0, addressNRF);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  servoArm.attach(11);
  servoGrip.attach(13);
  
  myservo.attach(9); 
  myservo.write(120);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  pinMode(A6, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(28, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to Robot Lego");
  lcd.setCursor(1,1);
  lcd.print("Fun and Enjoy");
  delay(3000);
  lcd.clear();
}

bool btnback() {
  int valueback = digitalRead(18);
  return !valueback;
}

bool up() {
  int valueup = digitalRead(24);
  return !valueup;
}

bool down() {
  int valuedown = digitalRead(26);
  return !valuedown;
}

bool btnselect() {
  int valueselect = digitalRead(28);
  return !valueselect;
}

void robotKW() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menghubungkan   ");
    lcd.setCursor(0,1);
    lcd.print("ke Remot.");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ke Remot..");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ke Remot...");
    delay(2000);
    lcd.clear();
    while (1) {
    wirelessRobot();
//      if (btnselect()) {
//          lcd.clear();
//          delay(200);
//      }
      if (btnback()) {
          lcd.clear();
          return main_menu();
      }
    }
  }
}

void robotLF() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LINE FOLLOWER");
    while (1) {
      switch (select) {
        case 0: 
          select = 4;
          break;
        case 1:
          lcd.setCursor(0,1);
          lcd.print("      Jalankan->");
          setRun();
          break;
        case 2:
          lcd.setCursor(0,1);
          lcd.print("            Coba"); 
          setTry();
          break;
        case 3: 
          lcd.setCursor(0,1);
          lcd.print("      Pengaturan"); 
          setting();
          break;
        case 4: 
          lcd.setCursor(0,1);
          lcd.print("             Cek");
          setCheck();
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
          return main_menu();
        }
    }
  }
}

void robotA() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AVOIDER");
    while (1) {
      switch (select) {
        case 0: 
          select = 2;
          break;
        case 1:
          lcd.setCursor(0,1);
          lcd.print("        Jalankan"); 
          runAvoider();
          break;
        case 2:
          lcd.setCursor(0,1);
          lcd.print("      Pengaturan");
          setAvoider();
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
          return main_menu();
        }
    }
  }
}

void robotTW() {
  char select = 1;
  if (btnselect() || back == 1) {
    delay(200);
    back = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menghubungkan   ");
    lcd.setCursor(0,1);
    lcd.print("ke Remot.");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ke Remot..");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ke Remot...");
    delay(2000);
    lcd.clear();
    while (1) {
    wirelessRobot();
      if (btnback()) {
          lcd.clear();
          return main_menu();
      }
    }
  }
}

void main_menu() {
  char select = 1;
  lcd.setCursor(0,0);
  lcd.print("PILIH ROBOT");
  while (1) {
    switch (select) {
      case 0: 
        select = 4;
        break;
      case 1:
        lcd.setCursor(0,1);
        lcd.print("Kendali Wireless");
        robotKW();
        break;
      case 2:
        lcd.setCursor(0,1);
        lcd.print("   Line Follower");  
        robotLF();
        break;
      case 3: 
        lcd.setCursor(0,1);
        lcd.print("         Avoider");
        robotA();
        break;
      case 4: 
        lcd.setCursor(0,1);
        lcd.print("     Transporter");
        robotTW();
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
  }
}


void loop() {
  main_menu();
}
