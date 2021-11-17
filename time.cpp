#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
}
int minutesSinceMidnight(Time time){
    int hours = time.h%24;
    int min = time.m%60;
    hours += time.m/60;
    return hours*60 + min;
}
int minutesUntil(Time earlier, Time later){
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
    output += " (" + std::to_string(ts.movie.duration);
    output+= " min) ";
    output += "[starts at " + std::to_string(ts.startTime.h);
    output+= ":" + std::to_string(ts.startTime.m);
    output+= ",";
    Time end = addMinutes(ts.startTime, ts.movie.duration);
    output+=" ends by " + std::to_string(end.h);
    output += ":" + std::to_string(end.m);
    output += "]";
    return output;
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot output = {nextMovie,addMinutes(ts.startTime, ts.movie.duration)};
    return output;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    Time start1 = ts1.startTime;
    Time start2 = ts2.startTime;
    Time end1 = addMinutes(ts1.startTime, ts1.movie.duration);
    Time end2 = addMinutes(ts2.startTime, ts2.movie.duration);
    if (minutesSinceMidnight(start1)==minutesSinceMidnight(start2))
        return true;
    if (minutesSinceMidnight(end1)==minutesSinceMidnight(end2))
        return true;
    if (minutesSinceMidnight(end1)<minutesSinceMidnight(start1)){
        if (!(minutesSinceMidnight(start2)>minutesSinceMidnight(end1) && minutesSinceMidnight(start2)<minutesSinceMidnight(start1)))
            return true;
        if (!(minutesSinceMidnight(end2)>minutesSinceMidnight(end1) && minutesSinceMidnight(end2)<minutesSinceMidnight(start1)))
            return true;
    }
    else{
        if ((minutesSinceMidnight(start2)<minutesSinceMidnight(end1) && minutesSinceMidnight(start2)>minutesSinceMidnight(start1)))
            return true;
        if ((minutesSinceMidnight(end2)<minutesSinceMidnight(end1) && minutesSinceMidnight(end2)>minutesSinceMidnight(start1)))
            return true;
    }
    return false;
}