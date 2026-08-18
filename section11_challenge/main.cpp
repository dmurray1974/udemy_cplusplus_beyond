#include <iostream>
#include <vector>

using namespace std;

// Prototypes
void print_collection(const vector<int>& vec);
void display_mean(const vector<int>& vec);
void display_smallest(const vector<int>& vec);
void display_largest(const vector<int>& vec);
void add_numbers(vector<int>& numbers);
void display_menu(void);
char get_selection(void);
void handle_quit(void);
void handle_default(void);

void handle_find(const vector<int>&);
bool find(const vector<int>&, int);

// Main Function
int main() {

    vector<int> vec {};
    char menu_option {};

    do {
        display_menu();
        menu_option = get_selection();

        switch (menu_option) {
            case 'P':
                print_collection(vec);
                break;
            case 'A':
                add_numbers(vec);
                break;
            case 'M':
                display_mean(vec);
                break;
            case 'S':
                display_smallest(vec);
                break;
            case 'L':
                display_largest(vec);
                break;
            case 'F':
                handle_find(vec);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_default();
        }
    } while (menu_option != 'Q');

    return 0;
}




void print_collection(const vector<int> &vec) {
    cout << "[ ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void display_mean(const vector<int> &vec) {
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

void display_smallest(const vector<int> &vec) {
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

void display_largest(const vector<int> &vec) {
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

void add_numbers(vector<int>& numbers) {
    int n {0};

    cout << "Please enter Integer to add to collection" << endl;
    while (!(std::cin >> n)) {
        std::cout << "That's not a valid number. Try again: ";
        std::cin.clear(); // reset the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
    }

    numbers.push_back(n);
    cout << "[ " << n << " ] has been added to list" << endl;

}

void display_menu() {

    char menu_option {};
    cout << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add number" << endl;
    cout << "M - Display Mean of the numbers" << endl;
    cout << "S - Display Smallest number" << endl;
    cout << "L - Display Largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - QUIT" << endl << endl;
    cout << endl;
    cout << "Choose option : " << endl;

}

char get_selection() {
    char menu_option {};
    cin >> menu_option;

    return toupper(menu_option);
}


void handle_quit() {
    cout << "Good Bye!" << endl;
}

void handle_default() {
    cout << endl << "Unknown option, Try again" << endl;
}



void handle_find(const vector<int>& numbers) {
    int target {};
    cout << "Enter Integer you wish to find in vector: " << endl;
    cin >> target;
    if (find(numbers, target)) {
        cout << "Integer " << target << " found in vector." << endl;
    } else {
        cout << "Integer " << target << " not found in vector." << endl;
    }

}


bool find(const vector<int>& numbers, int target) {
    for (auto i : numbers) {
        if (i == target) {
            return true;
        }
    }
    return false;
}