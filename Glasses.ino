#include "Glasses.h"

const int colors[3] = {RED, GREEN, BLUE};
const int buttons[4] = {BTN_1, BTN_2, BTN_3, BTN_4};

int mode = 0;

void setup ()
{
    for (int i = 0; i < 3; i++) 
    {
        pinMode(colors[i], OUTPUT);
        digitalWrite(colors[i], 0);
    }

    for (int i = 0; i < 4; i++)
        pinMode(buttons[i], INPUT_PULLUP);

    randomSeed(analogRead(0));
}

void loop ()
{
    CheckButtons();
    Mode();
}

void Mode () 
{
    switch (mode)
    {
        case 0:
            Wave();
            break;
        
        case 1:
            SetColor(0, Breathe(), 0);
            break;
        
        case 2:
            SetColor(0xff0000);
            break;
        
        case 3:
            RandColor();
            break;
    }
}

void SetColor (byte red, byte green, byte blue)
{
    analogWrite(RED, 255 - red);
    analogWrite(GREEN, 255 - green);
    analogWrite(BLUE, 255 - blue);
}

void SetColor (uint32_t color)
{
    byte blue = color % 256;
    color /= 256;

    byte green = color % 256;
    color /= 256;
    
    byte red = color;

    SetColor(red, green, blue);
}

void CheckButtons ()
{
    for (int i = 0; i < 4; i++)
    {
        if (digitalRead(buttons[i]) == LOW) 
        {
            mode = i;
            delay(50);
        }
    }
}
