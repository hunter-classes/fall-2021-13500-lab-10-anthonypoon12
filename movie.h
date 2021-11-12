#pragma once
class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
void printMovie(Movie mv);