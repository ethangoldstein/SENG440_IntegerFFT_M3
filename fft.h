/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef FFT_H
#define FFT_H
#include "general.h"
    
int fix_ifft(fixed *__restrict__  fr, fixed *__restrict__  fi, int m);
int fix_fft(fixed *__restrict__  fr, fixed  *__restrict__  fi, int m);

#define FIX_MPY(A,B)             ( ( (long)(A) * (long)(B) ) >> 15 )

#if N_WAVE != 1024
        //ERROR: N_WAVE != 1024
#endif

#define N_WAVE          1024    /* dimension of Sinewave[] */
#define LOG2_N_WAVE     10      /* log2(N_WAVE) */
#define N_LOUD          100     /* dimension of Loudampl[] */
    
#define M       10
#define N       (1<<M)  //1<<M
    
#endif
    
/* [] END OF FILE */
