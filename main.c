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
#include <project.h>
#include <stdio.h>
#include <math.h>
#include "general.h"
#include "fft.h"
#include "debug.h"

//TODO write a function to calculate amplitude
int main(){
    fixed real[N], imag[N];
    char string[32];
    int     i;
    int f1 = 2; int a1 = 100;
    int f2 = 30; int a2 = 40;
        
    CyGlobalIntEnable;        
    UART_1_Start();     /* Enabling the UART */

    UART_1_PutString("\r\nFFT Testing\r\n"); /* Sending the data */
    UART_1_PutString("FFT Size = "); /* Sending the data */
    itoa(N,string);
    UART_1_PutString(string); /* Sending the data */
    UART_1_PutString("\r\n\r\n"); /* Sending the data */
    CyDelay(200);
        
    for (i=0; i<N; i++){
            real[i] = (int)(a1*cos(f1*2.0*(i)*3.1415926535/N) + a2*sin(f2*2.0*(i)*3.1415926535/N) + 100);;// + (int)(a2*cos(f2*2.0*i*3.1415926535/N)) + 100;
            imag[i] = 0;
    }   
    
    fix_fft(real, imag);
    UART_1_PutString("Real Transform Data\r\n");
    for (i=0; i<N; i++){                  
            itoa(real[i],string);
            UART_1_PutString(string);           
            UART_1_PutString(" ");
            itoa(imag[i],string);
            UART_1_PutString(string);
            UART_1_PutString("\r\n");  
    }
   return 0;
}
/* [] END OF FILE */
