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
#if defined(EMF_INTERNALFLASH_CUBEIDE__HAL__G0_H)
//=========================================================================================
//=========================================================================================
uint32 EMF_InternalFlash_Lx_GetFirstByteAddressOfPage(uint8 PageNumber_0tox){
    return EMF_InternalFlash_StartAddress + (PageNumber_0tox * EMF_InternalFlash_PageSize);
}
//=========================================================================================
//=========================================================================================
uint32 EMF_InternalFlash_Lx_GetEndByteAddressOfPage(uint8 PageNumber_0tox){
    return EMF_InternalFlash_Lx_GetFirstByteAddressOfPage(PageNumber_0tox) + EMF_InternalFlash_PageSize - 1;
}
//=========================================================================================
//=========================================================================================
bool EMF_InternalFlash_L2_ErasePage_Return_0Error_1Ok(uint32 PageNumber_0tox){
    FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PageError;

    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Page      = PageNumber_0tox;                // شروع از صفحه 0
    EraseInitStruct.NbPages   = 1;                              // تعداد  صفحات

    if(HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) == HAL_OK){
        return 1;
    }

    return 0;
}
//=========================================================================================
//=========================================================================================
bool EMF_InternalFlash_L2_Write8Byte_Return_0Error_1Ok(uint32 StartWriteByteAddress, uint64 Data){
    uint64 Data2;
    if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, StartWriteByteAddress, Data) == HAL_OK){
        Data2 = EMF_InternalFLASH_Lx_Read_Return_4Byte(StartWriteByteAddress);
        if(Data == Data2){
            return 1;
        } 
    }

    return 0;
}
//=========================================================================================
//=========================================================================================

#endif
