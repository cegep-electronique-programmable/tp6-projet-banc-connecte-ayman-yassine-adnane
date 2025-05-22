#include <Wire.h>
#include "U8g2lib.h"

// initialisation de l'ecran OLED avec I2C pins: D1 (SCL) et D2 (SDA)
U8G2_SSD1306_128X64_NONAME_F_SW_I2C ecran(U8G2_R0, /* clock=*/ D1, /* data=*/ D2, /* reset=*/ U8X8_PIN_NONE);

// void setup() {
//   ecran.begin(); // INIT
//   ecran.setFont(u8g2_font_ncenB08_tr); // choisir police
// }

// void loop() {
//   ecran.clearBuffer(); // clear les bits de donnees
//   ecran.setCursor(0, 20);  
//   ecran.print("test");
//   ecran.setCursor(0, 40);
//   ecran.print("test 2");
//   ecran.sendBuffer();            // send
//   delay(1000);
//   ecran.clearDisplay();
// }


void afficherInfo(uint16_t nbrPresence, uint16_t nbrCharge)
{
    ecran.clearDisplay(); // clear l'ecran et clear les bits de donnees
    ecran.clearBuffer(); 

    ecran.setCursor(0, 20); // placer le curseur puis print le nombre de personne presentes
    ecran.print("Il y a ");
    ecran.print(nbrPresence);
    ecran.print(" personne(s) presente");

    ecran.setCursor(0, 40); // placer le curseur puis print le nombre de 
    ecran.print("Telephone(s) chargé(s): ");
    ecran.print(nbrCharge);

    ecran.setCursor(0, 50);
    ecran.sendBuffer();  
}   