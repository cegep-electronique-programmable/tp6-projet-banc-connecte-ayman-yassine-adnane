#ifndef LEDAYMAN_H
#define LEDAYMAN_H

#include <Arduino.h>

// initialise les leds
void initBandeLED();

// met la bande en rouge (charge) ou jaune (libre)
void updateBandeLED(bool chargeActive);

#endif
