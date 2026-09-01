#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

/*
 *Example Palindromes
 * A toyotas a toyota
   A santa at NASA
   A man, a plan, a cat, a ham, a yak, a yam, a canal panama
   a man a plan a cam
 */

// Course Solution
bool is_palindrome2(const std::string& s) {
    std::deque<char> d;

    for (char c : s) {
        if (std::isalpha(c)) {
            d.push_back(std::toupper(c));
        }
    }
    char c1{};
    char c2{};

    while (d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        d.pop_front();
        d.pop_back();
        if (c1 != c2) {
            return false;
        }
    }
    return true;
}


// My solution - asked AI and even though mine works it is not as efficient as the course solution above
bool is_palindrome(const std::string &word) {
    std::deque<char> deq_forward {};
    std::deque<char> deq_back {};
    for (auto c : word) {

        if (std::isalnum(c)) {
            deq_forward.push_back(std::tolower(c));
            deq_back.push_front(std::tolower(c));
        }
    }

    if (deq_forward == deq_back) {
        return true;
    }
    return false;
}


int main() {

    std::vector<std::string> words {};
    words.push_back("a Santa at NASA.");
    words.push_back("MADam");
    words.push_back("A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal panama");

    for (auto& word : words) {
        std::cout << std::boolalpha;
        std::cout << std::setw(10) << std::left << is_palindrome2(word) << " : " << word << std::endl;
    }
    return 0;
}