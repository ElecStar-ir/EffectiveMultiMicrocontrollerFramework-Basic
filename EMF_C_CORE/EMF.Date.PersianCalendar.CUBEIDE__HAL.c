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
 * v5.7_14040924            E.Rahmanian    Add{EMF_PersianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange}
 ******************************************************************************************
 */
#include "EMF.h"
#if defined(EMF_DATE_PERSIANCALENDAR_CUBEIDE__HAL)

const uint8 _DayesOfMonthNonLeapYearPersianCalendar[12] = {
                                                            31, // Farvardin
                                                            31, // Ordibehesht
                                                            31, // Khordad
                                                            31, // Tir
                                                            31, // Mordad
                                                            31, // Shahrivar
                                                            30, // Mehr
                                                            30, // Aban
                                                            30, // Azar
                                                            30, // Dey
                                                            30, // Bahman
                                                            29  // Esfand
                                                          };

const uint8 _DayesOfMonthLeapYearPersianCalendar[12] = {
                                                        31, // Farvardin
                                                        31, // Ordibehesht
                                                        31, // Khordad
                                                        31, // Tir
                                                        31, // Mordad
                                                        31, // Shahrivar
                                                        30, // Mehr
                                                        30, // Aban
                                                        30, // Azar
                                                        30, // Dey
                                                        30, // Bahman
                                                        30  // Esfand
                                                        };

//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(uint16 Year_1400to1500){
    if((Year_1400to1500 < 1400) || (Year_1400to1500 > 1500)){return 2;}

    Year_1400to1500 = (uint16)(Year_1400to1500 - 3 - ((uint16)(Year_1400to1500 - 1374) / 33));

    if (Year_1400to1500 % 4 == 0)
    {
        return 1;
    }

    return 0;
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(uint16 Year_1400to1500, uint8 Month_1to12, uint8 Day_1to31){
    if((Month_1to12 == 0) || (Month_1to12 > 12)){return 0;}
    if(Day_1to31 == 0){return 0;}

    switch (EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Year_1400to1500)) {
        case 2:
            return 0;
        case 1:
            if(Day_1to31 > _DayesOfMonthLeapYearPersianCalendar[Month_1to12 - 1]){return 0;}
            break;
        case 0:
            if(Day_1to31 > _DayesOfMonthNonLeapYearPersianCalendar[Month_1to12 - 1]){return 0;}
            break;
    }

    return 1;
}
//=========================================================================================
//=========================================================================================
uint8 EMF_PersianCalendar_CompareDates_Return_Date1_1Greater_0Smaller_2Equal(uint16 Year1, uint8 Month1, uint8 Day1, uint16 Year2, uint8 Month2, uint8 Day2){
    if (Year1 > Year2) return 1;
    if (Year1 < Year2) return 0;

    if (Month1 > Month2) return 1;
    if (Month1 < Month2) return 0;

    if (Day1 > Day2) return 1;
    if (Day1 < Day2) return 0;

    return 2; // مساوی
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_PersianCalendar_DaysInMonth_Return_28To31_0OutOfReange(uint16 Year_1400to1500, uint8 Month_1to12){
    if(EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year_1400to1500, Month_1to12, 1) == 0){return 0;}

    if(EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Year_1400to1500) == 0){
        return _DayesOfMonthNonLeapYearPersianCalendar[Month_1to12 - 1];      
    }
    
    return _DayesOfMonthLeapYearPersianCalendar[Month_1to12 - 1];
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint16 EMF_PersianCalendar_DayOfYear_Return_1To366_0OutOfReange(uint16 Year_1400to1500, uint8 Month_1to12, uint8 Day_1to31){
    // بررسی اعتبار تاریخ
    if (EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year_1400to1500, Month_1to12, Day_1to31) == 0){
        return 0; // تاریخ نامعتبر
    }

    uint16 daysPassed = 0;

    // جمع روزهای ماه‌های قبل
    for (uint8 m = 1; m < Month_1to12; m++){
        uint8 daysInMonth = EMF_PersianCalendar_DaysInMonth_Return_28To31_0OutOfReange(Year_1400to1500, m);
        if (daysInMonth == 0){
            return 0; // خطا یا ماه نامعتبر
        }
        daysPassed += daysInMonth;
    }

    // اضافه کردن روزهای ماه جاری
    daysPassed += Day_1to31;

    return daysPassed;
}

