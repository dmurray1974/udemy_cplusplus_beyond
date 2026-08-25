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
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdrawal_percent = 0.2;

protected:
    int num_withdrawals {0};
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposits of £5000.oo or more will receive £50.00 binus
    bool deposit(double amount);

    // Only allowed MAX od 3 withdrawals, each can be upto a max of 20% of account balance
    bool withdraw(double amount);
};

#endif //REDEFINEBASECLASS_TRUST_ACCOUNT_H

