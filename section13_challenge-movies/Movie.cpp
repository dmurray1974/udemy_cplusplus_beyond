//
// Created by Darren Murray on 16/08/2026.
//

#include "Movie.h"
#include <iostream>

int Movie::number_of_movies {0};

// Constructor
Movie::Movie(std::string p_name, std::string p_rating, int p_watched)
{
    std::cout << ".Creating Movie..." << std::endl;
    name = new std::string(p_name);
    rating = new std::string(p_rating);
    watched = new int(p_watched);
    this->number_of_movies++;
    std::cout << "Movie Number: " << this->number_of_movies << std::endl;
}

// Deep Copy Constructor
Movie::Movie(const Movie& other)
{
    std::cout << "Copy Constructor - Made copy of : " << *other.name << std::endl;
    name = new std::string(*other.name);
    rating = new std::string(*other.rating);
    watched = new int(*other.watched);
}

// Move Constructor - steals pointers instead of allocating new memory
Movie::Movie(Movie&& source) noexcept
    : name(source.name), rating(source.rating), watched(source.watched)
{
    std::cout << "Move Constructor - Moved : " << *name << std::endl;
    source.name = nullptr;
    source.rating = nullptr;
    source.watched = nullptr;
}

// Copy Assignment Operator
Movie& Movie::operator=(const Movie& other)
{
    std::cout << "Copy Assignment - Made copy of : " << *other.name << std::endl;
    if (this == &other) {
        return *this;  // guard against self-assignment
    }

    // free existing resources first
    delete name;
    delete rating;
    delete watched;

    // allocate and copy new resources
    name = new std::string(*other.name);
    rating = new std::string(*other.rating);
    watched = new int(*other.watched);

    return *this;
}

// Move Assignment Operator
Movie& Movie::operator=(Movie&& other) noexcept
{
    if (this == &other) {
        return *this;  // guard against self-assignment
    }

    // free existing resources first
    delete name;
    delete rating;
    delete watched;

    // steal other's pointers
    name = other.name;
    rating = other.rating;
    watched = other.watched;

    // leave other in a valid, destructible state
    other.name = nullptr;
    other.rating = nullptr;
    other.watched = nullptr;

    return *this;
}

// Destructor
Movie::~Movie() {
    if (name) {
        std::cout << ".Destroying Movie..." << *name << std::endl;
    } else {
        std::cout << ".Destroying Movie... (moved-from)" << std::endl;
    }
    delete name;
    delete rating;
    delete watched;
}

std::string Movie::get_name(void) const {
    return *name;
}

bool Movie::increment_watched(void) {
    (*watched)++;
    return true;
}

std::string Movie::display() const {
    return *name;
}