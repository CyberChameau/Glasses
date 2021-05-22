#ifndef MODES_H
#define MODES_H

/* === Settings === */
// Breathe
#define BREATHE_INTERVAL 10

// Wave
#define WAVE_INTERVAL 100
#define WAVE_SHIFT 1
#define WAVE_COLOR 0x0000ff

// RandColor
#define RAND_INTERVAL 1000
/* ================= */

// Functions
uint8_t Breathe();
void Wave();
void RandColor();

#endif