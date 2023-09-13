/*  Esempio creato partendo dal codice: "Arduino UNO running 4-digit 7-segment display". 
    http://www.hobbytronics.co.uk/arduino-4digit-7segment
    di pubblico dominio (meglio  beerware: offri una birra all'autore

    Questo è un esempio per pilotare un display 7 segmenti con 4 elementi
    senza usare resistenze. Questa tecnica è molto diffusa ma devi sapere
    che eventuali errori possono portare ad un sovraccarico di corrente
    con il rischio di bruciare qualche segmento del display (basta porre attenzione
    al valore di luminosità). 
 
*/
#define DIGIT_ON  LOW // E' un modello a Anodo Comune
#define DIGIT_OFF  HIGH
// -----------------------------------------------------------------
// PIN della fila in basso del display ==> e,d,dp,c,g,4
// -----------------------------------------------------------------
// La parte bassa corrisponde a quella dove ho il punto decimale
// La numerazione del modulo "Display a 7 segmenti" con 4 elementi 
// va da sinistra a destra
int segE = 13;  // Primo PIN
int segD = 12;  // Secondo PIN 
int segDP = 11; // Terzo PIN
int segC = 10;  // Quarto PIN
int segG = 9;   // Quinto PIN
int digit4 = 8; // Sesto PIN - PWM che Accende il quarto digit
// -----------------------------------------------------------------
// PIN della fila in alto del display ==> 1,a,f,2,3,b 
// -----------------------------------------------------------------
// La numerazione del modulo "Display a 7 segmenti" con 4 elementi 
// va da sinistra a destra
int digit1 = 7; // Dodicesimo PIN - PWM che Accende il primo digit
int segA =  6;  // Undicesimo PIN
int segF = 5;   // Decimo PIN
int digit2 = 4; // Nono PIN - PWM che Accende il secondo digit 
int digit3 = 3; // Ottavo PIN - PWM che Accende il terzo digit 
int segB = 2;   // Settimo PIN

void setup() 
{
    // Imposto titti i pin come output  
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
}

void loop() 
{
    displayNumber(millis()/1000);
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

// Accende i segmenti specifici per ottenere la corretta 
// visualizzazione del numero passato come parametro
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
        break;
    }
}