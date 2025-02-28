
#include <Arduino.h>

// Define the pin for the onboard LED
// Define this pin based on how our circuit is wired
const int LED_PIN_1 = 12;
const int LED_PIN_2 = 14;


void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("TTGO T7 V1.4 Mini32 LED Blink Example");
  
  // Set the LED pin as an output
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, HIGH);
  Serial.println("LED 1&2 ON");
  delay(1000); // Wait for 1 second
  
  // Turn the LED off
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  Serial.println("LED 1&2 OFF");
  delay(1000); // Wait for 1 second


}
 