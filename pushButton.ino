/*  State change detection (edge detection)

 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground
 
 Created 1/18/2014 
 by Mark Snyder

Based on example code by Tom Igoe:
 http://arduino.cc/en/Tutorial/ButtonStateChange
 */

// Declaring LED and Pushbutton location constants
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Declaring counter variables
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int ledState = 0;            // current state of the LED

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the pushbutton input pin - either HIGH or LOW
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, check to see if the button went from off to on:
    if (buttonState == HIGH) {
      // if button went from off to on, flop ledState
      ledState = !(ledState | 0);
        
      //read ledState and turn on LED if ledState = 1. turn off if anything else 
      if (ledState == 1){
        digitalWrite(ledPin, HIGH); 
      }
      else {
          digitalWrite(ledPin, LOW);
      } 
      

    }
  
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;
  
  }
}
