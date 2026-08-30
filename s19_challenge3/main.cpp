#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int count_occurrences(const std::string& str, const std::string& substr) {
    if (substr.empty()) return 0;

    int count = 0;
    size_t pos = 0;

    while ((pos = str.find(substr, pos)) != std::string::npos) {
        ++count;
        pos += substr.length();   // move past this match
    }

    return count;
}

int count_words(const std::string& str) {
    std::stringstream ss(str);
    std::string word;
    int count = 0;

    while (ss >> word) {
        ++count;
    }

    return count;
}

int main() {
    std::ifstream inputFile {};
    std::string word_to_find {};
    std::string line {};
    std::string filename {"../romeoandjuliet.txt"};
    int word_count {0};
    int match_count {0};

    inputFile.open(filename);
    if (!inputFile) {
        std::cerr << "Could not open file : " << filename << std::endl;
        return 1;
    }

    word_to_find = "love";
    while (std::getline(inputFile, line)) {
        match_count += count_occurrences(line, word_to_find);
        word_count += count_words(line);
    }

    std::cout << "Found " << match_count << " occurrences of " << word_to_find << " in text." << std::endl;
    std::cout << "Total words in text :  " << word_count << std::endl;

    return 0;
}