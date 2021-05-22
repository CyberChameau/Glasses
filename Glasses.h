#ifndef GLASSES_H
#define GLASSES_H

#include <Arduino.h>

// LED
#define RED    11
#define GREEN  10
#define BLUE   9

// Buttons
#define BTN_1   0
#define BTN_2   1
#define BTN_3   2
#define BTN_4   3

// functions
void SetColor (byte red, byte green, byte blue);
void SetColor (uint32_t color);

void CheckButtons();

// Libs
#include "Utils.hpp"
#include "Modes.h"

#endif