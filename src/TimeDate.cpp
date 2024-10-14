#include "TimeDate.h"

TimeDate::TimeDate()
{
    //ctor
}
ostream& operator<<(ostream& out,TimeDate& TD)
{
    out<<TD.hours<<":"<<TD.minutes<<":"<<TD.seconds<<"-"<<TD.day<<"/"<<TD.month<<"/"<<TD.year;
    return out;
}
TimeDate TimeDate::tempsCourant()
{
    TimeDate d;
    time_t now;
    int day, mois, an;
    time(&now);
    struct tm *local = localtime(&now);

    d.hours=local->tm_hour;
    d.minutes=local->tm_min;
    d.seconds=local->tm_sec;
    d.day = local->tm_mday;
    d.month = local->tm_mon + 1;
    d.year = local->tm_year + 1900;
    return d ;
}

TimeDate::~TimeDate()
{
    //dtor
}
