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
#include "fft.h"
#include "general.h"
#include "bitrev.h"
#include "debug.h"
#include "UART_1.h"
#include "LUT.h"

extern const fixed Sinewave[N_WAVE];
extern const fixed sinLUT[SIN_LUT_SIZE];
extern const fixed cosLUT[COS_LUT_SIZE];

#define LIKELY(x)     __builtin_expect(x,1)
#define UNLIKELY(x)   __builtin_expect(x,0)

void fix_fft(fixed *__restrict__  fr, fixed  *__restrict__  fi)
{
    
        // A total of 16 variables - can we do better?
        int i,j,l,k, istep, m;
        long wr,wi;
        long fr_i_temp, fr_j_temp, fi_i_temp, fi_j_temp;
        long  qr, qi, tr,ti;
    
        //bit reordering
        bit_reversal(fr);
        bit_reversal(fi);      

        //setting up loop stuff
        //m = M; //size of fft in number of bits (this value for m is not used)
        l = 1;
        k = M-1;
        
        while(LIKELY(l < N)) {

            /* fixed scaling, for proper normalization -
               there will be log2(n) passes, so this
               results in an overall factor of 1/n,
               distributed to maximize arithmetic accuracy. */
            
            /* it may not be obvious, but the shift will be performed
               on each data point exactly once, during this pass. */
            istep = l << 1;
            
            for(m=0; m<l; ++m) {
                
                j = m << k;
                
                //grabbing twiddle factors
                wr = (long)cosLUT[j]; 
                wi = (long)sinLUT[j]; 
                
                for(i=m; LIKELY(i<N); i+=istep) {
                    
                    j = i + l;
                    
                    //On Cortex M3 sequential Load and store operations are easier to pipeline
                    fr_i_temp = (long)fr[i];
                    fr_j_temp = (long)fr[j];
                    fi_i_temp = (long)fi[i];
                    fi_j_temp = (long)fi[j];
                                       
                    tr = wr * fr_j_temp;
                    tr -= wi *  fi_j_temp;
                    tr >>=15;
                    
                    ti = wr * fi_j_temp;
                    ti += wi * fr_j_temp;
                    ti >>=15;
                    
//                    tr = FIX_MPY(wr,fr_j_temp) - FIX_MPY(wi,fi_j_temp);
//                    ti = FIX_MPY(wr,fi_j_temp) + FIX_MPY(wi,fr_j_temp);
                    
                    qr = (fr_i_temp >> 1);
                    qi = (fi_i_temp >> 1);
                    
                    fr_j_temp = (qr - tr);
                    fi_j_temp = (qi - ti);
                    fr_i_temp = (qr + tr);
                    fi_i_temp = (qi + ti);
                    
                    //On Cortex M3 sequential Load and store operations are easier to pipeline
                    fr[j] = (fixed)fr_j_temp;
                    fi[j] = (fixed)fi_j_temp;
                    fr[i] = (fixed)fr_i_temp;
                    fi[i] = (fixed)fi_i_temp;
                }
            }
            
            --k;
            l = istep;            
        }     
}
