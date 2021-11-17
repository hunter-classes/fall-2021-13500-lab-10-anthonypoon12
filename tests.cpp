#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "timeslot.h"
#include "movie.h"

Movie movie1 = {"Back to the Future", Genre::COMEDY, 116};
Movie movie2 = {"Black Panther", Genre::ACTION, 134};
TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}};
TEST_CASE("minutes since midnight"){
    CHECK(minutesSinceMidnight({0,0})==0);
    CHECK(minutesSinceMidnight({1,0})==60);
    CHECK(minutesSinceMidnight({12,50})==12*60+50);
    CHECK(minutesSinceMidnight({42,12})==18*60+12);
}
TEST_CASE("minutesUntil"){
    CHECK(minutesUntil({0,0},{11,30})==11*60 + 30);
    CHECK(minutesUntil({11,30},{8,30})== (8*60 + 30) - (11*60 + 30));
    CHECK(minutesUntil({11,30},{20,30})== (20*60 + 30) - (11*60 + 30));
}
TEST_CASE("addminutes"){
    Time one = {1,30};
    Time two = {22, 43};
    Time three = {23, 59};
    CHECK(addMinutes(one,1).h==1);
    CHECK(addMinutes(one,1).m==31);
    CHECK(addMinutes(two,60).h==23);
    CHECK(addMinutes(three,60).h==0);
    CHECK(addMinutes(three,60).m==59);
    CHECK(addMinutes(one,-90).h==0);
    CHECK(addMinutes(one,-90).m==0);
    CHECK(addMinutes({9,15},116).h==11);
    CHECK(addMinutes({9,15},116).m==11);
    CHECK(addMinutes({9,15},134).h==11);
    CHECK(addMinutes({9,15},134).m==29);
}
TEST_CASE("getTimeSlot"){
    std::string test1 = "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]";
    std::string test2 = "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]";
    std::string test3 = "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]";
    
    CHECK(getTimeSlot(morning) == test1);
    CHECK(getTimeSlot(daytime) == test2);
    CHECK(getTimeSlot(evening) == test3);
}
TEST_CASE("scheduleAfter"){
    CHECK(scheduleAfter(morning, movie2).movie.title == movie2.title);
    CHECK(scheduleAfter(morning, movie2).startTime.h == 11);
    CHECK(scheduleAfter(morning, movie2).startTime.m == 11);
}
TEST_CASE("overlap"){
    Movie movie3 = {"Hello", Genre::ACTION, 120};
    TimeSlot overlaptest = {movie3, {8, 0}};
    Movie movie4 = {"Hi", Genre::ACTION, 120};
    TimeSlot overlaptest2 = {movie4, {9, 0}};
    Movie movie5 = {"Bye", Genre::ACTION, 120};
    TimeSlot overlaptest3 = {movie5, {10, 0}};
    Movie movie6 = {"B", Genre::ACTION, 120};
    TimeSlot overlaptest4 = {movie6, {23, 0}};
    Movie movie7 = {"A", Genre::ACTION, 120};
    TimeSlot overlaptest5 = {movie7, {0, 10}};
    Movie movie8 = {"D", Genre::ACTION, 0};
    TimeSlot overlaptest6 = {movie8, {10, 10}};
    Movie movie9 = {"C", Genre::ACTION, 120};
    TimeSlot overlaptest7 = {movie9, {10, 10}};
    CHECK(timeOverlap(overlaptest, overlaptest2)==true);
    CHECK(timeOverlap(overlaptest2, overlaptest)==true);
    CHECK(timeOverlap(overlaptest3, overlaptest)==false);
    CHECK(timeOverlap(overlaptest5, overlaptest4)==true);
    CHECK(timeOverlap(overlaptest5, overlaptest4)==true);
    CHECK(timeOverlap(overlaptest6, overlaptest7)==true);
}