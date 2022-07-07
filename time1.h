#ifndef TIME_H
#define TIME_H

#include <iostream>

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
};

#endif // TIME_H
