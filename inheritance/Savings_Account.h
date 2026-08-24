//
// Created by Darren Murray on 22/08/2026.
//

#ifndef INHERITANCE_SAVINGS_ACCOUNT_H
#define INHERITANCE_SAVINGS_ACCOUNT_H

#include "Account.h"

class Savings_Account: public Account {
public:
    double int_rate;

    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};

#endif //INHERITANCE_SAVINGS_ACCOUNT_H