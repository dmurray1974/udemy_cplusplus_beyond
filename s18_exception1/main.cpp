#include <iostream>

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0 || miles == 0) {
        throw std::invalid_argument("Running calculate_mpg encountered error, gallons/miles must be non-zero");
    }
    if (gallons < 0 || miles < 0) {
        throw std::invalid_argument("Running calculate_mpg encountered error, gallons/miles must be greater than zero");
    }
    return static_cast<double>(miles) / gallons;
}


int main() {
    int miles {-20};
    int gallons {10};
    double miles_per_gallon {};

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}