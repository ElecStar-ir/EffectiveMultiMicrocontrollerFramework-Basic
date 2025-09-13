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
 * v5.3.1_14040803          E.Rahmanian    Optimize
 ******************************************************************************************
 */
#if defined(CUBEIDE__HAL__G0__STM32G030X6_X8)
#ifndef EMF_DELAY_CUBEIDE__HAL__G0__STM32G030X6_X88_H
#define EMF_DELAY_CUBEIDE__HAL__G0__STM32G030X6_X8_H

/**
* @code Simple Example
#include "main.h"
#include "EMF.h"

int main(void){

    uint8 a;
    uint32 f;

    EMF_init();

    a = EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();
    f = EMF_GetCoreClock_HZ();
    a = EMF_SetCoreClockTo_HSI_16MHZ_Return_1Ok_0Failed();
    f = EMF_GetCoreClock_HZ();
    a = EMF_SetCoreClockTo_HSI_PLL_32MHZ_Return_1Ok_0Failed();
    f = EMF_GetCoreClock_HZ();
    a = EMF_SetCoreClockTo_HSI_PLL_64MHZ_Return_1Ok_0Failed();
    f = EMF_GetCoreClock_HZ();

    EMF_GIO_RegisterClockOnOff(GIOA, 1);
    EMF_GIO_Init(GIOA, 0b11, GPIO_MODE_INPUT, GPIO_PULLNO, GPIO_SPEED_FREQ_VERY_HIGH, 0);

    a = EMF_Delay_L1_Config_return_0Error_1Ok(TIM1);
    a = EMF_Delay_Lx_ConfigState_Return_1Ok_0NotConfiged();
    
    f = HAL_GetTick();
    EMF_Delay_us(10000);
    f = HAL_GetTick() - f;

    f = EMF_Delay_L2_Get_WhileDelayCount(100);
    while(f--); //wait 100us


    while (1);
}
* @endcode Simple Example
*
* @brief Please uncomment "#define HAL_TIM_MODULE_ENABLED" in "stm32f0xx_hal_conf.h"
*/

#if defined(HAL_TIM_MODULE_ENABLED)

    /**
     * @brief Don't Need Delay_Config Before Call This
     */
    #define EMF_Delay_ms(delay_ms_uint32) HAL_Delay(delay_ms_uint32)

    #define EMF_Delay_us(Delay_us_0to32767_uint16) EMF_Delay_L2_Delay_us(Delay_us_0to32767_uint16)

    bool EMF_Delay_L1_Config_return_0Error_1Ok(TIM_TypeDef *SelectTimerToCreateDelay_Ptr__Ex_TIM1);
    void EMF_Delay_Lx_Timer_Stop();

    /**
     * @brief PLZ Delay_Config Before Call This Sub
     */
    void EMF_Delay_L2_Delay_us(uint16 Delay_us_0to32767);

    /**
     * @brief Don't Need Delay_Config Before Call This
     */
    bool EMF_Delay_Lx_ConfigState_Return_1Ok_0NotConfiged();

    /**
     * @brief PLZ Delay_Config Before Call This Sub
     */
    uint32 EMF_Delay_L2_Get_WhileDelayCount(int16 Delay_us_0to32767);

// #else
//     #error "Please uncomment #define HAL_TIM_MODULE_ENABLED in stm32xxxx_hal_conf.h"
#endif

#endif
#endif
