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
#include "EMF.h"
#if defined(EMF_DATE_GREGORIANCALENDAR_CUBEIDE__HAL)

 const uint8 _DayesOfMonthNonLeapYearGregorianCalendar[12] = {
                                                                31, // January
                                                                28, // February
                                                                31, // March
                                                                30, // April
                                                                31, // May
                                                                30, // June
                                                                31, // July
                                                                31, // August
                                                                30, // September
                                                                31, // October
                                                                30, // November
                                                                31  // December
                                                             };


const uint8 _DayesOfMonthLeapYearGregorianCalendar[12] = {
                                                            31, // January
                                                            29, // February
                                                            31, // March
                                                            30, // April
                                                            31, // May
                                                            30, // June
                                                            31, // July
                                                            31, // August
                                                            30, // September
                                                            31, // October
                                                            30, // November
                                                            31  // December
                                                         };
//=========================================================================================
//=========================================================================================
uint8 EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(uint16 Year_1to9999){
    if((Year_1to9999 == 0) || (Year_1to9999 > 9999)){return 2;}

    return ((Year_1to9999 % 4 == 0) && (Year_1to9999 % 100 != 0)) || (Year_1to9999 % 400 == 0);
}
//=========================================================================================
//=========================================================================================
bool EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31){
    if((Month_1to12 == 0) || (Month_1to12 > 12)){return 0;}
    if(Day_1to31 == 0){return 0;}

    switch (EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Year_1to9999)) {
        case 2:
            return 0;
        case 1:
            if(Day_1to31 > _DayesOfMonthLeapYearGregorianCalendar[Month_1to12 - 1]){return 0;}
            break;
        case 0:
            if(Day_1to31 > _DayesOfMonthNonLeapYearGregorianCalendar[Month_1to12 - 1]){return 0;}
            break;
    }

    return 1;
}
//=========================================================================================
//=========================================================================================
uint8 EMF_GregorianCalendar_CompareDates_Return_Date1_1Greater_0Smaller_2Equal(uint16 Year1, uint8 Month1, uint8 Day1, uint16 Year2, uint8 Month2, uint8 Day2){
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
uint8 EMF_GregorianCalendar_DaysInMonth_Return_28To31_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12){
    if(EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year_1to9999, Month_1to12, 1) == 0){return 0;}

    if(EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Year_1to9999) == 0){
        return _DayesOfMonthNonLeapYearGregorianCalendar[Month_1to12 - 1];      
    }

    return _DayesOfMonthLeapYearGregorianCalendar[Month_1to12 - 1];
}
//=========================================================================================
//=========================================================================================
uint16 EMF_GregorianCalendar_DayOfYear_Return_1To366_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31){
    // بررسی اعتبار تاریخ
    if (EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year_1to9999, Month_1to12, Day_1to31) == 0){
        return 0; // تاریخ نامعتبر
    }

    uint16 daysPassed = 0;

    // جمع روزهای ماه‌های قبل
    for (uint8 m = 1; m < Month_1to12; m++){
        uint8 daysInMonth = EMF_GregorianCalendar_DaysInMonth_Return_28To31_0OutOfReange(Year_1to9999, m);
        if (daysInMonth == 0){
            return 0; // خطا یا ماه نامعتبر
        }
        daysPassed += daysInMonth;
    }

    // اضافه کردن روزهای ماه جاری
    daysPassed += Day_1to31;

    return daysPassed;
}
//=========================================================================================
//=========================================================================================
int32 EMF_GregorianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(uint16 Year1_1to9999, uint8 Month1_1to12, uint8 Day1_1to31, uint16 Year2_1to9999, uint8 Month2_1to12, uint8 Day2_1to31){
    int32 sum1 = 0, sum2 = 0;
    uint16 BaseYear, Counter;

    // 1. اعتبارسنجی
    if ((EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year1_1to9999, Month1_1to12, Day1_1to31) == 0) ||
        (EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year2_1to9999, Month2_1to12, Day2_1to31) == 0)){

        return -1;
    }

    BaseYear = (Year1_1to9999 < Year2_1to9999) ? Year1_1to9999 : Year2_1to9999;

    for( Counter = BaseYear ; Counter < Year1_1to9999 ; Counter++){
        if(EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Counter) == 1){
            sum1 += 366;
        }else{
            sum1 += 365;
        }
    }

    for( Counter = BaseYear ; Counter < Year2_1to9999 ; Counter++){
        if(EMF_GregorianCalendar_IsLeapYear_Return_1isLeap_0IsNotLeap_2OutOfReange(Counter) == 1){
            sum2 += 366;
        }else{
            sum2 += 365;
        }
    }
    
    sum1 += EMF_GregorianCalendar_DayOfYear_Return_1To366_0OutOfReange(Year1_1to9999, Month1_1to12, Day1_1to31);
    sum2 += EMF_GregorianCalendar_DayOfYear_Return_1To366_0OutOfReange(Year2_1to9999, Month2_1to12, Day2_1to31);

    return (sum1 > sum2) ? (sum1 - sum2) : (sum2 - sum1);
}
//=========================================================================================
//=========================================================================================
bool EMF_GregorianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(uint16 *Year_1to9999, uint8 *Month_1to12, uint8 *Day_1to31, int32 AddOrSubtractDay){
    uint16 y = *Year_1to9999;
    uint8  m = *Month_1to12;
    uint8  d = *Day_1to31;

    if (EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}

    if (AddOrSubtractDay >= 0) {
        for( ; AddOrSubtractDay > 0 ; AddOrSubtractDay-- ){
            d++;
            if(d > EMF_GregorianCalendar_DaysInMonth_Return_28To31_0OutOfReange(y, m)){
                m++;
                d = 1;

                if(m > 12){
                    y++;
                    m = 1;
                }
            }
            if (EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}
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
                d = EMF_GregorianCalendar_DaysInMonth_Return_28To31_0OutOfReange(y, m);
                if(d == 0){return 0;}
            }
            if (EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(y, m, d) == 0){return 0;}
        }
    }

    *Year_1to9999  = y;
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
bool EMF_GregorianCalendar_ConvertDate_GregorianToPersian_Return_1Ok_0OutOfReange(
    uint16 GregorianYear_2021to2122, uint8 GregorianMonth_1to12, uint8 GregorianDay_1to31,
    uint16 *ReturnPersianYear_1400to1500, uint8 *ReturnPersianMonth_1to12, uint8 *ReturnPersianDay_1to31){

    if(EMF_GregorianCalendar_CompareDates_Return_Date1_1Greater_0Smaller_2Equal(
        GregorianYear_2021to2122, GregorianMonth_1to12, GregorianDay_1to31,
        2021, 03, 21) == 0){
            
        return 0;
    }

    int32 DifferenceInDays = EMF_GregorianCalendar_DifferenceInDays_Return_0Tox_N1OutOfReange(GregorianYear_2021to2122, GregorianMonth_1to12, GregorianDay_1to31, 2021, 3, 21);
    if(DifferenceInDays == -1){return 0;}

    *ReturnPersianYear_1400to1500 = 1400;
    *ReturnPersianMonth_1to12 = 1;
    *ReturnPersianDay_1to31 = 1;
    if(EMF_PersianCalendar_AddOrSubtractDay_Return_1Ok_0OutOfReange(ReturnPersianYear_1400to1500, ReturnPersianMonth_1to12, ReturnPersianDay_1to31, DifferenceInDays) == 1){
        return 1;
    }

    return 0;
}
//=========================================================================================
//=========================================================================================
uint8 EMF_GregorianCalendar_DayOfWeek_1To7SaturdayToFriday_0OutOfReange(uint16 Year_1to9999, uint8 Month_1to12, uint8 Day_1to31){
    if(EMF_GregorianCalendar_IsValidDate_Return_1Valid_0Notvalid(Year_1to9999, Month_1to12, Day_1to31) == 0){
        return 0;
    }

    if (Month_1to12 < 3){
        Month_1to12 += 12;
        Year_1to9999 -= 1;
    }

    uint8_t K = Year_1to9999 % 100;
    uint16_t J = Year_1to9999 / 100;

    int8_t h = (int8_t)((Day_1to31 + ((13 * (Month_1to12 + 1)) / 5) + K + (K / 4) + (J / 4) + (5 * J)) % 7);

    return h + 1; // 1=Saturday ... 7=Friday
}



#endif
