#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void cpp_strings2() {
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};

    size_t pos = journal_entry_1.find(' ');
    journal_entry_1.erase(0, pos+1);

    if (journal_entry_1 > journal_entry_2) {
        journal_entry_1.swap(journal_entry_2);
    }

    cout << journal_entry_1 << " " << journal_entry_2 << endl;

}


void cpp_strings() {
    string unformatted_full_name {"StephenHawking"};

    string first_name {unformatted_full_name, 0, 7};
    string last_name { unformatted_full_name, 7, unformatted_full_name.length() -1};

    cout << first_name << " " << last_name << endl;

    string formatted_full_name = unformatted_full_name;
    formatted_full_name.insert(7, " ");

    cout << "Formatted Full Name: " << formatted_full_name << endl;

}

void strings_and_functions() {

    char first_name[] {"Bjarne"};
    char last_name[] {"Stroustrup"};
    char whole_name[] {};

    size_t first_name_length = strlen(first_name);
    size_t last_name_length = strlen(last_name);

    cout << "FirstName Length: " << first_name_length << endl;
    cout << "LastName: " << last_name_length << endl;

    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "Whole Name Init: " << whole_name << endl;

    strcpy(whole_name, first_name);
    cout << "Whole Name [firstName]: " << whole_name << endl;
    strcat(whole_name, last_name);
    cout << "Whole Name [lastName]: " << whole_name << endl;

    size_t whole_name_length = strlen(whole_name);
    cout << "WholeName Length: " << whole_name_length << endl;

}

int main() {
    strings_and_functions();
    cout << endl << "=============================" << endl;
    cpp_strings();
    cout << endl << "=============================" << endl;
    cpp_strings2();
    return 0;
}