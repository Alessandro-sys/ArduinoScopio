#include <Stepper.h>
#include <Keypad.h> 


const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;


// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {

  char pressedKey = keypad.getKey();

  if(pressedKey == 'A') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(15);
	    myStepper.step(1);
    }
  } else if(pressedKey == 'B') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(15);
	    myStepper.step(-1);
    }
  } else if(pressedKey == 'C') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(10);
	    myStepper.step(1);
    }
  } else if(pressedKey == 'D') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(10);
	    myStepper.step(-1);
    }
  } else if(pressedKey == '1') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(5);
	    myStepper.step(1);
    }
  } else if(pressedKey == '2') {
    while (keypad.getKey() != '#'){
      myStepper.setSpeed(5);
	    myStepper.step(-1);
    }
  } else {
    while (keypad.getKey() == '8'){
    myStepper.setSpeed(10);
	  myStepper.step(1);
  }
  }

  
  


	
}