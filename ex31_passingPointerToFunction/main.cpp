#include <iostream>

void multiply_with_pointer(int *ptr, int multiplier);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int *valuePtr {nullptr};
    int multiplier {13};
    int value {1012};
    valuePtr = &value;

    multiply_with_pointer(valuePtr, multiplier);
    std::cout << *valuePtr << std::endl;


    return 0;
}


void multiply_with_pointer(int *ptr, int multiplier) {
    *ptr *= multiplier;

}
