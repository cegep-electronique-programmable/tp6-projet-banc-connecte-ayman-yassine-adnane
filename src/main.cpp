#include <Arduino.h>

#include "affichage.h"
#include <Wire.h>
#include "APDS9930.h"


APDS9930 capteur = APDS9930();
void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1); //  SDA, SCL

  

  if (capteur.init()) 
  {
    Serial.println("Capteur initialise avec succes");
  } 
  else 
  {
    Serial.println("Echec de l'initialisation du capteur");
    
  }

  capteur.enableLightSensor(false);
  capteur.enableProximitySensor(false);
  delay(500);

  
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  float lux = 0;
  uint16_t proximite = 0;

  if (capteur.readAmbientLightLux(lux)) 
  {
    Serial.print("Luminosite (lux): ");
    Serial.println(lux);
  } 
  else 
  {
    Serial.println("Erreur de lecture de la luminosite.");
  }

  if (capteur.readProximity(proximite)) 
  {
    Serial.print("Proximite : ");
    Serial.println(proximite);
  } 
  else 
  {
    Serial.println("Erreur de lecture de la proximite.");
  }

  delay(500);



#include "LEDAYMAN.h"

#define inputchargeur D3  // pin utilisé pour recevoir les informations de charge

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
