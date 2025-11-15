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
* v5.6_14040903            E.Rahmanian    Create
******************************************************************************************
*/
#if defined(EMF_C)
#ifndef EMF_DATE_PERSIANCALENDAR_CUBEIDE__HAL
#define EMF_DATE_PERSIANCALENDAR_CUBEIDE__HAL

/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(uint16 Year_1400to1500);
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(uint16 Year_1400to1500, uint8 Month_1to12, uint8 Day_1to31);
uint8 EMF_PersianCalendar_CompareDates_Return_Date1_1Greater_0Smaller_2Equal(uint16 Year1, uint8 Month1, uint8 Day1, uint16 Year2, uint8 Month2, uint8 Day2);
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_PersianCalendar_DaysInMonth_Return_28To31_0OutOfReange(uint16 Year_1400to1500, uint8 Month_1to12);
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint16 EMF_PersianCalendar_DayOfYear_Return_1To366_0OutOfReange(uint16 Year_1400to1500, uint8 Month_1to12, uint8 Day_1to31);
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
int32 EMF_PersianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(uint16 Year1_1400to1500, uint8 Month1_1to12, uint8 Day1_1to31, uint16 Year2_1400to1500, uint8 Month2_1to12, uint8 Day2_1to31);
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(uint16 *Year1_1400to1500, uint8 *Month_1to12, uint8 *Day_1to31, int32 AddOrSubtractDay);
/**
* @brief MinGregorianDate : 2021/03/21   MaxGregorianDate : 2122/03/20
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_ConvertDate_PersianToGregorian_Return_1Ok_0OutOfReange(
    uint16 PersianYear_1400to1500, uint8 PersianMonth_1to12, uint8 PersianDay_1to31,
    uint16 *ReturnGregorianYear_2021to2122, uint8 *ReturnGregorianMonth_1to12, uint8 *ReturnGregorianDay_1to31);

#endif
#endif
