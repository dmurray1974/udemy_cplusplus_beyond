#include <iostream>
#include <vector>

using namespace std;

void print_collection(vector<int> vec) {
    cout << "[ ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void display_mean(vector<int> vec) {
    if (vec.size() > 0) {
        double sum = 0.0;
        for (auto i : vec) {
            sum += i;
        }
        cout << "Mean value : " << sum / vec.size() << endl;
    } else {
        cout << "Empty vector" << endl;
    }
}

void display_smallest(vector<int> vec) {
    if (vec.size() > 0) {
        int smallest {vec.at(0)};
        for (auto i : vec) {
            if (i < smallest) {
                smallest = i;
            }
        }
        cout << "Smallest value : " << smallest << endl;
    } else {
        cout << "The vector is empty" << endl;
    }
}

void display_largest(vector<int> vec) {
    if (vec.size() > 0) {
        int largest {vec.at(0)};
        for (auto i : vec) {
            if (i > largest) {
                largest = i;
            }
        }
        cout << "Largest value : " << largest << endl;
    } else {
        cout << "The vector is empty" << endl;
    }
}

vector<int> add_numbers(vector<int>& numbers) {
    int n {0};

    cout << "Please enter Integer to add to collection" << endl;
    while (!(std::cin >> n)) {
        std::cout << "That's not a valid number. Try again: ";
        std::cin.clear(); // reset the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
    }

    numbers.push_back(n);


    return numbers;
}

int main() {

    vector<int> vec {};
    char menu_option {};
    do {
        cout << endl << "P - Print numbers" << endl;
        cout << "A - Add number" << endl;
        cout << "M - Display Mean of the numbers" << endl;
        cout << "S - Display Smallest number" << endl;
        cout << "L - Display Largest number" << endl;
        cout << "Q - QUIT" << endl << endl;

        cin >> menu_option;

        switch (menu_option) {
            case 'P':
            case 'p':
                cout << endl << menu_option << " - Print numbers" << endl;
                print_collection(vec);
                break;
            case 'A':
            case 'a':
                cout << endl << menu_option << " - Add numbers" << endl;
                vec = add_numbers(vec);
                break;
            case 'M':
            case 'm':
                cout << endl << menu_option << " - Display Mean Value" << endl;
                display_mean(vec);
                break;
            case 'S':
            case 's':
                cout << endl << menu_option << " - Display Smallest Number" << endl;
                display_smallest(vec);
                break;
            case 'L':
            case 'l':
                cout << endl <<  menu_option << "- Display Largest Number" << endl;
                display_largest(vec);
                break;
            case 'Q':
            case 'q':
                cout << endl << menu_option << " - quit" << endl;
                break;
            default:
                cout << endl << menu_option << " - Unknown option, Try again" << endl;
        }
    } while (menu_option != 'q' && menu_option != 'Q');

    return 0;
}