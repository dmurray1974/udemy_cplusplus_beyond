//
// Created by Darren Murray on 22/08/2026.
//
#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {

}

SavingsAccount::~SavingsAccount() {

}

void SavingsAccount::deposit(double amount) {
    std::cout << "SavingsAccount::Deposit " << amount << std::endl;
}

void SavingsAccount::withdraw(double amount) {
    std::cout << "SavingsAccount::Withdraw " << amount << std::endl;
}