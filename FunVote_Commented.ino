

// This code was written to create a physical voting system with live feedback
// It's meant to be for interactive surveys.  On the wall, walk up and press a button
// We put this together Thursday afternoon, October 18, 2012 
// for the Hackfest at Access 2012 in Montreal, Quebec
// We had a blast finding parts, building and coding.
// Thanks to ABRA Electronics http://www.abra-electronics.com/ 
// for having all of the gear we needed to buy and being an overall awesome store
// This code was put together drawing from a few examples.
// Thanks to the Sparkfun Arduino kit manual
// Thanks to Arduino tutorial http://www.arduino.cc/en/Tutorial/button
// Thanks to Todd Holoubek's tutorial http://www.toddholoubek.com/classes/pcomp/?page_id=58

// By Marc Comeau, Sarah Simpkin and Corey Ha

// Setting up the pin numbers on the Arduino for buttons and LEDs
const int button1Pin = 0;
const int button2Pin = 1;
// Set of LEDs for button 1
const int b1led1Pin =  2;
const int b1led2Pin =  3;
const int b1led3Pin =  4;
const int b1led4Pin =  5;
const int b1led5Pin =  6;
// Set of LEDs for button 2
const int b2led1Pin =  7;
const int b2led2Pin =  8;
const int b2led3Pin =  9;
const int b2led4Pin =  10;
const int b2led5Pin =  11;


// Variables that will change
int button1State = 0;
int button2State = 0;
float vote1 = 0;
float vote2 = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;

void setup() {
  // Initialize LEDs as output
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
  // Initialize pushbuttons as input
  pinMode(button1Pin, INPUT);    
  pinMode(button2Pin, INPUT);    

}

void loop(){
  // Read the state of the pushbutton value
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Check if the pushbutton is pressed
  // If it is, the buttonState is LOW
  if (button1State == LOW) { 
    // Have to keep track of button state because pressing the button leaves it in the 
    // low state for hundreds of loops, screwing up the counter.
    currentState1 = 1;
    if(currentState1 != previousState1) {    
      // Increment only if there's a change of state to low.  
      // This way a button press is only counted once
      vote1++;
    }   
  }
  else if (button1State == HIGH) {
    currentState1 = 0;
  }
  previousState1 = currentState1;

  // Do it all over again for the second button
  if (button2State == LOW) { 
     currentState2 = 1;
    if(currentState2 != previousState2) {    
      vote2++;
    }   
  }
  else if (button2State == HIGH) {
    currentState2 = 0;
  }
  previousState2 = currentState2;



  // Now do the math for percentages
  // We've split it this way because we have 6 different bar graph states 
  // using two sets of 5 LEDs
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
