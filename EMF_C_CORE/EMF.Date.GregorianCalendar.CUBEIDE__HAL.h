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
* v5.7_14040924            E.Rahmanian    Add{EMF_GregorianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange}
******************************************************************************************
*/
#if defined(EMF_C)
#ifndef EMF_DATE_GREGORIANCALENDAR_CUBEIDE__HAL
#define EMF_DATE_GREGORIANCALENDAR_CUBEIDE__HAL
/**
* @brief MinGregorianDate : 2021/03/21   MaxGregorianDate : 2122/03/20
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(uint16 Year_1to9999);
bool EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31);
uint8 EMF_GregorianCalendar_CompareDates_Return_Date1_1Greater_0Smaller_2Equal(uint16 Year1, uint8 Month1, uint8 Day1, uint16 Year2, uint8 Month2, uint8 Day2);
uint8 EMF_GregorianCalendar_DaysInMonth_Return_28To31_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12);
uint16 EMF_GregorianCalendar_DayOfYear_Return_1To366_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31);
int32 EMF_GregorianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(uint16 Year1_1to9999, uint8 Month1_1to12, uint8 Day1_1to31, uint16 Year2_1to9999, uint8 Month2_1to12, uint8 Day2_1to31);
bool EMF_GregorianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(uint16 *Year_1to9999, uint8 *Month_1to12, uint8 *Day_1to31, int32 AddOrSubtractDay);
bool EMF_GregorianCalendar_ConvertDate_GregorianToPersian_Return_1Ok_0OutOfReange(
    uint16 GregorianYear_2021to2122, uint8 GregorianMonth_1to12, uint8 GregorianDay_1to31,
    uint16 *ReturnPersianYear_1400to1500, uint8 *ReturnPersianMonth_1to12, uint8 *ReturnPersianDay_1to31);
uint8 EMF_GregorianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31);

#endif
#endif
