#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include "Movie.h"

class Movies {
public:
    Movies();
    Movies(const Movies& other);                 // copy constructor
    Movies(Movies&& source) noexcept;             // move constructor
    Movies& operator=(const Movies& other);       // copy assignment
    Movies& operator=(Movies&& other) noexcept;   // move assignment
    ~Movies();

    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    bool display() const;

private:
    std::vector<Movie>* movies;
};

#endif