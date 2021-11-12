#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"

TEST_CASE("minutes since midnight"){
    CHECK(minutesSinceMidnight({0,0})==0);
    CHECK(minutesSinceMidnight({1,0})==60);
    CHECK(minutesSinceMidnight({12,50})==12*60+50);
    CHECK(minutesSinceMidnight({42,12})==42*60+12);
}
TEST_CASE("minutesUntil"){
    CHECK(minutesUntil({0,0},{11,30}));
    CHECK(minutesUntil({11,30},{8,30}));
    CHECK(minutesUntil({11,30},{20,30}));
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
}