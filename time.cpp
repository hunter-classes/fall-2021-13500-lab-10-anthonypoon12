#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
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

std::string getGenre(Movie mv){
    std::string g="";
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return g;
}
std::string getTimeSlot(TimeSlot ts){
    std::string output="";
    output+=ts.movie.title + " ";
    output += getGenre(ts.movie);
    output += "( " + ts.movie.duration;
    output+= ") ";
    output += "[ starts at " + ts.startTime.h;
    output+= ":" + ts.startTime.m;
    output+= ",";
    Time end = addMinutes(ts.startTime, ts.movie.duration);
    output+="ends by " + end.h;
    output += ":" + end.m;
    output += "]";
    return output;
}