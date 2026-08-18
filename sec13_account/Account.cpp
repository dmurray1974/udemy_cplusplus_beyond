#include "Account.h"

#include <iostream>
#include <ostream>

int Account::num_accounts = 0;

Account::Account(std::string p_name, double p_bal)
    : name {p_name},
      balance {p_bal}
{
    std::cout << "--> Constructor of Object: " << name << std::endl;
    ++num_accounts;
//    this->set_name(name);
//    this->set_balance(bal);
}

Account::Account(std::string p_name)
    : Account {p_name, 0.0}
{
    std::cout << "--> Constructor of Object: " << name << std::endl;
    //    this->set_name(name);
    //    this->set_balance(bal);
}

//Copy Constructor
Account::Account(const Account& other)
//    : name(other.name), balance(other.balance)
    : Account { other.name, other.balance}
{
    std::cout << "Copy Constructor - Made copy of : " << other.name << std::endl;
}

void Account::set_balance(double bal) {
    this->balance = bal;
}

double Account::get_balance() {
    return this->balance;
}

void Account::set_name(std::string n) {
    this->name = n;
}

std::string Account::get_name() {
    return this->name;
}
bool Account::deposit(double amount) {
    this->balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= this->balance) {
        this->balance -= amount;
        return true;
    }
    return false;
}

int Account::get_num_accounts() {
    return num_accounts;
}

// Destructor
Account::~Account() {
    std::cout << "--> ~Destructor for object: " << this->name << std::endl;
    --num_accounts;
}
