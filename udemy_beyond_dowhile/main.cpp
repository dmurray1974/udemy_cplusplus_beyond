#include <iostream>
#include <vector>
#include <spdlog/spdlog.h>

using namespace std;

void find_first_vowel(const std::vector<char>& vec) {

    int index {0};
    int found {false};

    do {
        if (vec.size() > 0) {
            char letter {vec.at(index++)};
            if ( letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ) {
                cout << "Vowel found: " << letter << endl;
                spdlog::info("Hello {}", "Plopq");
                found = true;
            }
        }
    } while (index < vec.size() && !found);


    if (index >= vec.size() && !found) {
        cout << "No vowel was found" << endl;
    }

}

int main() {
//    vector<char> vec {'H', 'e', 'l', 'l', 'o', 'p', 'd'};
//    vector<char> vec2 {'H', 'E', 'l', 'l', 'O', 'p', 'd'};
    //vector<char> vec2 {'F', 'r', 'a', 'n', 'k'};
    vector<char> vec2 {'H', 'e', 'l', 'l', 'o'};
    //vector<char> vec2 {};




    find_first_vowel(vec2);
    return 0;
}