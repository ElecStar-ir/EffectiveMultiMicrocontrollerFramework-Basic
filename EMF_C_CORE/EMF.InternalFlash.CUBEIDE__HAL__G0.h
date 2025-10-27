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
#ifndef EMF_INTERNALFLASH_CUBEIDE__HAL__G0_H
#define EMF_INTERNALFLASH_CUBEIDE__HAL__G0_H

/**
* @code
    volatile uint32 e,h;	
    bool f;
    uint64 g, i , j;
    e = EMF_InternalFlash_Lx_GetFirstByteAddressOfPage(30);
    h = EMF_InternalFlash_Lx_GetEndByteAddressOfPage(30);
    j = EMF_InternalFLASH_Lx_Read_Return_4Byte(e);

    EMF_InternalFlash_L1_UnLock();
    f = EMF_InternalFlash_L2_ErasePage_Return_0Error_1Ok(30);
    g = 0x1122334455667788;

    f = EMF_InternalFlash_L2_Write8Byte_Return_0Error_1Ok(e, g);
    EMF_InternalFlash_Lx_Lock();
    i = EMF_InternalFLASH_Lx_Read_Return_4Byte(e);
    while(1);
* @endcode
*/
//=========================================================================================
#define EMF_InternalFlash_StartAddress	    FLASH_BASE
#define EMF_InternalFlash_EndAddress	    (FLASH_BASE + FLASH_SIZE - 1)
#define EMF_InternalFlash_PagesCount        FLASH_PAGE_NB
#define EMF_InternalFlash_Size              FLASH_SIZE
#define EMF_InternalFlash_PageSize          FLASH_PAGE_SIZE
//=========================================================================================
#define EMF_InternalFlash_L1_UnLock()       HAL_FLASH_Unlock()
#define EMF_InternalFlash_Lx_Lock()         HAL_FLASH_Lock()
bool EMF_InternalFlash_L2_ErasePage_Return_0Error_1Ok(uint32 PageNumber_0tox);
bool EMF_InternalFlash_L2_Write8Byte_Return_0Error_1Ok(uint32 StartWriteByteAddress, uint64 Data);
uint32 EMF_InternalFlash_Lx_GetFirstByteAddressOfPage(uint8 PageNumber_0tox);
uint32 EMF_InternalFlash_Lx_GetEndByteAddressOfPage(uint8 PageNumber_0tox);
#define EMF_InternalFLASH_Lx_Read_Return_1Byte(StartReadByteAddress_uint32)   (*((volatile uint8*)(StartReadByteAddress_uint32)))
#define EMF_InternalFLASH_Lx_Read_Return_2Byte(StartReadByteAddress_uint32)   (*((volatile uint16*)(StartReadByteAddress_uint32)))
#define EMF_InternalFLASH_Lx_Read_Return_3Byte(StartReadByteAddress_uint32)   (*((volatile uint32*)(StartReadByteAddress_uint32)))
#define EMF_InternalFLASH_Lx_Read_Return_4Byte(StartReadByteAddress_uint32)   (*((volatile uint64*)(StartReadByteAddress_uint32)))
//=========================================================================================





#endif
#endif
