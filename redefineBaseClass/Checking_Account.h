//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_CHECKING_ACCOUNT_H
#define REDEFINEBASECLASS_CHECKING_ACCOUNT_H

//
// Created by Darren Murray on 24/08/2026.
//

#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking_Account";
    static constexpr double def_balance = 0.0;
protected:
    const double trans_fee {1.50};
public:
    //   Savings_Account();
    //   Savings_Account(double balance, double int_rate);
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    // Withdraw is Inherited
};

#endif //REDEFINEBASECLASS_CHECKING_ACCOUNT_H