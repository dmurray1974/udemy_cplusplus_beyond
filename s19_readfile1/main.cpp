#include <iostream>
#include <fstream>
#include <cstring>   // for std::strerror
#include <cerrno>    // for errno

int main() {
    std::string filename {"../plop.txt"};
    std::ifstream in_file{filename};
    std::string line {};

    if (!in_file.is_open()) {
        std::cerr << "Can't open file: " << filename
                   << " (" << std::strerror(errno) << ")" << std::endl;
        return 1;
    }


    // Read line by line
/*
 *    while (std::getline(in_file, line)) {
        std::cout << "--> " << line << std::endl;
    }
*/
    char c {};
    while (in_file.get(c)) {
        std::cout << c;
    }
    std::cout << std::endl;
    in_file.close();

    return 0;
}