#include "LEDAYMAN.h"
#include <Adafruit_NeoPixel.h>


#define pinLED D4 // pin data de la bande LED
#define nbLED 10 // nombre de LED


static Adafruit_NeoPixel bande(nbLED, pinLED, NEO_GRB + NEO_KHZ800);

void initBandeLED() {
    bande.begin();
    bande.setBrightness(100);
    bande.show();  // clear au départ
}

void updateBandeLED(bool chargeActive) {
    uint8_t r, g, b;

    if (chargeActive) {
        r = 255; g = 0;   b = 0;   // rouge si en charge
    } else {
        r = 255; g = 255; b = 0;   // jaune si libre
    }

    for (int i = 0; i < nbLED; i++) {
        bande.setPixelColor(i, bande.Color(r, g, b));
    }
    bande.show();
}


void setLumiLED(uint8_t niveau) 
{
    bande.setBrightness(niveau);
    bande.show(); // pour que le changement soit visible
}

