#include <iostream>
using std::cout;
#include "time.h"

Time::Time(int h, int m, int s) { setTime(h, m, s); }

void Time::setTime(int h, int m, int s) {
    hour   = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printMilitary() const {
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute;
}

void Time::printStandard() const {
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << (minute < 10 ? "0" : "") << minute << ":"
         << (second < 10 ? "0" : "") << second
         << (hour < 12 ? " AM" : " PM");
}
