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
* v5.1.1_14031024          E.Rahmanian    Fixed
******************************************************************************************
*/
#if defined(CUBEIDE__HAL)
#ifndef EMF_BUTTON_CUBEIDE__HAL_H
#define EMF_BUTTON_CUBEIDE__HAL_H

/**
* @code
#include "main.h"
#include "EMF.h"

void main() {
    uint8 a;

    EMF_init();

    EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();

    EMF_GIO_Init(GIOA, 0b100, GPIO_MODE_INPUT, GPIO_PULLNO, GPIO_SPEED_FREQ_VERY_HIGH, 0); //GIOA.3 Config Input
    while (1){
        a = EMF_Button_1Detect_0NotDetect(GIOA, 2, 0);
    }
}
* @endcode
*/


#define _ButtonDebounce() EMF_Delay_ms(10)
//=========================================================================================
/**
 * @brief PLZ Config Pin Before Call This
 */
bool EMF_Button_1Detect_0NotDetect(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool DetectValue);

#endif
#endif
