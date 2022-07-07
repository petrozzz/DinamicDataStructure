#include "time1.h"

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

Time::Time() : Time(0, 0, 0) {
}

Time::Time(int sec) {
    hours = sec / 3600;
    minutes = (sec / 60) % 60;
    seconds = sec % 60;
}

void Time::show() {
    cout << hours << " " << minutes << " " << seconds << endl;
}

Time &Time::interval(Time &tm) {
    Time t1(abs(toSec() - tm.toSec()));
    return t1;
}

Time &Time::operator -(Time &tm) {
    return interval(tm);
}

int Time::toSec() {
    return (hours * 60 + minutes) * 60 + seconds;
}
