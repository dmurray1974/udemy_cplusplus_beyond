//
// Created by Darren Murray on 24/08/2026.
//

#include "Trust_Account.h"

//    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
        : Savings_Account(name, balance, int_rate), num_withdrawals {0} {
}


bool Trust_Account::deposit(double amount) {
        if ( amount > bonus_threshold) {
            amount += bonus_amount;
        }
        return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {

    if (num_withdrawals > max_withdrawals || amount > balance * max_withdrawal_percent ) {
        return false;
    }
    if (Savings_Account::withdraw(amount)) {
        num_withdrawals++;
        return true;
    }
    return false;
}


std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account Name : " << account.name << " ; balance: £" << account.balance << " : Interest Rate: " << account.int_rate << "%.] [" << account.num_withdrawals << "]";
    return os;
}
