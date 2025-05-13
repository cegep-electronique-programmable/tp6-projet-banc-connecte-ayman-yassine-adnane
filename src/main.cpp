#include <Arduino.h>
#include "affichage.h"
#include "LEDAYMAN.h" 
#include "Adafruit_NeoPixel.h"


#define PIN         6
#define NUMPIXELS   8

Adafruit_NeoPixel bande(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  bande.begin();               
  bande.setBrightness(100);    
  bande.fill(bande.Color(255, 0, 0)); 
  bande.show();  

}

// the loop function runs over and over again forever
void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  // delay(1000);                      // wait for 1second
  // digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  // delay(100);                      // wait for 100ms


}