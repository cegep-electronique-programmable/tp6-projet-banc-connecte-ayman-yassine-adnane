#include <Arduino.h>

#include <Wire.h>
#include "APDS9930.h"
#include "LEDAYMAN.h"


#define inputchargeur D3  // pin utilisé pour recevoir les informations de charge

APDS9930 capteur = APDS9930();
void setup() {
  Serial.begin(9600);

  // initialisation LED
  pinMode(inputchargeur, INPUT);
  initBandeLED();
  

  Wire.begin(D2, D1); //  SDA, SCL
  // initialisation capteur
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



  
}


void loop() {
  float lux = 20;
  uint16_t proximite = 0;

  int etat = digitalRead(inputchargeur);
      
  updateBandeLED(etat == LOW);  // faire l'update des leds
  
  if (lux < 10) 
  {
      setLumiLED(50);
  }
  else
  {
      setLumiLED(100);
  }
  
  

  if (capteur.readAmbientLightLux(lux))  // lire luminosite
  {
    Serial.print("Luminosite (lux): ");
    Serial.println(lux);
  } 
  else 
  {
    Serial.println("Erreur de lecture de la luminosite");
  }

  if (capteur.readProximity(proximite))  // lire proximite
  {
    Serial.print("Proximite : ");
    Serial.println(proximite);
  } 
  else 
  {
    Serial.println("Erreur de lecture de la proximite");
  }

  delay(500);



  
    

}
