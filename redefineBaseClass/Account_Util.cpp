//
// Created by Darren Murray on 24/08/2026.
//

#include <iostream>
#include "Account_Util.h"

// Account
void display(const std::vector<Account> &accounts) {
    std::cout << std::endl << "==========Accounts ============" << std::endl;
    for (const auto &account : accounts) {
        std::cout << account << std::endl;
    }
}


void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << std::endl << "==========Deposits Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited: " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of: " << amount << " to " << account << std::endl;
        }
    }
}


void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << std::endl << "==========Withdrawal Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew: " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of: " << amount << " from " << account << std::endl;
        }
    }

}

// Savings Account
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << std::endl << "==========Savings Accounts ============" << std::endl;
    for (const auto &account : accounts) {
        std::cout << account << std::endl;
    }
}


void deposit(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Deposits Savings Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited: " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of: " << amount << " to " << account << std::endl;
        }
    }
}


void withdraw(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Withdrawal Savings Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew: " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of: " << amount << " from " << account << std::endl;
        }
    }
}

// Checking Account
void display(const std::vector<Checking_Account> &accounts) {
    std::cout << std::endl << "==========Checking Accounts ============" << std::endl;
    for (const auto &account : accounts) {
        std::cout << account << std::endl;
    }
}


void deposit(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Deposits Checking Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited: " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of: " << amount << " to " << account << std::endl;
        }
    }
}


void withdraw(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Withdrawal Checking Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew: " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of: " << amount << " from " << account << std::endl;
        }
    }
}

//Trust Account
void display(const std::vector<Trust_Account> &accounts) {
    std::cout << std::endl << "==========Trust Accounts ============" << std::endl;
    for (const auto &account : accounts) {
        std::cout << account << std::endl;
    }
}


void deposit(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Deposits Trust Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited: " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of: " << amount << " to " << account << std::endl;
        }
    }
}


void withdraw(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << std::endl << "==========Withdrawal Trust Accounts ============" << std::endl;
    for (auto &account : accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew: " << amount << " from " << account  << std::endl;
        } else {
            std::cout << "Failed Withdrawal of: " << amount << " from " << account << std::endl;
        }
    }
}
