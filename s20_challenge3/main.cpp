#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include <limits>


template <typename T>
concept Iterable = requires(T t) { t.begin(); t.end(); };

template <typename T1, typename T2>
void display(const std::map<T1, T2>& m,
             size_t limit = std::numeric_limits<size_t>::max()) {
    std::cout << "[";
    size_t count = 0;
    for (const auto& elem : m) {
        if (count >= limit) break;

        std::cout << elem.first << ":";
        if constexpr (Iterable<T2>) {
            std::cout << "[";
            for (const auto& set_elem : elem.second) {
                std::cout << set_elem << " ";
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << elem.second;
        }
        std::cout << std::endl;
        ++count;
    }
    std::cout << "]" << std::endl;
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
    challenge1();
    challenge2();
    return 0;
}