/*
#include <Arduino.h>


enum State {
  BOTH_OFF,
  LED1_ON,
  LED2_ON,
  BOTH_ON
};

// Define pins that have the external LEDS
const int LED1_pin = 15; 
const int LED2_pin = 16;

// Define the pin the button is on
const int BUTTON_PIN = 17;

int counter = 0;

// button handler function, if the button is pressed increment the state
void readButton() {
    if (digitalRead(BUTTON_PIN) == HIGH) {
      updateCounter();
    }
  
    // need delay for debouncing? 
}
  
  // Simple counter for 4 values (0,1,2,3), wraps around
void updateCounter() {
    if (counter < 3) {
      counter++;
    }
    else {
      counter = 0;
    }
}
  
void changeState() {
    // TODO: could track state instead of calling this every loop
    switch (counter) {
      case BOTH_OFF:
        digitalWrite(LED1_pin, LOW);
        digitalWrite(LED2_pin, LOW);
        break;
      
      case LED1_ON:
        digitalWrite(LED1_pin, HIGH);
        digitalWrite(LED2_pin, LOW);
        break;
      
      case LED2_ON:
        digitalWrite(LED1_pin, LOW);
        digitalWrite(LED2_pin, HIGH);
        break;
      
      case BOTH_ON:
        digitalWrite(LED1_pin, HIGH);
        digitalWrite(LED2_pin, HIGH);
        break;
    }
}
  

void setup() {
  Serial.begin(9600);
  Serial.println("------- Hello FLX Solutions Project ----------");
  Serial.println("TTGO T7 V1.4 Mini32 LED Blink Example");

  // Set the LED pin as an output
  pinMode(BUILTIN_LED, OUTPUT);

}

void loop() {
   
  // check button
  readButton();

  // update state
  changeState();
}
*/