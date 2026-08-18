#ifndef SEC13_ACCOUNT_ACCOUNT_H
#define SEC13_ACCOUNT_ACCOUNT_H

#include <string>

class Account {
    private:
        std::string name;
        double balance;
        static int num_accounts;
    public:
        Account(std::string name, double bal);  // Constructor
        explicit Account(std::string name);  // Constructor

        //Copy Constructor
        Account(const Account& other);
        void set_balance(double bal);
        double get_balance();

        static int get_num_accounts();

        void set_name(std::string);
        std::string get_name();

        bool deposit(double);
        bool withdraw(double);

        ~Account();   // Destructor
};

#endif //SEC13_ACCOUNT_ACCOUNT_H