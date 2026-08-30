#include <iostream>
#include <fstream>
#include <cstring>   // for std::strerror
#include <cerrno>    // for errno

int main() {
    std::string sourcefile {"../romeoandjuliet.txt"};
    std::string targetfile {"../romeoandjuliet_copy.txt"};

    std::ifstream in_file{sourcefile};
    std::ofstream out_file{targetfile};
    std::string line {};

    if (!in_file.is_open()) {
        std::cerr << "Can't open file: " << sourcefile
                   << " (" << std::strerror(errno) << ")" << std::endl;
        return 1;
    }

    if (!out_file.is_open()) {
        std::cerr << "Can't open file: " << targetfile
                   << " (" << std::strerror(errno) << ")" << std::endl;
        return 1;
    }
    // Read line by line

    int lineNo {0};
    while (std::getline(in_file, line)) {
        if (line.length() > 0 ) {
            ++lineNo;
          //  out_file << lineNo << " : " << line << std::endl;
            out_file << std::setw(7) << std::left << lineNo << line << std::endl;
        } else {
            out_file << line << std::endl;
        }
    }


    std::cout << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}