//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_ACCOUNT_UTIL_H
#define REDEFINEBASECLASS_ACCOUNT_UTIL_H

#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

// Helper functions for Account Class
void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);



// Helper functions for SavingsAccount Class
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);


// Helper functions for CheckingAccount Class
void display(const std::vector<Checking_Account> &accounts);
void deposit(std::vector<Checking_Account> &accounts, double amount);
void withdraw(std::vector<Checking_Account> &accounts, double amount);

// Helper functions for TrustAccount Class
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &accounts, double amount);
void withdraw(std::vector<Trust_Account> &accounts, double amount);

#endif //REDEFINEBASECLASS_ACCOUNT_UTIL_H