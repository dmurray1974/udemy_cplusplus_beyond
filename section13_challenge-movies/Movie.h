#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    Movie(std::string p_name, std::string p_rating, int p_watched);
    Movie(const Movie& other);              // copy constructor
    Movie(Movie&& source) noexcept;         // move constructor
    Movie& operator=(const Movie& other);   // copy assignment
    Movie& operator=(Movie&& other) noexcept; // move assignment
    ~Movie();

    std::string get_name(void) const;
    bool increment_watched(void);
    std::string display() const;

private:
    std::string* name;
    std::string* rating;
    int* watched;
    static int number_of_movies;
};

#endif