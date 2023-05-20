int potenziometro = 10;

float lettura = 0;

float costanteMoltiplicazione = 0.249023;

float outputDigitale = 0;

void setup() {
  pinMode(potenziometro, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lettura = analogRead(0);

  outputDigitale = lettura * 0.249023;

  Serial.println(outputDigitale);

  delay(100);
}
