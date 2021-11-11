#include <iostream>
#include "time.h"
void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
}
int minutesSinceMidnight(Time time){
    return time.h*60 + time.m;
}
int minutesUntil(Time earlier, Time later){
    if (minutesSinceMidnight(earlier)>minutesSinceMidnight(later))
        return minutesSinceMidnight(earlier) - minutesSinceMidnight(later);
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}