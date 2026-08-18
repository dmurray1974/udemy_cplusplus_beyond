#include <iostream>
using namespace std;

void swapPointers(int*, int* );
void doubleData( int*);
void display(const vector<string> *const v);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a {10};
    int b {20};
    int d {30};
    int *c {&d};

    swapPointers(&a, &b);

    doubleData(c);
    cout << "Double Data: " << *c << endl;

    vector<string> stooges {"larry", "Moe", "Curly"};
    display(&stooges);

    return 0;
}


void display(const vector<string> *const v) {
    for (auto i : *v) {
        cout << i << " : ";
    }
    cout << endl;

 //   (*v).at(0) = "Funny";   // Update value at index 0
 //   v = nullptr;        // Changes Address of ptr to Nullptr
}


void doubleData(int *intPtr) {
    *intPtr *= 2;
}



void swapPointers(int *ptr1, int *ptr2 ) {
    cout << *ptr1 << " " << *ptr2 << endl;
    cout << ptr1 << " " << ptr2 << endl;

    // Without using Temporary
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;

    cout << endl;
    cout << *ptr1 << " " << *ptr2 << endl;
    cout << ptr1 << " " << ptr2 << endl;

}
