#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#import <string.h>

MPU6050 mpu6050(Wire);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

double x, y, z;

float startingPos = 0;

void setup(){
  Serial.begin(115200);

  lcd.begin(16, 2);


  lcd.print("Calibrating");

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  mpu6050.update();
  startingPos = mpu6050.getAngleX();

  lcd.clear();
}

void loop(){
  mpu6050.update();
  x = mpu6050.getAngleX();
  y = mpu6050.getAngleY();
  z = mpu6050.getAngleZ();

  String printx;
  String printy;
  String printz;

  printx = String(x);
  printy = String(y);
  printz = String(z);
  lcd.setCursor(0, 0);
  //lcd.print( printx + " " + printy + " " + printz);
  lcd.print("Ascensione retta");

  lcd.setCursor(0, 1);
  lcd.print(printz);

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("   ");
  Serial.print("y: ");
  Serial.print(y);
  Serial.print("   ");
  Serial.print("z: ");
  Serial.println(z);


  delay(100);

  lcd.clear();
}