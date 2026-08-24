#include <iostream>

#include "Account.h"
#include "SavingsAccount.h"
#include "Savings_Account.h"


int main() {
    //Account Class
    std::cout << std::endl << "========Account=========" << std::endl;
    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    std::cout << "Name: " << acc.name << std::endl;


    std::cout << std::endl;

    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    std::cout << "Name: " << p_acc->name << std::endl;


    delete p_acc;

    //Savings Account Class
    std::cout << std::endl << "========SavingsAccount=========" << std::endl;
    SavingsAccount sav_acc {};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);
    std::cout << "Name: " << sav_acc.name << std::endl;

    std::cout << std::endl;

    SavingsAccount *p_sav_acc {nullptr};
    p_sav_acc = new SavingsAccount();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    std::cout << "Name: " << p_sav_acc->name << std::endl;


    delete p_sav_acc;

    //Savings_Account Class
    std::cout << std::endl << "========Savings_Account=========" << std::endl;
    Savings_Account sav_acc2 {};
    sav_acc2.deposit(3000.0);
    sav_acc2.withdraw(800.0);
    std::cout << "Name: " << sav_acc2.name << std::endl;

    std::cout << std::endl;

    Savings_Account *p_sav_acc2 {nullptr};
    p_sav_acc2 = new Savings_Account();
    p_sav_acc2->deposit(4000.0);
    p_sav_acc2->withdraw(1500.0);
    std::cout << "Name: " << p_sav_acc2->name << std::endl;

    delete p_sav_acc2;

    return 0;
}