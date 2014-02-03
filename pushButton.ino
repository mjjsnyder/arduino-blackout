/*  State change detection (edge detection)

 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 Created 1/18/2014 
 by Mark Snyder

Based on example code by Tom Igoe:
 http://arduino.cc/en/Tutorial/ButtonStateChange
 */

// Declaring LED and Pushbutton location constants
const int buttonPin = 2;    // Oushbutton connected to pin 2
const int ledPin = 13;      // Utilizing onboard LED on pin 13
const int relayPin = 4;     // Power relay connected to pin 4

// Declaring counter variables
int buttonState = 0;         // Current state of the button
int lastButtonState = 0;     // Previous state of the button
int ledState = 0;            // Current state of the LED
int relayState = 0;          // Current state of the power relay

void setup() {
  // Initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // Initialize the LED and power relay as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  
  //Initializes the power relay in the 'off' position
  //NOTE: Power relay must be pulled LOW to activate and HIGH to deactivate
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // Read the pushbutton input pin - either HIGH or LOW
  buttonState = digitalRead(buttonPin);

  // Compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // If the state has changed, check to see if the button went from off to on:
    if (buttonState == HIGH) {
      // if button went from off to on, flop ledState and relayState
      ledState = !(ledState | 0);
      relayState = !(relayState | 0);
        
      //Read ledState and turn on LED if ledState = 1. Turn off if anything else 
      if (ledState == 1){
        digitalWrite(ledPin, HIGH); 
      }
      else {
          digitalWrite(ledPin, LOW);
      }
      
      //Read relayState and turn on power relay if ledState = 1. Turn off if anything else
      if (relayState == 1){
        digitalWrite(relayPin, LOW); 
      }
      else {
          digitalWrite(relayPin, HIGH);
      } 
      
    }
  
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  
  }
}
