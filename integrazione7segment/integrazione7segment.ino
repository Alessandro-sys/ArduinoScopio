#define DIGIT_ON  LOW 
#define DIGIT_OFF  HIGH


// Setup ponte H
int enA = 49;
int in1 = 51;
int in2 = 53;




// Setup Bottoni
#define buttonAdd 22
#define buttonSub 23
#define buttonChange 25

// Setup variabili potenza motori
const float maxPower = 255.0;
float motorPower = 255.0;
float percentage = 100.0;
float changeRate = 0.5;


// Setup 7segment
int segE = 13;  // Primo PIN
int segD = 12;  // Secondo PIN 
int segDP = 11; // Terzo PIN
int segC = 10;  // Quarto PIN
int segG = 9;   // Quinto PIN
int digit4 = 8; // Sesto PIN - PWM che Accende il quarto digit


int digit1 = 7; // Dodicesimo PIN - PWM che Accende il primo digit
int segA =  6;  // Undicesimo PIN
int segF = 5;   // Decimo PIN
int digit2 = 4; // Nono PIN - PWM che Accende il secondo digit 
int digit3 = 3; // Ottavo PIN - PWM che Accende il terzo digit 
int segB = 2;   // Settimo PIN

int oldButton = 0;

void setup() {
  pinMode(buttonAdd, INPUT);
  pinMode(buttonSub, INPUT);
  pinMode(buttonChange, INPUT);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  // Pin relativi all'elemento
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  // Spengo tutti gli elementi
  digitalWrite(digit1, DIGIT_OFF);
  digitalWrite(digit2, DIGIT_OFF);
  digitalWrite(digit3, DIGIT_OFF);
  digitalWrite(digit4, DIGIT_OFF);

  // Setup pin ponte H
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  analogWrite(enA, motorPower);
  int pressedButton = getKey();

  

  if (pressedButton != 0)
  {
    if (pressedButton == oldButton)
    {
      oldButton = pressedButton;
      pressedButton = 0;
    }
    else
    {
      oldButton = pressedButton;
    }
  }
  else
  {
    oldButton = 0;
  }
  
  Serial.println(pressedButton);

 
  pressedKey(pressedButton, motorPower, percentage);

  if (pressedButton == 3)
  {
    for (int i = 0; i < 80; i++)
    {
      if (changeRate != 0.5)
      {
        displayNumber(changeRate * 10);
      }
      else
      {
        displayNumber(5);
      }
    }
  }

  displayNumber(percentage * 10);
}







int getKey(){
  if (digitalRead(buttonAdd) == HIGH)
  {
    //Serial.println("bottone premuto 1");
    return 1;
  }
  else if (digitalRead(buttonSub) == HIGH)
  {
    //Serial.println("bottone premuto 2");
    return 2;
  }
  else if (digitalRead(buttonChange) == HIGH)
  {
    //Serial.println("bottone premuto 3");
    return 3;
  }
  else
  {
    return 0;
  }
}









void displayNumber(int toDisplay)
{
#define DISPLAY_BRIGHTNESS  20000
#define SPEGNI 10

  // Ogni elemento rimane accesso per 20 millisecondi dopo di che viene spento
  for (int digit = 4 ; digit > 0 ; digit--)
  {
      if (digit==4)
          digitalWrite(digit4, DIGIT_ON);
      else if (digit==3)
          digitalWrite(digit3, DIGIT_ON);
      else if (digit==2)
          digitalWrite(digit2, DIGIT_ON);
      else if (digit==1)
          digitalWrite(digit1, DIGIT_ON);


      if (digit == 3)
        digitalWrite(segDP, HIGH);
      // Mostra il resto della divisione per 10 sull'elemento posto ad ON
      MostraSingoloNumero(toDisplay % 10);
      
      // Lascia l'elemento ON per una breve frazione di secondo
      delayMicroseconds(DISPLAY_BRIGHTNESS); 
      // Spegne tutti i segmenti del display selezionato
      MostraSingoloNumero(SPEGNI); 

      toDisplay /= 10; // Aggiorna il numero dividendolo per 10 (divisione intera)
 
      // Disattivo tutti i digit
      digitalWrite(digit1, DIGIT_OFF);
      digitalWrite(digit2, DIGIT_OFF);
      digitalWrite(digit3, DIGIT_OFF);
      digitalWrite(digit4, DIGIT_OFF);
  }
}


void MostraSingoloNumero(int n) 
{
  #define SEGMENT_ON  HIGH
  #define SEGMENT_OFF LOW

  switch (n)
  {

    case 0:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_ON);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_OFF);
        break;
  
    case 1:
        digitalWrite(segA, SEGMENT_OFF);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_OFF);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_OFF);
        digitalWrite(segG, SEGMENT_OFF);
        break;
  
    case 2:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_OFF);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_ON);
        digitalWrite(segF, SEGMENT_OFF);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 3:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_OFF);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 4:
        digitalWrite(segA, SEGMENT_OFF);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_OFF);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 5:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_OFF);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 6:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_OFF);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_ON);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 7:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_OFF);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_OFF);
        digitalWrite(segG, SEGMENT_OFF);
        break;
  
    case 8:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_ON);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 9:
        digitalWrite(segA, SEGMENT_ON);
        digitalWrite(segB, SEGMENT_ON);
        digitalWrite(segC, SEGMENT_ON);
        digitalWrite(segD, SEGMENT_ON);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_ON);
        digitalWrite(segG, SEGMENT_ON);
        break;
  
    case 10: // Tutto spento
        digitalWrite(segA, SEGMENT_OFF);
        digitalWrite(segB, SEGMENT_OFF);
        digitalWrite(segC, SEGMENT_OFF);
        digitalWrite(segD, SEGMENT_OFF);
        digitalWrite(segE, SEGMENT_OFF);
        digitalWrite(segF, SEGMENT_OFF);
        digitalWrite(segG, SEGMENT_OFF);
        digitalWrite(segDP, SEGMENT_OFF);
        break;
    }
}

void pressedKey(int key, float & motorPower, float & percentage){
  if (key == 2)
  {
    if (motorPower > 0.5)
    {
      motorPower = motorPower - changeRate;
      percentage = motorPower / 2.55;
    }
  }
  else if (key == 1)
  {
    if (motorPower < 255.0)
    {
      motorPower = motorPower + changeRate;
      percentage = motorPower / 2.55;
    }
  }
  else if (key == 3)
  {
    if (changeRate == 0.5)
    {
      changeRate = 1.0;
      
    }
    else if (changeRate == 1.0)
    {
      changeRate = 5.0;
    }
    else if (changeRate == 5.0)
    {
      changeRate = 0.5;
    }
  }
}