//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_ACCOUNT_UTIL_H
#define REDEFINEBASECLASS_ACCOUNT_UTIL_H

#include <vector>
#include "Account.h"

// Helper functions for Account Class
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif //REDEFINEBASECLASS_ACCOUNT_UTIL_H