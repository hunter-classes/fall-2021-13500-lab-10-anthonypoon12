#pragma once
#include "time.h"
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};
void printMovie(Movie mv);
std::string getGenre(Movie mv);