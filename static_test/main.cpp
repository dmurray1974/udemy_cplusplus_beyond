#include <iostream>

int get_next_seq(int seed = 0);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int seed {101};
    for ( size_t i = 1; i <= 100; ++i ) {
        std::cout << get_next_seq(seed) << ", ";
        if ( i % 10 == 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}


int get_next_seq(int seed) {
    static int seq = seed;
    return ++seq;
}