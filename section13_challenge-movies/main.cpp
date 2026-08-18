#include <iostream>

#include "Movies.h"

int main() {
    Movies my_movies;
    my_movies.add_movie("E.T", "PG", 1);
    my_movies.add_movie("Dune", "15", 2);
    my_movies.add_movie("Predator", "18", 2);
    my_movies.add_movie("Dune", "15", 2);
    my_movies.add_movie("Monsters Inc", "PG", 2);
    my_movies.add_movie("Toy Story 2", "PG", 2);

    my_movies.display();

    std::cin.get();
    return 0;
}
