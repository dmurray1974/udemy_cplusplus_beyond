#include <iostream>
using namespace std;

//ProtoTypes
int find_area(int);
double find_area(double, double);


void area_calc() {
    int square_area {};
    double rectangle_area {};

    square_area = find_area(2);
    rectangle_area = find_area(4.5, 2.3);
    cout << "The area of the square is " << square_area << endl;
    cout << "The area of the rectangle is " << rectangle_area << endl;

}

int main() {

    area_calc();
    return 0;
}


int find_area(int length) {
    return length * length;
}


double find_area(double length, double width) {
    return length * width;
}
