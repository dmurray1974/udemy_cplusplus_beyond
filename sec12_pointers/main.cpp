#include <iostream>

using namespace std;

void loop_pointer() {
    int scores [] {100, 95, 89, 68, -1};
    int *scorePtr {scores};

    cout << endl;
    while (*scorePtr != -1) {
        cout << "** Loop_pointer: "<< *scorePtr << endl;
        ++scorePtr;
    }
    cout << endl;
}

void loop_pointer2() {
    int scores [] {101, 96, 90, 69, -1};
    int *scorePtr {scores};

    cout << endl;
    while (*scorePtr != -1) {
        cout << "** Loop_pointer2: "<< *scorePtr++ << endl;
    }
    cout << endl;
}

int main() {

    int score {100};
    int score2 {200};
    int *scorePtr {&score};

    loop_pointer();
    loop_pointer2();

    cout << "Init Ptr: " << *scorePtr << endl;

    *scorePtr = 121;

    cout << "New Ptr: " << *scorePtr << endl;
    cout << "New Ptr: " << scorePtr << endl;
    cout << "New Ptr: " << &scorePtr << endl;

    scorePtr = &score2;

    cout << "New Ptr: " << *scorePtr << endl;
    cout << "New Ptr: " << scorePtr << endl;
    cout << "New Ptr: " << &scorePtr << endl;


    cout << "Score Value: " << score << endl;


    string fname {"Donna"};
    string *filenamePtr {&fname};

    for (auto c: *filenamePtr) {
        cout << c << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}