//
// Created by Darren Murray on 24/08/2026.
//

//
// Created by Darren Murray on 24/08/2026.
//

#include "Checking_Account.h"



Checking_Account::Checking_Account(std::string name, double balance)
    : Account(name, balance) {
}

bool Checking_Account::withdraw(double amount) {
    amount += trans_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "Checking Account Name: " << account.name << " : balance: £" << account.balance;
    return os;
}