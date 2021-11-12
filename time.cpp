#include <iostream>
#include "time.h"
#include "movie.h"
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
Time addMinutes(Time time0, int min){
    Time output = {time0.h,time0.m};
    output.m += min;
    if (output.m>=60 || output.m<0){
        output.h+=output.m/60;
        output.m = output.m % 60;
    }
    if (output.h>=24)
        output.h = output.h % 24;
    return output;
}
std::string getTimeSlot(){
    std::string output="";
    return output;
}