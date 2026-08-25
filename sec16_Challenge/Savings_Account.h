//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_SAVINGS_ACCOUNT_H
#define REDEFINEBASECLASS_SAVINGS_ACCOUNT_H

#include "Account.h"

class Savings_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Savings_Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
 //   Savings_Account();
 //   Savings_Account(double balance, double int_rate);
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Savings_Account() = default;
};


#endif //REDEFINEBASECLASS_SAVINGS_ACCOUNT_H