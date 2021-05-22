#include "Glasses.h"


uint8_t Breathe () 
{
    static uint32_t timer = 0;
    static uint8_t power = 0;
    static bool add = false;
    
    if (millis() < timer)
        return power;

    if (power == 255 || power == 0)
        add = !add;
    
    power += add ? 1 : -1;
    timer = millis() + BREATHE_INTERVAL;

    return power;
}

void Wave() 
{
    static uint32_t timer = 0;
    static uint32_t color = WAVE_COLOR;
    
    if (millis() < timer)
        return;
    timer = millis() + WAVE_INTERVAL;

    SetColor(color);
    color = cycle_shift(color, 1);
}

void RandColor() 
{
    static uint32_t timer = 0;

    if (millis() < timer)
        return;
    timer = millis() + RAND_INTERVAL;

    SetColor(random(255), random(255), random(255));
}