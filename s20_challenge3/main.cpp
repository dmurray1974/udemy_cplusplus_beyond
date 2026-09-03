#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include <limits>
#include <sstream>



template <typename T>
concept Iterable = requires(T t) { t.begin(); t.end(); };

template <typename T1, typename T2>
void display(const std::map<T1, T2>& m,
             size_t limit = std::numeric_limits<size_t>::max()) {
    std::cout << "[ ";
    size_t count = 0;
    for (const auto& elem : m) {
        std::cout << "[ ";
        if (count >= limit) break;

        std::cout << elem.first << ":";
        if constexpr (Iterable<T2>) {
            std::cout << "[ ";
            for (const auto& set_elem : elem.second) {
                std::cout << set_elem << " ";
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << elem.second;
        }
        std::cout << "], " << std::endl;
        ++count;
    }
    std::cout << "]" << std::endl;
}
// Part 1
void display_words(const std::map<std::string, int>& words) {
    std::cout << std::setw(15) << std::left << "\nWord"
    << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "=========================================" << std::endl;
    for (auto pair : words) {
        std::cout << std::setw(15) << std::left << pair.first
        << std::setw(7) << std::right << pair.second << std::endl;
    }
}

// Part2
void display_words(const std::map<std::string, std::set<int>>& words) {
    std::cout << std::setw(15) << std::left << "\nWord"
     << "Occurrences" << std::endl;
    std::cout << "=========================================" << std::endl;
    for (auto pair : words) {
        std::cout << std::setw(15) << std::left << pair.first
        << std::left << "[ ";
        for (auto set_elem : pair.second) {
            std::cout << set_elem << " ";
        }
    std::cout << "]" << std::endl;
    }
}

std::string clean_string(std::string word) {

    std::string cleaned {};
    const std::string chars_to_trim = "\",.;:!?()[]{}";

        size_t start = word.find_first_not_of(chars_to_trim);
        size_t end = word.find_last_not_of(chars_to_trim);

        if (start != std::string::npos) {
            cleaned = word.substr(start, end - start + 1);
        }
    return cleaned;
}


void part1() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream file("../words.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word]++;
            }
        }
        file.close();
        display_words(words);
    } else {
        std::cerr << "Could not open file" << std::endl;
    }
}



void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream file("../words.txt");
    if (file.is_open()) {
        int line_number = 0;
        while (std::getline(file, line)) {
            line_number++;
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }
        file.close();
        display_words(words);
    } else {
        std::cerr << "Could not open file" << std::endl;
    }
}


int challenge1() {
    std::string filename = "../words.txt";
    std::map<std::string, int> words;


    std::cout << "Word         Count" << std::endl;
    std::cout << "====================================" << std::endl;

    std::ifstream infile {filename};
    if (!infile) {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    std::string word {};

    while (infile >> word) {
        const std::string chars_to_trim = "\",.;:!?()[]{}";

        size_t start = word.find_first_not_of(chars_to_trim);
        size_t end = word.find_last_not_of(chars_to_trim);

        if (start != std::string::npos) {
            std::string cleaned = word.substr(start, end - start + 1);
            words[cleaned]++;
        }
    }

    display(words, 10);

    infile.close();

    return 0;

}


int challenge2() {
    std::string filename = "../words.txt";
    std::map<std::string, std::set<int>> words;


    std::cout << "Word         Occurrences" << std::endl;
    std::cout << "====================================" << std::endl;

    std::ifstream infile {filename};
    if (!infile) {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    std::string word {};

    int word_count {0};
    while (infile >> word) {
        word_count++;
        const std::string chars_to_trim = "\",.;:!?()[]{}";

        size_t start = word.find_first_not_of(chars_to_trim);
        size_t end = word.find_last_not_of(chars_to_trim);

        if (start != std::string::npos) {
            std::string cleaned = word.substr(start, end - start + 1);
            words[cleaned].insert(word_count);
        }
    }

    display(words, 10);

    infile.close();

    return 0;

}

int main() {
    //challenge1();
    //challenge2();
    part1();
    part2();
    return 0;
}