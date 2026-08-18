#include <iostream>
#include <cmath>
using namespace std;

double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);

void temperature_conversion(double fahrenheit_temperature) {
    double celcius_temperature {};
    double kelvin_temperature {};

    celcius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
    kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);

    cout << "The Fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celcius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

int main() {
    cout << endl << endl;
    temperature_conversion(100);
    cout << endl << endl;
    return 0;
}


double fahrenheit_to_celsius(double fahrenheit) {
    return round((5.0/9.0) * (fahrenheit - 32.0));
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return fahrenheit_to_celsius(fahrenheit) + 273; ;
}