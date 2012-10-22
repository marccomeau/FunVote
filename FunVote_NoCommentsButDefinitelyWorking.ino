const int button1Pin = 0; // Button for option 1
const int button2Pin = 1; // Button for option 2
const int b1led1Pin =  2;      // the number of the LED pin
const int b1led2Pin =  3;      // the number of the LED pin
const int b1led3Pin =  4;      // the number of the LED pin
const int b1led4Pin =  5;      // the number of the LED pin
const int b1led5Pin =  6;      // the number of the LED pin
const int b2led1Pin =  7;      // the number of the LED pin
const int b2led2Pin =  8;      // the number of the LED pin
const int b2led3Pin =  9;      // the number of the LED pin
const int b2led4Pin =  10;      // the number of the LED pin
const int b2led5Pin =  11;      // the number of the LED pin


// variables will change:
int button1State = 0;         // button 1 status
int button2State = 0;         // button 1 status
float vote1 = 0;
float vote2 = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;

void setup() {
  // initialize LEDs as output:
  pinMode(b1led1Pin, OUTPUT);      
  pinMode(b1led2Pin, OUTPUT);      
  pinMode(b1led3Pin, OUTPUT);      
  pinMode(b1led4Pin, OUTPUT);      
  pinMode(b1led5Pin, OUTPUT);      
  pinMode(b2led1Pin, OUTPUT);      
  pinMode(b2led2Pin, OUTPUT);      
  pinMode(b2led3Pin, OUTPUT);      
  pinMode(b2led4Pin, OUTPUT);      
  pinMode(b2led5Pin, OUTPUT);
  // initialize pushbutton pins as input:
  pinMode(button1Pin, INPUT);    
  pinMode(button2Pin, INPUT);    

}

void loop(){
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (button1State == LOW) { 
     currentState1 = 1;
    if(currentState1 != previousState1) {    
      //increment
      vote1++;
    }   
  }
  else if (button1State == HIGH) {
    currentState1 = 0;
  }
  previousState1 = currentState1;
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:

  if (button2State == LOW) { 
     currentState2 = 1;
    if(currentState2 != previousState2) {    
      //increment
      vote2++;
    }   
  }
  else if (button2State == HIGH) {
    currentState2 = 0;
  }
  previousState2 = currentState2;





  //now do the math for percentages
  if (vote1/(vote1+vote2) > 0.85) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, HIGH);
    digitalWrite(b1led4Pin, HIGH);
    digitalWrite(b1led5Pin, HIGH);
    
    digitalWrite(b2led1Pin, LOW);
    digitalWrite(b2led2Pin, LOW);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  else if (vote1/(vote1+vote2) > 0.67) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, HIGH);
    digitalWrite(b1led4Pin, HIGH);
    digitalWrite(b1led5Pin, LOW);

    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, LOW);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  else if (vote1/(vote1+vote2) > 0.50) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, HIGH);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
    
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  else if (vote1/(vote1+vote2) > 0.34) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
    
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, HIGH);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  else if (vote1/(vote1+vote2) > 0.17) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, LOW);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
    
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, HIGH);
    digitalWrite(b2led4Pin, HIGH);
    digitalWrite(b2led5Pin, LOW);
  }
  else if (vote1/(vote1+vote2) > 0) {
    digitalWrite(b1led1Pin, LOW);
    digitalWrite(b1led2Pin, LOW);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
    
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, HIGH);
    digitalWrite(b2led4Pin, HIGH);
    digitalWrite(b2led5Pin, HIGH);  
  }

  delay(250);
}


/*  
  if (vote1 == 1) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, LOW);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
  }
  if (vote1 == 2) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
  }
  if (vote1 == 3) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, HIGH);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
  }  
  
  
  if (vote2 == 1) {
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, LOW);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  if (vote2 == 2) {
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }
  if (vote2 == 3) {
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, HIGH);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
  }  
*/





/*
if (vote1 > vote2) {
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b1led3Pin, HIGH);
    digitalWrite(b1led4Pin, HIGH);
    digitalWrite(b1led5Pin, HIGH);

    digitalWrite(b2led1Pin, LOW);
    digitalWrite(b2led2Pin, LOW);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
}
else if (vote2 > vote1) {
    digitalWrite(b1led1Pin, LOW);
    digitalWrite(b1led2Pin, LOW);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
  
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b2led3Pin, HIGH);
    digitalWrite(b2led4Pin, HIGH);
    digitalWrite(b2led5Pin, HIGH);
  }
else if (vote1 == vote2) {
    digitalWrite(b2led1Pin, HIGH);
    digitalWrite(b2led2Pin, HIGH);
    digitalWrite(b1led3Pin, LOW);
    digitalWrite(b1led4Pin, LOW);
    digitalWrite(b1led5Pin, LOW);
    
    digitalWrite(b1led1Pin, HIGH);
    digitalWrite(b1led2Pin, HIGH);
    digitalWrite(b2led3Pin, LOW);
    digitalWrite(b2led4Pin, LOW);
    digitalWrite(b2led5Pin, LOW);
}
*/

