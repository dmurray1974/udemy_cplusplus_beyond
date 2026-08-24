//
// Created by Darren Murray on 24/08/2026.
//

#include "Account.h"
/*
Account::Account()
    : Account {0.0} {
}

Account::Account(double balance)
    : balance(balance) {
}
*/
Account::Account(std::string name, double balance)
    : name(name), balance(balance) {

}


bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
        //        std::cout << "Insufficient Funds: You can't withdraw £" << amount << " You only have balance of £" << balance << std::endl;
}

double Account::getBalance() const {
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "Account Name: " << account.name << " : balance: £" << account.balance;
    return os;
}
