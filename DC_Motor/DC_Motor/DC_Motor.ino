// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

float lettura = 0;

const float costanteMoltiplicazione = 0.249023;

float outputDigitale = 0;


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void loop() {
  lettura = analogRead(5);

  outputDigitale = lettura * costanteMoltiplicazione;
  Serial.println(outputDigitale);
  analogWrite(enA, outputDigitale);
  delay(20);
}


void activateMotor(){
  lettura = analogRead(0);

  outputDigitale = lettura * 0.249023;

  analogWrite(enA, outputDigitale);
}

void directionControl(){
  analogWrite(enA, 255);

  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
  delay(2000);

  //digitalWrite(in1, LOW);
	//digitalWrite(in2, HIGH);
  //delay(2000);

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void speedControl() {
	// Turn on motors
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}