#include <iostream>
#include <string>
#include "Account.h"

void display_accounts(Account a) {
    std::cout << "Name: " << a.get_name() << std::endl;
    std::cout << "Balance: " << a.get_balance() << std::endl;
}

int main() {

    std::cout << "Number of Account: " <<   Account::get_num_accounts() <<   std::endl;
    std::cout << "Running Account" << std::endl;
    Account account1("Joe", 123.45);

    std::cout << "Running Account" << std::endl;
    Account account3("Joe3");

    std::cout << "Initial Balance: £" << account1.get_balance() << std::endl;

    if (account1.withdraw(100)) {
        std::cout << "-- Withdrawal Success!" << std::endl;
    } else {
        std::cout << "-- Withdrawal Fail! - Insufficient Funds!!" << std::endl;
    }

    if (account1.deposit(1000)) {
        std::cout << "++ Deposit Success!" << std::endl;
    } else {
        std::cout << "++ Deposit Fail!" << std::endl;
    }

    std::cout << "Balance: £" << account1.get_balance() << std::endl;

    std::cout << "Number of Account: " <<   Account::get_num_accounts() <<   std::endl;


    if (account1.withdraw(10000)) {
        std::cout << "-- Withdrawal Success!" << std::endl;
    } else {
        std::cout << "-- Withdrawal Fail! - Insufficient Funds!!" << std::endl;
    }

    if (account1.deposit(1000)) {
        std::cout << "++ Deposit Success!" << std::endl;
    } else {
        std::cout << "++ Deposit Fail!" << std::endl;
    }

    std::cout << "Balance: £" << account1.get_balance() << std::endl;

    // Example using Pointers
    auto *account2 = new Account("Giggly Jigs", 345.56);

    account2->deposit(100.0);
    std::cout << "Balance of account [£" << account2->get_balance() << "]" << std::endl;

    delete account2;

    display_accounts(account1);

    return 0;
}