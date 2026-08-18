#include <iostream>
using namespace std;

unsigned long long factorial( unsigned long long n) {
    unsigned long long result {};
    if (n== 0)
        return 1;
    return n * factorial(n-1);
}

unsigned long long factorial_demo( unsigned long long n) {
    //cout << "Running Factorial(" << n << ")" << endl;
    unsigned long long result {};
    if (n== 0)
        return 1;
    result = n * factorial(n-1);
    cout << "Factorial of " << n << "! = " << result << endl;
    return result;
}
unsigned long long fibonacci( unsigned long long n) {
    //cout << "Running Fibonacci(" << n << ")" << endl;
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int sum_of_digits( int n ) {
    cout << "..Sum of digits: " << n << endl;
    if (n == 0) {
        return 0;
    }
    return (n % 10 + sum_of_digits(n/10));
}

int main() {
    int factorial_seed {10};
    //std::cout << "Factorial(" << factorial_seed << "): " << factorial(factorial_seed) << std::endl;

    //cout << "Fibonacci(30): " << fibonacci(30) << endl;

    cout << endl << sum_of_digits(123) << endl;
    return 0;
}