#include <iostream>

using namespace std;

//Prototypes
void print(const int *const, size_t);
int* apply_all(const int *const, size_t, const int *const, size_t);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1 [] {1, 2, 3, 4, 5};
    int array2 [] {10, 20, 30};

    int *results;

    cout << "Array1: ";
    print(array1,array1_size);

    cout << "Array2: ";
    print(array2,array2_size);

    results = apply_all(array1,array1_size,array2,array2_size);
    constexpr size_t results_size {array1_size*array2_size};

    cout << "Results: ";
    print(results,results_size);

    delete [] results;
    cout << endl;

    return 0;
}

void print(const int *const array, size_t size) {
    cout << "[ ";
    for (int i {0}; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << "]" << endl;
}

int*  apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2) {
    int *newarray {nullptr};
    newarray = new int[size1 * size2];

    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < size1; j++) {
            newarray[i * size1 + j] = *(array1+j) * *(array2+i);
        }
    }
    return newarray;
}