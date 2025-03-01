#include <Arduino.h>


enum State {
  BOTH_OFF,
  LED1_ON,
  LED2_ON,
  BOTH_ON
};

// Define pins that have the external LEDS
const int LED_PIN_1 = 12; 
const int LED_PIN_2 = 14;

// Define the pin the button is on
const int BUTTON_PIN = 33;

int counter = 0;

int lastState = HIGH; // the previous state from the input pin
int currentState; 

// Simple counter for 4 values (0,1,2,3), wraps around
void updateCounter() {
    if (counter < 3) {
      counter++;
    }
    else {
      counter = 0;
    }
}
// button handler function, if the button is pressed increment the state
void readButton() {

    currentState = digitalRead(BUTTON_PIN);
    if (lastState == LOW && currentState == HIGH) {
      Serial.println("Button Pressed!");
      updateCounter();
      delay(100); // delay for debouncing
    }
    lastState = currentState;
}
  

  
void changeState() {
    // TODO: could track state instead of calling this every loop
    switch (counter) {
      case BOTH_OFF:
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        break;
      
      case LED1_ON:
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, LOW);
        break;
      
      case LED2_ON:
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, HIGH);
        break;
      
      case BOTH_ON:
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        break;

      default:
        break;
    }
}
  

void setup() {
  Serial.begin(9600);
  Serial.println("------- Hello FLX Solutions Project ----------");
  Serial.println("State Machine LED Controller V0.1");

  // Set the LED pin as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

}

void loop() {
   
  // check button
  readButton();

  // update state
  changeState();
}
