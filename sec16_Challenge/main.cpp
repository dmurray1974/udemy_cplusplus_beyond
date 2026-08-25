#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

int main() {
/*
 *  Checking_Account c;
    std::cout << c << std::endl;

    Savings_Account s {"Frank", 5000, 2.63};
    std::cout << s << std::endl;
    s.deposit(10000);
    std::cout << s << std::endl;
    s.withdraw(10000);
    std::cout << s << std::endl; */

    Account *ptr = new Trust_Account("Leo", 10000, 2.64);
    std::cout << *ptr << std::endl;

    return 0;
}