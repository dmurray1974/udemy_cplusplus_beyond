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
private:
    static constexpr const char *def_name = "Unnamed Checking_Account";
    static constexpr double def_balance = 0.0;
protected:
    const double trans_fee {1.50};
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(std::ostream& os) const override;

    virtual ~Checking_Account() = default;
};

#endif //REDEFINEBASECLASS_CHECKING_ACCOUNT_H