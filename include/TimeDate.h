#ifndef TIMEDATE_H
#define TIMEDATE_H

#include <iostream>
#include <fstream>
#include <time.h>
#include<string>

using namespace std;
class TimeDate
{
    int day,month,year,hours,minutes,seconds;
    public:
        TimeDate();
        virtual ~TimeDate();
        TimeDate tempsCourant();
        friend ostream& operator<<(ostream& out,TimeDate& TD);
};

#endif // TIMEDATE_H
