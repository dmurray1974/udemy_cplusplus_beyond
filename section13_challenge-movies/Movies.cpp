//
// Created by Darren Murray on 16/08/2026.
//

#include "Movies.h"
#include <iostream>

// Constructor
Movies::Movies() {
    std::cout << "Creating Movies..." << std::endl;
    movies = new std::vector<Movie>;
}

// Deep Copy Constructor
Movies::Movies(const Movies& other)
{
    movies = new std::vector<Movie>(*other.movies);
    std::cout << "Copy Constructor - Made copy of : " << other.movies->size() << " movies" << std::endl;
}

// Move Constructor - steals the pointer instead of allocating new memory
Movies::Movies(Movies&& source) noexcept
    : movies(source.movies)
{
    std::cout << "Move Constructor - Moved " << movies->size() << " movies" << std::endl;
    source.movies = nullptr;
}

// Copy Assignment Operator
Movies& Movies::operator=(const Movies& other)
{
    std::cout << "Copy Assignment - Made copy of : " << other.movies->size() << " movies" << std::endl;
    if (this == &other) {
        return *this;  // guard against self-assignment
    }

    delete movies;
    movies = new std::vector<Movie>(*other.movies);

    return *this;
}

// Move Assignment Operator
Movies& Movies::operator=(Movies&& other) noexcept
{
    if (this == &other) {
        return *this;  // guard against self-assignment
    }

    delete movies;
    movies = other.movies;
    other.movies = nullptr;

    return *this;
}

// Destructor
Movies::~Movies() {
    std::cout << "Destroying Movies..." << std::endl;
    delete movies;
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie : *movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    Movie temp {name, rating, watched};
    movies->push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (Movie &movie : *movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

bool Movies::display() const {
    if (movies->empty()) {
        std::cout << "No movies found." << std::endl;
        return false;
    }
    std::cout << "=========================================" << std::endl;
    for (const Movie &movie : *movies) {
        std::cout << "    " << movie.display() << std::endl;
    }
    std::cout << "=========================================" << std::endl;
    return true;
}