int32 EMF_PersianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(uint16 Year1_1400to1500, uint8 Month1_1to12, uint8 Day1_1to31, uint16 Year2_1400to1500, uint8 Month2_1to12, uint8 Day2_1to31){
    int32 sum1 = 0, sum2 = 0;
    uint16 BaseYear, Counter;

    // 1. اعتبارسنجی
    if ((EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year1_1400to1500, Month1_1to12, Day1_1to31) == 0) ||
        (EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year2_1400to1500, Month2_1to12, Day2_1to31) == 0)){

        return -1;
    }

    BaseYear = (Year1_1400to1500 < Year2_1400to1500) ? Year1_1400to1500 : Year2_1400to1500;

    for( Counter = BaseYear ; Counter < Year1_1400to1500 ; Counter++){
        if(EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Counter) == 1){
            sum1 += 366;
        }else{
            sum1 += 365;
        }
    }

    for( Counter = BaseYear ; Counter < Year2_1400to1500 ; Counter++){
        if(EMF_PersianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Counter) == 1){
            sum2 += 366;
        }else{
            sum2 += 365;
        }
    }
    
    sum1 += EMF_PersianCalendar_DayOfYear_Return_1To366_0OutOfReange(Year1_1400to1500, Month1_1to12, Day1_1to31);
    sum2 += EMF_PersianCalendar_DayOfYear_Return_1To366_0OutOfReange(Year2_1400to1500, Month2_1to12, Day2_1to31);

    return (sum1 > sum2) ? (sum1 - sum2) : (sum2 - sum1);   
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(uint16 *Year1_1400to1500, uint8 *Month_1to12, uint8 *Day_1to31, int32 AddOrSubtractDay){
    uint16 y = *Year1_1400to1500;
    uint8  m = *Month_1to12;
    uint8  d = *Day_1to31;

    if (EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}

    if (AddOrSubtractDay >= 0) {
        for( ; AddOrSubtractDay > 0 ; AddOrSubtractDay-- ){
            d++;
            if(d > EMF_PersianCalendar_DaysInMonth_Return_28To31_0OutOfReange(y, m)){
                m++;
                d = 1;

                if(m > 12){
                    y++;
                    m = 1;
                }
            }
            if (EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}
        }
    }else{
        for( ; AddOrSubtractDay < 0 ; AddOrSubtractDay++ ){
            d--;
            if(d == 0){
                m--;
                if(m == 0){
                    y--;
                    m = 12;
                }
                d = EMF_PersianCalendar_DaysInMonth_Return_28To31_0OutOfReange(y, m);
                if(d == 0){return 0;}
            }
            if (EMF_PersianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}
        }
    }

    *Year1_1400to1500  = y;
    *Month_1to12   = m;
    *Day_1to31     = d;

    return 1;
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinGregorianDate : 2021/03/21   MaxGregorianDate : 2122/03/20
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
bool EMF_PersianCalendar_ConvertDate_PersianToGregorian_Return_1Ok_0OutOfReange(
    uint16 PersianYear_1400to1500, uint8 PersianMonth_1to12, uint8 PersianDay_1to31,
    uint16 *ReturnGregorianYear_2021to2122, uint8 *ReturnGregorianMonth_1to12, uint8 *ReturnGregorianDay_1to31){

    int32 DifferenceInDays = EMF_PersianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(PersianYear_1400to1500, PersianMonth_1to12, PersianDay_1to31, 1400, 1, 1);
    if(DifferenceInDays == -1){return 0;}

    *ReturnGregorianYear_2021to2122 = 2021;
    *ReturnGregorianMonth_1to12 = 3;
    *ReturnGregorianDay_1to31 = 21;
    if(EMF_GregorianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(ReturnGregorianYear_2021to2122, ReturnGregorianMonth_1to12, ReturnGregorianDay_1to31, DifferenceInDays) == 1){
        return 1;
    }

    return 0;
}
//=========================================================================================
//=========================================================================================
/**
* @brief MinPersianDate   : 1400/01/01     MaxPersianDate : 1500/12/29
*/
uint8 EMF_PersianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange(uint16 Year1_1400to1500, uint8 Month_1to12, uint8 Day_1to31){
    uint16 y;
    uint8 m, d, r;

    if(EMF_PersianCalendar_ConvertDate_PersianToGregorian_Return_1Ok_0OutOfReange(Year1_1400to1500, Month_1to12, Day_1to31, &y, &m, &d) == 1){
        r = EMF_GregorianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange(y, m, d);
        if(r != 0){
            return r;
        }
    }

    return 0;
}
#endif
