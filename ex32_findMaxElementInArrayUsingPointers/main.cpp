#include <iostream>
#include <string>
using namespace std;

int find_max_element(int* arr, int size);
void reverse_array(int* arr, int size);
string reverse_string(const string &str);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int array[] = { 1, 2, 3, 445, 5, 6, 7, 8, 9, 123 };
    int size {10};
    int max_element {0};

    max_element = find_max_element(array, size);
    std::cout << max_element << std::endl;

    int array2[] = {3,5,7,9,11, 234};
    int size2 { sizeof(array2) / sizeof(array2[0])};

    reverse_array(array2, size2);
    for (size_t i {0}; i < size2; i++) {
        std::cout << "CAT: " << *(array2+i) << std::endl;
    }

    string input {"Hello, World"};
    string reversed = reverse_string(input);

    cout << reversed << endl;


    return 0;
}

string reverse_string(const std::string &str) {
    std::string reversed;

    const char* start = str.c_str();
    const char* end = str.c_str() + str.size() -1;

    while (end >= start) {
        reversed.push_back(*end);
        end--;
    }

    return reversed;

}


void reverse_array(int* arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}



int find_max_element(int* arr, int size) {
    int max = *arr;
    for (int i =1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}