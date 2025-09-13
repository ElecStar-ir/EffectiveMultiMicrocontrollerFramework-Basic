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
 * v4.0.2_14020829          E.Rahmanian    Optimize{Change Name:GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut to GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut}
 *                                         Fixed{GIO_DirectWrite_Pins_Low_WithMask}
 * v5.0_14031024            E.Rahmanian    Optimize
 * v5.1_14040709            E.Rahmanian    Optimize
 ******************************************************************************************
 */
#include "EMF.h"
#if defined(EMF_GIO_CUBEIDE__HAL__F0_H)

void EMF::GIO::EMF_GIO_RegisterClockOnOff(GIO_TypeDef *GIOx_Ptr__Ex_GIOA, bool GIOx_Clock_1On0Off){
    switch ((uint32)GIOx_Ptr__Ex_GIOA) {
    #ifdef GIOA
    case (uint32)GIOA:
        if (GIOx_Clock_1On0Off) {
            EMF_GIOA_RegisterClockOn();
        } else {
            EMF_GIOA_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOB
    case (uint32)GIOB:
        if (GIOx_Clock_1On0Off) {
            EMF_GIOB_RegisterClockOn();
        } else {
            EMF_GIOB_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOC
    case (uint32)GIOC:
        if (GIOx_Clock_1On0Off) {
            EMF_GIOC_RegisterClockOn();
        } else {
            EMF_GIOC_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOD
    case (uint32)GIOD:
        if (GIOx_Clock_1On0Off) {
            EMF_GIOD_RegisterClockOn();
        } else {
            EMF_GIOD_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOE
    case (uint32)GIOE:
        if (GIOx_Clock_1On0Off) {
            GIOE_RegisterClockOn();
        } else {
            GIOE_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOF
    case (uint32)GIOF:
        if (GIOx_Clock_1On0Off) {
            EMF_GIOF_RegisterClockOn();
        } else {
            EMF_GIOF_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOG
    case (uint32)GIOG:
        if (GIOx_Clock_1On0Off) {
            GIOG_RegisterClockOn();
        } else {
            GIOG_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOH
    case (uint32)GIOH:
        if (GIOx_Clock_1On0Off) {
            GIOH_RegisterClockOn();
        } else {
            GIOH_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOI
    case (uint32)GIOI:
        if (GIOx_Clock_1On0Off) {
            GIOI_RegisterClockOn();
        } else {
            GIOI_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOJ
    case (uint32)GIOJ:
        if (GIOx_Clock_1On0Off) {
            GIOJ_RegisterClockOn();
        } else {
            GIOJ_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOK
    case (uint32)GIOK:
        if (GIOx_Clock_1On0Off) {
            GIOK_RegisterClockOn();
        } else {
            GIOK_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOL
    case (uint32)GIOL:
        if (GIOx_Clock_1On0Off) {
            GIOL_RegisterClockOn();
        } else {
            GIOL_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOM
    case (uint32)GIOM:
        if (GIOx_Clock_1On0Off) {
            GIOM_RegisterClockOn();
        } else {
            GIOM_RegisterClockOff();
        }
        break;
    #endif



    }  // switch
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
                    McuRegType GPIO_PINS_Mask__Ex_0b1101,
                    McuRegType GPIO_MODE__Ex_GPIO_MODE_OUTPUT_PP,
                    McuRegType GPIO_PULL__Ex_GPIO_PULLNO,
                    McuRegType GPIO_OUTPUT_SPEED__Ex_GPIO_SPEED_FREQ_HIGH,
                    McuRegType ALTERNATE_FUNCTION__Ex_GPIO_AF0_SPI1__Or_0AlternateFunctionIsOff) {
    GPIO_InitTypeDef temp = {0};
    temp.Pin = GPIO_PINS_Mask__Ex_0b1101;
    temp.Mode = GPIO_MODE__Ex_GPIO_MODE_OUTPUT_PP;
    temp.Pull = GPIO_PULL__Ex_GPIO_PULLNO;
    temp.Speed = GPIO_OUTPUT_SPEED__Ex_GPIO_SPEED_FREQ_HIGH;
    temp.Alternate = ALTERNATE_FUNCTION__Ex_GPIO_AF0_SPI1__Or_0AlternateFunctionIsOff;
    HAL_GPIO_Init((GPIO_TypeDef *)GIOx__Ex_GIOA, &temp);
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::EMF_GIO_GetConfigState_1Pin_Return_Mode_0Input1Output2Alternate3Analog(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->MODER, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::EMF_GIO_GetConfigState_1Pin_Return_OutputMode_0PushPull_1OpenDrain(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->OTYPER, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::EMF_GIO_GetConfigState_1Pin_Return_OutputSpeed_0Low_1Medium_2Low_3High(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->OSPEEDR, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::EMF_GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp_2PullDown(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->PUPDR, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value) {
    EMF_GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1) {
    EMF_GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    EMF_GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    EMF_GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011) {
    EMF_GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::EMF_GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    EMF_GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
McuRegType EMF::GIO::EMF_GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA) {
    return EMF_GIO_DirectGetWriteState_AllPins(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
McuRegType EMF::GIO::EMF_GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA) {
    return EMF_GIO_DirectRead_AllPins_Defsubf(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return EMF_GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return EMF_GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return EMF_GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000) {
    return EMF_GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (EMF_GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) != CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (EMF_GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) == CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::EMF_GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount) {
    while ((TryCount) && (EMF_GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) != CheckValue_0or1)){
        TryCount--;
    };
    return TryCount && 1;
}
#endif
