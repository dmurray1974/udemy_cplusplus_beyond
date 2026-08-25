#include <iostream>

class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Account::Account withdrawn: " << amount << std::endl;
    }
    virtual ~Account() {
        std::cout << "Account::~Account Destructor" << std::endl;
    }
};

class Checking : public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Checking::Account withdrawn: " << amount << std::endl;
    }
    virtual ~Checking() {
        std::cout << "Checking::~Checking Destructor" << std::endl;
    }
};

class Savings : public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Savings::Account withdrawn: " << amount << std::endl;
    }
    virtual ~Savings() {
        std::cout << "Savings::~Savings Destructor" << std::endl;
    }
};

class Trust : public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Trust::Account withdrawn: " << amount << std::endl;
    }
    virtual ~Trust() {
        std::cout << "Trust::~Trust Destructor" << std::endl;
    }
};


int main() {
    std::cout << std::endl << "===============Pointers =============" << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(100);
    p2->withdraw(200);
    p3->withdraw(300);
    p4->withdraw(400);

    std::cout << std::endl << "===============Cleanup =============" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}