#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string print_guest_list(const string [], size_t);
void clear_guest_list(string [], size_t);

void event_guest_list() {

    string guest_list[] {"Larry", "Moe", "Curly"};
    size_t guest_size_list {3};

    print_guest_list(guest_list, guest_size_list);
    clear_guest_list(guest_list, guest_size_list);
    print_guest_list(guest_list, guest_size_list);

}

string print_guest_list(const string guests [], size_t guest_size) {
    cout << endl << "Printing Guest List" << endl;
    for (size_t i = 0; i < guest_size; i++) {
        cout << guests[i] << endl;
    }
    cout << endl << "PLOP [" << typeid(guests).name() << "]" << endl;
    return typeid(guests).name();
}

void clear_guest_list(string guests [], size_t guest_size) {
    cout << endl << "Clearing Guest List" << endl;
    for (size_t i = 0; i < guest_size; i++) {
        guests[i] = " ";
    }
}

int main() {
    event_guest_list();
    return 0;
}