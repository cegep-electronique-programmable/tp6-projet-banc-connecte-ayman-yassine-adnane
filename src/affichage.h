/*!
 * @file affichage.h
 *
 * @author Ayman & Yassine  
 * 
 * @date 22 mai 2025
 * 
 * @brief Contient les fonctions pour le controle de l'affichage
 *
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Arduino.h>
//#include <affichage.cpp>
#include <U8g2lib.h>

extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C ecran;


void afficherInfo(uint16_t nbrPresence, uint16_t nbrCharge);




#endif // AFFICHAGE_H