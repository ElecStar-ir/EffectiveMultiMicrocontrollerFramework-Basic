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
* v4.3_14020830            E.Rahmanian    Create
* v5.0_14031021            E.Rahmanian    Optimize
******************************************************************************************
*/
#include "EMF.h"
#if defined(EMF_BUTTON_CUBEIDE__HAL_H)

bool EMF_Button_1Detect_0NotDetect(GIO_TypeDef *Ex_GPIOA, uint8 PinNumber_0tox, bool DetectValue){
    if(EMF_GIO_Read_1Pin(Ex_GPIOA, PinNumber_0tox) == DetectValue){
        _ButtonDebounce();
        if(EMF_GIO_Read_1Pin(Ex_GPIOA, PinNumber_0tox) == DetectValue){
            return 1;
        }
    }
    return 0;
}

#endif
