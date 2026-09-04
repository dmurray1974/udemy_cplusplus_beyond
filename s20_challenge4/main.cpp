#include <iostream>
#include <cctype>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>

// Use a Stack and a Queue to detect Palindromes
// Remove all spaces and special characters and case

// " a man a plan a cat a ham a yak a yam a hat a canal panama "

template <typename T>
void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T item = s.top();
        s.pop();
        std::cout << item << " ";
    }
    std::cout << "]" << std::endl;
}

bool is_palindrome(const std::string& s) {
    std::queue<char> q;
    std::stack<char> stk;

    // Add all of the string chars that are alpha to the back of queue
    // Push all of the string that are alpha to the stack
    for (char c : s) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
            q.push(c);
            stk.push(c);
        }
    }

    char a {};
    char b {};

    while (!q.empty()) {
        a = q.front();
        b = stk.top();
        if (a != b) {
            return false;
        }
        q.pop();
        stk.pop();
    }
  //  display(stk);


    return true;
}

int main() {

    std::vector<std::string> test_strings {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar",
    "bob", "ana", "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
    "a man a plan a cat a ham a yak a yam a hat a canal-panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& test : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(test) << "  " << test << std::endl;
    }
    std::cout << std::endl;

    return 0;
}