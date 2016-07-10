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

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <project.h>
#include "general.h"
#include "fft.h"
#include "debug.h"

typedef enum {
    start,
    hw_init,
    state_init,
    idle,
    stop,
    set_parameters,
    get_parameters,
    simulate_fft,
    print_ready,
    print_results,
}SimulationState_t;

void do_simulation();
    
#endif/* End USER_INTERFACE_H */
