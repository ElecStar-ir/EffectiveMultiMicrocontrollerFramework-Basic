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
* v5.3_14040709            E.Rahmanian    Create
******************************************************************************************
*/

#if defined(CUBEIDE__HAL__G0__STM32G030X6_X8)
#ifndef EMF_SYSTEM_CUBEIDE__HAL__G0__STM32G030X6_X8_H
#define EMF_SYSTEM_CUBEIDE__HAL__G0__STM32G030X6_X8_H

/**
* @code
#include "EMF.h"
#include "main.h"

int main(void){

    int32 a;
    EMF_init();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a =  EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_32MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);

}
* @endcode
*/

#define EMF_GetCoreClock_HZ() SystemCoreClock
#define EMF_ResetMCU() NVIC_SystemReset()

bool EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();       // Min Speed in HSi
bool EMF_SetCoreClockTo_HSI_16MHZ_Return_1Ok_0Failed();      // Max Speed in HSi
bool EMF_SetCoreClockTo_HSI_PLL_32MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed / 2
bool EMF_SetCoreClockTo_HSI_PLL_64MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed


#endif
#endif
