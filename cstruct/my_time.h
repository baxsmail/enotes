#pragma once
#include <math.h>
#include <stdbool.h>


struct _tm
{
    long unix_time;
    long unix_msec;
    long tm_sec;
    long tm_min;
    long tm_hour;
    long tm_mday;
    long tm_mon;
    long tm_year;
    long tm_wday;
    long tm_yday;
} typedef tm;

void calcDate(tm *tm_ptr);
