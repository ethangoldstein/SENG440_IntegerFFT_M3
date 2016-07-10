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

/* [] END OF FILE */

#include "userInterface.h"

//FFT DATA
static fixed real[N];
static fixed imag[N];

#define MAX_WIDTH 50
#define MAX_LINES 1

static void fix_fft_init();
static SimulationState_t parseInput(uint8 data);
static void fix_fft_print( fixed real[N], fixed imag[N]);
static void fix_fft_regenerate_data( fixed real[N],fixed imag[N],int f1, int a1, int f2, int a2);
static void echo();

static parse_regular(uint8 data, uint8 responseBuffer[MAX_LINES][MAX_WIDTH],
                     uint8 row_inc , uint8 col_inc );

void do_simulation(){
    
    static SimulationState_t state = hw_init;
    static uint8 buffSize = 0;
    
    switch(state){
        
        case hw_init:
            fix_fft_init(&state);
            state = state_init;
        break;
          
        case state_init:
            fix_fft_regenerate_data(real, imag, 1000, 40, 1000, 30);
            state = idle;
        break;
        
        case idle:
            
            while( state == idle){
               buffSize = UART_1_GetRxBufferSize();
               if(buffSize){
//                   state = parseInput(UART_1_ReadRxData());
                echo();
               }
            
            echo();
            
            }
              
           
        break;
        
        case stop:
        break;
        
        case set_parameters:
        break;
        
        case get_parameters:
        break;
        
        case simulate_fft:
        break;
        
        case print_ready:
        break;
        
        case print_results:
        break;
        
        default:
        break;

    }
}

#define ESC 0x1B
#define BACKSPACE 0x10 
#define SPACE 0x20
#define CF 0x0D
#define LF 0x12
#define CTRL 0x21 /* Is this right?*/
#define ALPHANUM 0xFF


SimulationState_t static parseInput(uint8 data){
    
    static uint8 responseBuffer[MAX_LINES][MAX_WIDTH];
    static uint8 row_inc = 0;
    static uint8 col_inc = 0;
    
    switch ( data ) {
          
        case BACKSPACE:

        break;
        
        case SPACE:
        break;
        
        case CF:
        break;
        
        case LF:
        break;
        
        case CTRL:
        break;
        
        
        default: //All other characters
            parse_regular(data, responseBuffer, )

            
        break;

    
    }
   
}

static parse_regular(uint8 data, uint8 responseBuffer[MAX_LINES][MAX_WIDTH],
                     uint8 row_inc , uint8 col_inc ){
    
    if( ( 0x2F < data ) && ( data  < 0x39)){
        responseBuffer[row_inc][col_inc] = data;
        state = ALPHANUM;
    }else{
    }

}

static void echo(){
    uint8 data_s;
    data_s = UART_1_ReadRxData();
    UART_1_PutChar(data_s);
}

void UART_TX_IRQHandler(){

}

void UART_RX_IRQHandler(){

}


 static void fix_fft_init(void){
        
    char string[32];
    
    CyGlobalIntEnable;  
    
    UART_1_Start();     /* Enabling the UART */
    UART_1_PutString("\r\nFFT Testing\r\n"); /* Sending the data */
    UART_1_PutString("FFT Size = "); /* Sending the data */
    itoa(N,string);
    UART_1_PutString(string); /* Sending the data */
    UART_1_PutString("\r\n\r\n"); /* Sending the data */
    CyDelay(200);
    
    
    
}
static void fix_fft_print( fixed real[N], fixed imag[N]){
    
    int     i;
    char string[32];
    
    UART_1_PutString("Real and Image Transform Data\r\n");
    for (i=0; i<N; i++){                  
            itoa(real[i],string);
            UART_1_PutString(string);           
            UART_1_PutString(" ");
            itoa(imag[i],string);
            UART_1_PutString(string);
            UART_1_PutString("\r\n");  
    }
    
}

static void fix_fft_regenerate_data( fixed real[N],fixed imag[N],int f1, int a1, int f2, int a2){
    
    int     i;

    
    for (i=0; i<N; i++){
        real[i] = (int)(a1*cos(f1*2.0*i*3.1415926535/N)) + 1000;// + (int)(a2*cos(f2*2.0*i*3.1415926535/N)) + 100;
        imag[i] = 0;
    }
    
    return;
}

