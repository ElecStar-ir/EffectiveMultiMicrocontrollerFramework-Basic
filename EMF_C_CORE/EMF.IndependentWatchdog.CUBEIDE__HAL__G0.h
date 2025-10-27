/**
 ******************************************************************************************
 * This file is part of EMF(Effective Multi Microcontroller Framework).
 *
 * @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
 * @brief
 ******************************************************************************************
 * @attention
 *
 ******************************************************************************************
 * @RELEASE HISTORY
 *
 * DATE                     NAME           DESCRIPTION
 * v5.5_14040810            E.Rahmanian    Create
 ******************************************************************************************
 */
#if defined(CUBEIDE__HAL__G0)
#ifndef EMF_INDEPENDENTWATCHDOG_CUBEIDE__HAL__G0_H
#define EMF_INDEPENDENTWATCHDOG_CUBEIDE__HAL__G0_H

//=========================================================================================
/**
* @code
#include "EMF.h"

void main(){
    EMF_init();
    bool e;
    e = EMF_IndependentWatchdog_L1_Init_Return_0Error_1Ok(IWDG_PRESCALER_256, 4095);
    while(1){
        //EMF_IndependentWatchdog_L2_RefreshCounter();
    }
}
* @endcode
*/
/*
Ex) if Reload=4095 and Prescaler=256 then :
(4095 + 1) / (32000 / 256) ~= 32.8s
*/
/**
* @brief ResetTime(s) = (Reload + 1) / (32000 / Prescaler)
* @brief Ex) if Reload=4095 and Prescaler=256 then : (4095 + 1) / (32000 / 256) ~= 32.8s
*/
bool EMF_IndependentWatchdog_L1_Init_Return_0Error_1Ok(uint32 Prescaler_Ex_IWDG_PRESCALER_256, uint32 Reload_0to4095);
//=========================================================================================
/**
* @brief PLZ set init Befor Call Functions
*/
void EMF_IndependentWatchdog_L2_RefreshCounter();


#endif
#endif
