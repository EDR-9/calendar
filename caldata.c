#include "caldata.h"



static void get_current_time( struct tm* __timeholder )
{
    time_t __rawTimeSec = time(0);
    struct tm* __tmp = localtime(&__rawTimeSec);

    if ( __tmp )
    {
        *__timeholder = *__tmp;
        // memcpy(__timeholder, __tmp, sizeof(struct tm));
    }

    /* using offset to set proper values */
    __timeholder->tm_mon =+ LIB_MONTH_OFFSET;
    __timeholder->tm_wday =+ LIB_DAY_OFFSET;
    __timeholder->tm_yday =+ LIB_DAY_OFFSET;
    __timeholder->tm_year =+ LIB_YEAR_OFFSET;
}


/* Calculate the number of days in current month */
static time_t month_lasting( struct tm __time )
{
    struct tm __tmpRefTime;
    time_t s1, s2;

    __tmpRefTime = __time;
    __tmpRefTime.tm_mon -= 1;

    //printf("copy: %d %d\n", __tmpRefTime.tm_mon, __time.tm_mon);

    s1 = mktime(&__tmpRefTime);
    s2 = mktime(&__time);

    //printf("%ld %ld\ndays: %ld\n", s1, s2, (s2 - s1)/86400);

    return ((s2 - s1)/DAY_SECONDS);
}


static void month_data_gen(  )
{
    struct tm todayDate;
    get_current_time( &todayDate );

    char weekDaysLine[MAX_WEEK_STR_LEN ] = {0};
    char monthWeeksMatrix[MAX_WEEKS_MONTH][MAX_WEEK_STR_LEN] = {0};
    time_t monthDays = month_lasting(todayDate);
    uint8_t bisiestoYear = 0;
    uint8_t weekPos = 0;

    /* Checking for bisiesto year to set a flag */
    if ( todayDate.tm_year % 4 == 0 )
    {
        bisiestoYear = 1;
    }

    for ( uint8_t monthday = 1; monthday <= monthDays; monthday++ )
    {
        char numstr[MAX_DAY_STR_LEN];

        if ( monthday >= 1 && monthday <= 9 )
        {
            snprintf(numstr, sizeof(numstr), "%d   ", monthday);
        }
        else
        {
            snprintf(numstr, sizeof(numstr), "%d  ", monthday);
        }

        strncat(weekDaysLine, numstr, sizeof(numstr));

        if ( monthday % WEEK_DAYS == 0 || ( !strcmp(weekDaysLine, "29  ") && todayDate.tm_mon == FEB_N && bisiestoYear ) ||
            ( !strcmp(weekDaysLine, "29  30  ") && (todayDate.tm_mon == APR_N || todayDate.tm_mon == JUN_N || todayDate.tm_mon == SEP_N || todayDate.tm_mon == NOV_N) ) ||
            ( !strcmp(weekDaysLine, "29  30  31  ") && (todayDate.tm_mon == JAN_N || todayDate.tm_mon == MAR_N || todayDate.tm_mon == MAY_N || todayDate.tm_mon == JUL_N || todayDate.tm_mon == AUG_N || todayDate.tm_mon == OCT_N || todayDate.tm_mon == DEC_N) )
        )
        {
            printf("%s\n", weekDaysLine);
            //snprintf(copy, 5, "%d\n", monthday);

            /* storing each line in matrix */
            strcpy(monthWeeksMatrix[weekPos], weekDaysLine);

            /* string line clear to store next one */
            *weekDaysLine = '\0';

            weekPos++;
        }
    }

    printf("week line: %s\nlen (nothing if clean): %ld\n", weekDaysLine, strlen(weekDaysLine));

    for (uint8_t i = 0; i < MAX_WEEKS_MONTH; i++)
    {
        printf("%s\n", monthWeeksMatrix[i]);
    }

    //printf("Struct addr: %p\nhm: %p\ndm: %p\nmm: %p\nsm: %p\n", &todayDate, &todayDate.tm_hour, &todayDate.tm_mday, &todayDate.tm_min, &todayDate.tm_mon);
}


static void set_event()
{
    //
}


int main()
{
    month_data_gen();
}