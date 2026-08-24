//
// Created by Darren Murray on 24/08/2026.
//

#include "Savings_Account.h"

/*
Savings_Account::Savings_Account(double balance, double int_rate)
    : Account(balance), int_rate(int_rate){

}

Savings_Account::Savings_Account()
    : Savings_Account {0.0, 0.0} {

}
*/

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account(name, balance), int_rate(int_rate) {

}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings Account Name : " << account.name << " ; balance: £" << account.balance << " : Interest Rate: " << account.int_rate << "%.]";
    return os;
}
