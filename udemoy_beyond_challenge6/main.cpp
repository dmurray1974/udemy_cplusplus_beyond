#include <iostream>

using namespace std;

int main() {

    int numberOfSmallRooms {0};
    int numberOfLargeRooms {0};
    const double tax {0.06};
    const double pricePerSmallRoom {25.0};
    const double pricePerLargeRoom {35.0};
    const int estimatedays {30};

    cout << "How many SMALL rooms would you like cleaned: ";
    cin >> numberOfSmallRooms;

    cout << "How many LARGE rooms would you like cleaned: ";
    cin >> numberOfLargeRooms;

    cout << endl;

    cout << "Estimate for carpet cleaning service:";
    cout << "Number of SMALL rooms: " << numberOfSmallRooms << endl;
    cout << "Number of LARGE rooms: " << numberOfLargeRooms << endl;
    cout << "Price per SMALL room: £" << pricePerSmallRoom << endl;
    cout << "Price per LARGE room: £" << pricePerLargeRoom << endl;

    double smallCost = numberOfSmallRooms * pricePerSmallRoom;
    double largeCost = numberOfLargeRooms * pricePerLargeRoom;
    double totalCost = smallCost + largeCost;
    double taxCost = totalCost * tax;
    double totalCostPlusTax = totalCost + taxCost;

    cout << "Cost : £" << totalCost << endl;
    cout << "Tax: £" << taxCost << endl;
    cout << "============================" << endl;
    cout << "Total estimate: £" << totalCostPlusTax  << endl;
    cout << "This estimate is valid for " << estimatedays << " days" << endl;


    return 0;
}