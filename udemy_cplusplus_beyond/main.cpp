
#include <iostream>
#include <string>


int is_in(const char *s, char c) {
    std::cout << "Using the Char is_in() function" << std::endl;
    while (*s) {
        if (*s == c) {
            return 1;
        } else {
            s++;
        }
    }
    return 0;
}

bool is_in(const std::string &s, char c) {
    std::cout << "Using the String is_in() function" << std::endl;
    return s.find(c) != std::string::npos;
}

int main() {
    int favourite_number;
    int attempts = 0;
    std::string message;
    std::string p = "potato";
    const char *w = "potato";

    char c = 'x';

    int result = is_in(p, c);
    std::cout << "Is " << c << " in " << p << ": " << result << std::endl;

    int result2 = is_in(w, c);
    std::cout << "Is " << c << " in " << w << ": " << result2 << std::endl;


    do {
        if ( attempts == 0 ) {
            message = "Enter your favourite number between 1 and 100: ";
        } else {
            message = "ERROR  number must be between 1 and 100: ";
        }
        std::cout << message;

        std::cin >> favourite_number;
        attempts++;
    } while ((favourite_number < 1 || favourite_number > 100) && attempts < 5);

    if (attempts >= 5) {
        std::cout << "Too many attempts, think again for a number between 1 and 100 and try again"<< std::endl;
    } else {
        std::cout << "Amazing that is my favourite number too! [" << favourite_number << "] " << std::endl;
    }


    return 0;

}