//
// Created by Darren Murray on 22/08/2026.
//
#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account()
    : int_rate {3.0} {

}

Savings_Account::~Savings_Account() {

}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings_Account::Deposit " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings_Account::Withdraw " << amount << std::endl;
}