/*
Author: Anthony Poon
Course: CSCI-135
Instructor: Zamansky/ Tong Yi
Assignment: Lab 10 main

Main file for Lab 10
*/
#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
int main(){
    Movie movie1 = {"Back to the Future", Genre::COMEDY, 116};
    Movie movie2 = {"Black Panther", Genre::ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    std::cout<<"Timeslot 1: " + getTimeSlot(morning) + "\n";
    std::cout<<"Timeslot 2: " + getTimeSlot(daytime) + "\n";
    std::cout<<"Timeslot 3: " + getTimeSlot(evening) + "\n";
    std::cout<<"Minutes since Midnight for start of Timeslot 1: " + std::to_string(minutesSinceMidnight(morning.startTime))<< std::endl;
    std::cout<<"Minutes since Midnight for start of Timeslot 2: " + std::to_string(minutesSinceMidnight(daytime.startTime))<< std::endl;
    std::cout<<"Minutes since Midnight for start of Timeslot 3: " + std::to_string(minutesSinceMidnight(evening.startTime))<< std::endl;
    std::cout<<"Minutes between start of Timeslot 1 and 2: " + std::to_string(minutesUntil(morning.startTime, daytime.startTime))<<std::endl;
    std::cout<<"Minutes between start of Timeslot 2 and 3: " + std::to_string(minutesUntil(daytime.startTime, evening.startTime))<<std::endl;
    std::cout<<"Minutes between start of Timeslot 3 and 1: " + std::to_string(minutesUntil(evening.startTime, morning.startTime))<<std::endl;
    std::cout<<"Adding ten minutes to starttime of Timeslot1: " + getTimeSlot({movie1, addMinutes({9,15},10)})<<std::endl;
    std::cout<<"Adding ten minutes to starttime of Timeslot2: " + getTimeSlot({movie2, addMinutes({12,15},10)})<<std::endl;
    std::cout<<"Adding two hundred minutes to starttime of Timeslot2: " + getTimeSlot({movie2, addMinutes({12,15},200)})<<std::endl;
    std::cout<<"Adding five hundred minutes to starttime of Timeslot2: " + getTimeSlot({movie2, addMinutes({16,45},500)})<<std::endl;
    std::cout<<"scheduling movie after first timeslot: " + getTimeSlot(scheduleAfter(morning, movie2))<<std::endl;
    std::cout<<std::boolalpha<<"Is there overlap between the new movie and timeslot 2: "<<timeOverlap(daytime, scheduleAfter(morning, movie2))<<std::endl;
    return 0;
}