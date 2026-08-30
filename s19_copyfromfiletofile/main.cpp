
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile {"../source.txt"};
    std::ofstream outfile {"../target.txt"};
    std::ofstream outfileu {"../utarget.txt"};
    std::string line {};
    char c;

    if (!infile) {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    if (!outfile) {
        std::cerr << "File open error" << std::endl;
        return 2;
    }

    if (!outfileu) {
        std::cerr << "File open error" << std::endl;
        return 2;
    }

    while (std::getline(infile, line)) {
        outfile << line << std::endl;
    }

    // Unformatted, char by char

    // Reset to read again
    infile.clear();                          // clear eof/fail flags
    infile.seekg(0, std::ios::beg);          // move read position back to start
    while (infile.get(c)) {
        outfileu.put(c);
    }


    // Close files
    infile.close();
    outfile.close();
    outfileu.close();

    return 0;
}