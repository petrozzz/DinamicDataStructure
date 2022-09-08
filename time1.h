#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Time {
private:
    int seconds;
    int minutes;
    int hours;

public:
    Time(int hours, int minutes, int seconds);
    Time();
    Time(int sec);

    void show();
    Time& interval(Time &tm);
    Time& operator - (Time& tm);
    int toSec();
    friend ostream& operator<<(ostream& out,  Time& tm) {
            out << tm.hours << ":" << tm.minutes << ":" << tm.seconds;
            return out;
    }
};

#endif // TIME_H
