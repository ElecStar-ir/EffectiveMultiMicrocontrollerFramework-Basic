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
 * v4.0_14020803            E.Rahmanian    Create
 * v5.1_14040709            E.Rahmanian    Add #include "EMF.MCU.CUBEIDE__HAL__G0__STM32G030X6_X8__STM32G030C8T6.h"
 ******************************************************************************************
 */
#if defined(EMF_CPP)
#ifndef EMF_PREPARATION_H
#define EMF_PREPARATION_H

    #include "EMF.MCU.IAR__HAL__F0__STM32F030X6__STM32F030F4P6.h"
    #include "EMF.MCU.CUBEIDE__HAL__G0__STM32G030X6_X8__STM32G030C8T6.h"

    #if !defined(EMF_MCU_SELECTED)
        #error "Please Uncomment the target MCU define in EMF.Config.h"
    #endif

#endif
#endif