//
// Created by Darren Murray on 24/08/2026.
//

#ifndef REDEFINEBASECLASS_ACCOUNT_H
#define REDEFINEBASECLASS_ACCOUNT_H

#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr char def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    //Account();
    //Account(double balance);
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif //REDEFINEBASECLASS_ACCOUNT_H