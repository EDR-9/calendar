#ifndef  DATE_CFG_H
#define  DATE_CFG_H



#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


enum MonthNumberPositions{
    JAN_N=1,
    FEB_N,
    MAR_N,
    APR_N,
    MAY_N,
    JUN_N,
    JUL_N,
    AUG_N,
    SEP_N,
    OCT_N,
    NOV_N,
    DEC_N
};


#define  DAY_SECONDS                86400
#define  MAX_WEEK_STR_LEN              30
#define  MAX_DAY_STR_LEN                6
#define  MAX_WEEKS_MONTH                5
#define  WEEK_DAYS                      7
#define  MONTH_WEEKS                    4
#define  MONTH_AVG_DURATION            30
#define  REGULAR_YEAR_DAYS            365
#define  BISIESTO_YEAR_DAYS           366

/* time library defined offsets */
#define  LIB_YEAR_OFFSET             1900
#define  LIB_DAY_OFFSET                 1   
#define  LIB_MONTH_OFFSET               1
#define  LIB_SEC_OFFSET
#define  LIB_MIN_OFFSET




#endif