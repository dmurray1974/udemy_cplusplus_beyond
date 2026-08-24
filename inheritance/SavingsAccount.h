//
// Created by Darren Murray on 22/08/2026.
//

#ifndef INHERITANCE_SAVINGSACCOUNT_H
#define INHERITANCE_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount: public Account {
    public:
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //INHERITANCE_SAVINGSACCOUNT_H