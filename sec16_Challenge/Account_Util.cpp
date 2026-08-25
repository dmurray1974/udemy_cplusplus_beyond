//
// Created by Darren Murray on 24/08/2026.
//

#include <iostream>
#include "Account_Util.h"

// Account
void display(const std::vector<Account *> &accounts) {
    std::cout << std::endl << "==========Accounts ============" << std::endl;
    for (const auto account : accounts) {
        std::cout << *account << std::endl;
    }
}


void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << std::endl << "==========Deposits Accounts ============" << std::endl;
    for (auto account : accounts) {
        if (account->deposit(amount)) {
            std::cout << "Deposited: " << amount << " to " << *account << std::endl;
        } else {
            std::cout << "Failed Deposit of: " << amount << " to " << *account << std::endl;
        }
    }
}


void withdraw(std::vector<Account *> &accounts, double amount) {
    std::cout << std::endl << "==========Withdrawal Accounts ============" << std::endl;
    for (auto account : accounts) {
        if (account->withdraw(amount)) {
            std::cout << "Withdrew: " << amount << " from " << *account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of: " << amount << " from " << *account << std::endl;
        }
    }

}
