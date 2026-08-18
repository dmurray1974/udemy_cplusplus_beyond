#include <iostream>
#include <vector>

using namespace std;

int calculate_pairs(vector<int> vec) {

    int result {0};

    if (vec.size() > 0) {
        for (int i {0}; i < vec.size()-1; i++) {
            for (int j {i + 1}; j < vec.size(); j++) {
                result += vec.at(i) * vec.at(j);
            }
        }
    }
    return result;
}

int main() {
    vector<int> vec {};
    // vector<int> vec { 1, 2, 3};
    //vector<int> vec { 2, 4, 6, 8};

    int result {0};
    result = calculate_pairs(vec);

    cout << "Result: " << result << endl;
    return 0;
}