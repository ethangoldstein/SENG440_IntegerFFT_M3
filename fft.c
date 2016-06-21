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

extern fixed Sinewave[N_WAVE]; /* placed at end of this file for clarity */

/*      fix_fft.c - Fixed-point Fast Fourier Transform  */
/*
        fix_fft()       perform FFT or inverse FFT
        window()        applies a Hanning window to the (time) input
        fix_loud()      calculates the loudness of the signal, for
                        each freq point. Result is an integer array,
                        units are dB (values will be negative).
        iscale()        scale an integer value by (numer/denom).
        fix_mpy()       perform fixed-point multiplication.
        Sinewave[1024]  sinewave normalized to 32767 (= 1.0).
        Loudampl[100]   Amplitudes for lopudnesses from 0 to -99 dB.
        Low_pass        Low-pass filter, cutoff at sample_freq / 4.


        All data are fixed-point short integers, in which
        -32768 to +32768 represent -1.0 to +1.0. Integer arithmetic
        is used for speed, instead of the more natural floating-point.

        For the forward FFT (time -> freq), fixed scaling is
        performed to prevent arithmetic overflow, and to map a 0dB
        sine/cosine wave (i.e. amplitude = 32767) to two -6dB freq
        coefficients; the one in the lower half is reported as 0dB
        by fix_loud(). The return value is always 0.

        For the inverse FFT (freq -> time), fixed scaling cannot be
        done, as two 0dB coefficients would sum to a peak amplitude of
        64K, overflowing the 32k range of the fixed-point integers.
        Thus, the fix_fft() routine performs variable scaling, and
        returns a value which is the number of bits LEFT by which
        the output must be shifted to get the actual amplitude
        (i.e. if fix_fft() returns 3, each value of fr[] and fi[]
        must be multiplied by 8 (2**3) for proper scaling.
        Clearly, this cannot be done within the fixed-point short
        integers. In practice, if the result is to be used as a
        filter, the scale_shift can usually be ignored, as the
        result will be approximately correctly normalized as is.


        TURBO C, any memory model; uses inline assembly for speed
        and for carefully-scaled arithmetic.

        Written by:  Tom Roberts  11/8/89
        Made portable:  Malcolm Slaney 12/15/94 malcolm@interval.com

                Timing on a Macintosh PowerBook 180.... (using Symantec C6.0)
                        fix_fft (1024 points)             8 ticks
                        fft (1024 points - Using SANE)  112 Ticks
                        fft (1024 points - Using FPU)    11

*/

/*
        fix_fft() - perform fast Fourier transform.
        fr[n],fi[n] are real,imaginary arrays, INPUT AND RESULT.
        size of data = 2**m
*/
int fix_fft(fixed *__restrict__  fr, fixed  *__restrict__  fi, int m)
{
        int mr,nn,i,j,l,k, istep, n;
        fixed qr,qi,tr,ti,wr,wi,t;

        n = 1<<m;

        if(n > N_WAVE) return -1;
        
        mr = 0;
        nn = n - 1;

        /* decimation in time - re-order data */
        for(m=1; m<=nn; ++m) {
            
            l = n;
        
            do {
                 l >>= 1;
            } while(mr+l > nn);
            
            mr = (mr & (l-1)) + l;

            if(mr <= m) continue;
            
            tr = fr[m];
            fr[m] = fr[mr];
            fr[mr] = tr;
            ti = fi[m];
            fi[m] = fi[mr];
            fi[mr] = ti;
        }

        l = 1;
        k = LOG2_N_WAVE-1;
        
        while(l < n) {

            /* fixed scaling, for proper normalization -
               there will be log2(n) passes, so this
               results in an overall factor of 1/n,
               distributed to maximize arithmetic accuracy. */
            
            /* it may not be obvious, but the shift will be performed
               on each data point exactly once, during this pass. */
            istep = l << 1;
            
            for(m=0; m<l; ++m) {
                
                j = m << k;
                /* 0 <= j < N_WAVE/2 */
                wr =  Sinewave[j+N_WAVE/4];
                wi = -Sinewave[j];
                
                wr >>= 1;
                wi >>= 1;
                
                for(i=m; i<n; i+=istep) {
                    
                    j = i + l;
                                        
                    tr = FIX_MPY(wr,fr[j]) - FIX_MPY(wi,fi[j]);
                    ti = FIX_MPY(wr,fi[j]) + FIX_MPY(wi,fr[j]);
                            
                    qr = fr[i];
                    qi = fi[i];
                    
                    qr >>= 1;
                    qi >>= 1;
                    
                    fr[j] = qr - tr;
                    fi[j] = qi - ti;
                    fr[i] = qr + tr;
                    fi[i] = qi + ti;
                }
            }
            
            --k;
            l = istep;
            
        }
        
    return 0;
        
}

/*
        fix_ifft() - perform inverse fast Fourier transform.
        fr[n],fi[n] are real,imaginary arrays, INPUT AND RESULT.
        size of data = 2**m
*/
int fix_ifft(fixed *  __restrict__  fr, fixed  *  __restrict__  fi, int m)
{
        int mr,nn,i,j,l,k,istep, n, scale, shift;
        fixed qr,qi,tr,ti,wr,wi,t;

                n = 1<<m;

        if(n > N_WAVE)
                return -1;

        mr = 0;
        nn = n - 1;
        scale = 0;

        /* decimation in time - re-order data */
        for(m=1; m<=nn; ++m) {
            l = n;
            do {
                    l >>= 1;
            } while(mr+l > nn);
            mr = (mr & (l-1)) + l;

            if(mr <= m) continue;
            tr = fr[m];
            fr[m] = fr[mr];
            fr[mr] = tr;
            ti = fi[m];
            fi[m] = fi[mr];
            fi[mr] = ti;
        }

        l = 1;
        k = LOG2_N_WAVE-1;
        while(l < n) {

            /* variable scaling, depending upon data */
            shift = 0;
        
            for(i=0; i<n; ++i) {
                j = fr[i];
                if(j < 0)
                        j = -j;
                m = fi[i];
                if(m < 0)
                        m = -m;
                if(j > 16383 || m > 16383) {
                        shift = 1;
                        break;
                }
            }
            
            if(shift) ++scale;
             
            /* it may not be obvious, but the shift will be performed
               on each data point exactly once, during this pass. */
            istep = l << 1;
            for(m=0; m<l; ++m) {
                j = m << k;
                /* 0 <= j < N_WAVE/2 */
                wr =  Sinewave[j+N_WAVE/4];
                wi = -Sinewave[j];
               
                wi = -wi;
                
                if(shift) {
                        wr >>= 1;
                        wi >>= 1;
                }
                for(i=m; i<n; i+=istep) {
                    j = i + l;
                    
                    tr = FIX_MPY(wr,fr[j]) - FIX_MPY(wi,fi[j]);
                    ti = FIX_MPY(wr,fi[j]) + FIX_MPY(wi,fr[j]);
                    
                    qr = fr[i];
                    qi = fi[i];
                    
                    if(shift) {
                            qr >>= 1;
                            qi >>= 1;
                    }
                    
                    fr[j] = qr - tr;
                    fi[j] = qi - ti;
                    fr[i] = qr + tr;
                    fi[i] = qi + ti;
                }
            }
            --k;
            l = istep;
        }

        return scale;
}


/* [] END OF FILE */
