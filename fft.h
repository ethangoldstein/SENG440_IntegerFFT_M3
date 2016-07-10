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
#include "cytypes.h"
    
int fix_ifft(fixed *__restrict__  fr, fixed *__restrict__  fi, int16 m);
int fix_fft(fixed *__restrict__  fr, fixed  *__restrict__  fi, int16 m);

/* FIX_MPY() - fixed-point multiplication macro.
   This macro is a statement, not an expression (uses asm).
   BEWARE: make sure _DX is not clobbered by evaluating (A) or DEST.
   args are all of type fixed.
   Scaling ensures that 32767*32767 = 32767. */
#define dosFIX_MPY(DEST,A,B)    {       \
        _DX = (B);                      \
        _AX = (A);                      \
        asm imul dx;                    \
        asm add ax,ax;                  \
        asm adc dx,dx;                  \
        DEST = _DX;             }

//#define FIX_MPY(DEST,A,B)       DEST = (((long)(A) * (long)(B))>>15)
#define FIX_MPY(A,B)             ( ( (long)(A) * (long)(B) ) >> 15 )
//^^^^ Look FOR DSP INSTR THAT DOES SAME THING ^^^^

#if N_WAVE != 1024
        //ERROR: N_WAVE != 1024
#endif

#define N_WAVE          1024    /* dimension of Sinewave[] */
#define LOG2_N_WAVE     10      /* log2(N_WAVE) */
#define N_LOUD          100     /* dimension of Loudampl[] */
    
#define M       10
#define N       ( 1 << M )
    
#endif
    
/* [] END OF FILE */
