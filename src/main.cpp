#include <Arduino.h>
#include "LEDAYMAN.h"

#define inputchargeur D2  // pin utilisé pour recevoir les informations de charge

void setup() {
    Serial.begin(9600);
    pinMode(inputchargeur, INPUT);

    initBandeLED();
}

void loop() {
    int etat = digitalRead(inputchargeur);
    
    updateBandeLED(etat == LOW);  // faire l'update des leds

    delay(500);
}
