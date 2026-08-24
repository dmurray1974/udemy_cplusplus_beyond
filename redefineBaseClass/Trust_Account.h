//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_TRUST_ACCOUNT_H
#define REDEFINEBASECLASS_TRUST_ACCOUNT_H
#include "Savings_Account.h"
#include "Account.h"

class Trust_Account : public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust_Account";
    static constexpr double def_balance = 0.0;
    int withdrawal_count {0};
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = 0.0) ;
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif //REDEFINEBASECLASS_TRUST_ACCOUNT_H

