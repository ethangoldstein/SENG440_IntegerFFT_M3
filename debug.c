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

#include "debug.h"

char* itoa(fixed i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    int shifter = i;
    
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

char* uitoa(uint16 i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    int shifter = i;
    
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

/* [] END OF FILE */
