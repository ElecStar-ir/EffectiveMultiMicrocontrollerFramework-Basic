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
#include "EMF.h"
#if defined(EMF_INDEPENDENTWATCHDOG_CUBEIDE__HAL__G0_H)

IWDG_HandleTypeDef _EMF_hiwdg;
//=========================================================================================
//=========================================================================================
bool EMF_IndependentWatchdog_L1_Init_Return_0Error_1Ok(uint32 Prescaler_Ex_IWDG_PRESCALER_256, uint32 Reload_0to4095){
    _EMF_hiwdg.Instance = IWDG;
    _EMF_hiwdg.Init.Prescaler = Prescaler_Ex_IWDG_PRESCALER_256;
    _EMF_hiwdg.Init.Window = IWDG_WINDOW_DISABLE;
    _EMF_hiwdg.Init.Reload = Reload_0to4095;
    if (HAL_IWDG_Init(&_EMF_hiwdg) != HAL_OK)
    {
        return 0;
    }

    return 1;
}
//=========================================================================================
//=========================================================================================
void EMF_IndependentWatchdog_L2_RefreshCounter(){
    HAL_IWDG_Refresh(&_EMF_hiwdg);
}

#endif
