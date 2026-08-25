//
// Created by Darren Murray on 24/08/2026.
//

#include "Trust_Account.h"

//    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
        : Savings_Account(name, balance, int_rate) {
}


bool Trust_Account::deposit(double amount) {
        if ( amount > 5000.00) {
            amount += 50.00;
        }
        return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {

    if (withdrawal_count >= 3 ) {
        std::cout << "Too many attempts to withdraw" << std::endl;
        return false;
    }
    if (amount > this->balance/5 ) {
        std::cout << "You cannot withdraw more than 20% of total account balance" << std::endl;
        return false;
    }
    if (Savings_Account::withdraw(amount)) {
        withdrawal_count++;
        return true;
    }
    return false;
}


std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account Name : " << account.name << " ; balance: £" << account.balance << " : Interest Rate: " << account.int_rate << "%.] [" << account.withdrawal_count << "]";
    return os;
}
