#include <iostream>
#include <vector>

using namespace std;

int count_numbers(const vector<int> &vec) {
    int count {0};
    size_t index {0};

    while (vec.at(index) != -99 && index < vec.size()) {
        index++;
        count++;
    }

    return count;
}

int main() {
    vector<int> vec {1,45,24,87,88,-99,34,6756,5443};
    int result {0};

    result = count_numbers(vec);
    cout << "Result: " << result << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}