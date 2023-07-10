#include <Keypad.h>
#include <LiquidCrystal.h>

// Setup LCD
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Setup ponte H
int enA = 12;
int in1 = 11;
int in2 = 10;

// Setup Keypad
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

// Setup variabili potenza motori
const float maxPower = 255.0;
float motorPower = 255.0;
float percentage = 100.0;

void setup()
{
  // Setup LCD, 16 segmenti 2 righe
  lcd.begin(16, 2);
  // Setup pin ponte H
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Setup seriale
  Serial.begin(9600);

  // Inizia a muovere i motori in verso orario
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

}

void loop()
{
  // pulisce lo schermo lcd dal giro precedente
  lcd.clear();
  // imposta la potenza del motore a motorPower. Al primo giro sarà 100% (255) e verrà modificato ogni giro
  analogWrite(enA, motorPower);
  // legge i tasti premuti sul keypad
  char key = keypad.getKey();


  // modifica la potenza del motore in base al tasto premuto
  pressedKey(key, motorPower, percentage);


  // stampa sulla seriale
  serial(motorPower, percentage);
  // stampa sull'LCD
  liquid(motorPower, percentage);
}



void pressedKey( char key, float & motorPower, float & percentage ){
  // Se preme il tasto B diminuisce la velocità di 0.5
  if (key == 'B'){
    if (motorPower > 0.5){
      motorPower = motorPower - 0.5;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al minimo della potenza");
    }
  // Se preme il tasto A aumenta la velocità di 0.5
  } else if (key == 'A'){
    if (motorPower < 255){
      motorPower += 0.5;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al massimo della potenza");
    }
  // Se preme il tasto C aumenta la velocità di 1
  } else if (key == 'C'){
    if (motorPower < 255){
      motorPower += 1;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al massimo della potenza");
    }
  // Se preme il tasto D diminuisce la velocità di 1
  } else if (key == 'D'){
    if (motorPower > 1){
      motorPower = motorPower - 1;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al minimo della potenza");
    }
  // Se preme il tasto 1 mette la velocità del motore al minimo
  } else if (key == '1'){
    motorPower = 1;
    percentage = motorPower / 2.55;
  // Se preme il tasto 5 mette la velocità del motore al 50%
  } else if (key == '5'){
    motorPower = maxPower / 2;
    percentage = motorPower / 2.55;
  // Se preme il tasto 9 mette la velocità del motore al 100%
  } else if (key == '9'){
    motorPower = maxPower;
    percentage = motorPower / 2.55;
  // Se preme il tasto # diminuisce la velocità di 10
  } else if (key == '#'){
    if (motorPower > 10){
      motorPower = motorPower - 10;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al minimo della potenza");
    }
  // Se preme il tasto # aumenta la velocità di 10
  } else if (key == '*'){
    if (motorPower <= 250){
      motorPower = motorPower + 10;
      percentage = motorPower / 2.55;
    } else {
      Serial.println("Sei già al minimo della potenza");
    }
  }
}

void serial(float mp, float p){
  Serial.print("Potenza attuale: ");
  Serial.print(mp);
  Serial.print("    Percentage: ");
  Serial.println(p);
}

void liquid(float mp, float p){
  lcd.setCursor(0, 0);
  lcd.print("perc: ");
  lcd.print(p);
  lcd.setCursor(0, 1);
  lcd.print("speed: ");
  lcd.print(mp);
  delay(50);
}