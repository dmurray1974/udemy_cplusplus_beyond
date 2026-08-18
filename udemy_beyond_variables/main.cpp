#include <iostream>

using namespace std;

int main() {

    int age {9};  //c++11 style initialisation
    cout << age << endl;

    int roomWidth {0};  // Good practice to initialise variable
    int roomLength {0};  // Good practice to initialise variable

    cout << "Enter the width of the room [feet]: ";
    cin >> roomWidth;

    cout << "Enter the length of the room [feet]: ";
    cin >> roomLength;

    cout << "The area of the room is " << roomWidth * roomLength << " square feet" << endl;

    return 0;
}