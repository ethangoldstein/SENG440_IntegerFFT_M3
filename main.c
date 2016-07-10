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

#include "userInterface.h"
    
#include <project.h>
#include <stdio.h>
#include <math.h>
#include "general.h"
#include "fft.h"
#include "debug.h"

//TODO write a function to calculate amplitude
int main(){
    
    while(1){      
        do_simulation();
    }

    UART_1_PutString("\r\nProgram exitied unusually\r\n"); /* Sending the data */
    UART_1_Stop(); 
    
   return 0;
}
/* [] END OF FILE */
