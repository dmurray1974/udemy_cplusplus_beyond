//
// Created by Darren Murray on 22/08/2026.
//

#include <iostream>
#include "Account.h"

Account::Account()
    : balance {0}, name("AccountPL") {

}

Account::~Account() {

}

void Account::deposit(double amount) {
    std::cout << "Account::Deposit " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account::Withdraw " << amount << std::endl;
}

