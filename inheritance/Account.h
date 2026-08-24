//
// Created by Darren Murray on 22/08/2026.
//

#ifndef INHERITANCE_ACCOUNT_H
#define INHERITANCE_ACCOUNT_H

#include <string>

class Account {
    public:
        double balance;
        std::string name;
        void deposit(double amount);
        void withdraw(double amount);
        Account();
        ~Account();
};

#endif //INHERITANCE_ACCOUNT_H