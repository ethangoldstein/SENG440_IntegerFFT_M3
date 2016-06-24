#ifndef LUT_H
#define LUT_H
#include "general.h"
#include "fft.h"

#define SIN_LUT_SIZE N/2
#define COS_LUT_SIZE N/2
    
const fixed Sinewave[N_WAVE];
const fixed sinLUT[SIN_LUT_SIZE];
const fixed cosLUT[COS_LUT_SIZE];
    
#endif