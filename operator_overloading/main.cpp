#include <iostream>
#include "Mystring.h"
#include "Money.h"

int main() {


    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    std::cout << "Enter the 3rd stooges first name: ";
    std::cin >> curly;

    std::cout << "The 3 Stooges are: " << larry << " " << moe << " " << curly << std::endl;
    return 9;

    Money money(100.00);
    Money money2 {12, 13};
    if (money == money2) {
        std::cout << "money == money2" << std::endl;
    } else {
        std::cout << "money != money2" << std::endl;
    }
    Mystring larry1 {"LARRY"};
    Mystring larry2;
    larry2 = -larry1;

    std::cout << "========================================" << std::endl;
    larry1.display();
    larry2.display();
    std::cout << "========================================" << std::endl;

    Mystring result;
    result = larry1 + " " + larry2;
    result.display();

    std::cout << "** Running [ Mystring a {'Hello'} ]" << std::endl;
    Mystring a {"Hello"};   //Overloaded Constructor

    std::cout << std::endl << "** Running [ Mystring b ]" << std::endl;
    Mystring b;                 //No-Args constructor

    std::cout << std::endl << "** Running [ b = a ]" << std::endl;
    b = a;                      // Copy Assignment
                                // b.operator=(a)
    std::cout << std::endl << "** Running [ b = a ]" << std::endl;
    b = "This is a test";    // b.operator=("This is a test");


/*

    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge {larry};

    empty.display();
    larry.display();
    stooge.display();
*/


    return 0;
}