#pragma once
#include "time.h"
#include "movie.h"
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};
std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);