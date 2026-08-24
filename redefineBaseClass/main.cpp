#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

int main() {

    std::cout.precision(2);
    std::cout << std::fixed;

    // Accounts
    std::vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts,1000);
    withdraw(accounts,500);

    // Savings Accounts
    std::vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts,1000);
    withdraw(sav_accounts,2000);

    // Checking Accounts
    std::cout << "** Checking Account" << std::endl;
    std::vector<Checking_Account> chk_accounts;
    chk_accounts.push_back(Checking_Account{});
    chk_accounts.push_back(Checking_Account{"IronMan"});
    chk_accounts.push_back(Checking_Account{"Thor", 2000});
    chk_accounts.push_back(Checking_Account{"Hulk", 5000});

    display(chk_accounts);
    deposit(chk_accounts,1000);
    withdraw(chk_accounts,2000);

    withdraw(chk_accounts,20);
    withdraw(chk_accounts,20);
    withdraw(chk_accounts,20);

    // Trust Accounts
    std::cout << "** Trust Account" << std::endl;
    std::vector<Trust_Account> trust_accounts;
 //   trust_accounts.push_back(Trust_Account{});
 //   trust_accounts.push_back(Trust_Account{"IronMan"});
 //   trust_accounts.push_back(Trust_Account{"Thor", 2000});
    trust_accounts.push_back(Trust_Account{"Hulk", 5000});

    display(trust_accounts);
    deposit(trust_accounts,1000);
    withdraw(trust_accounts,2000);

    withdraw(trust_accounts,20);
    withdraw(trust_accounts,20);
    withdraw(trust_accounts,20);

/*

    std::cout << std::endl << "==========Account Class" << std::endl;
    Account a1 {1000.0};
    std::cout << a1 << std::endl;

    a1.deposit(500.0);
    std::cout << a1 << std::endl;

    a1.withdraw(1000.0);
    std::cout << a1 << std::endl;

    a1.withdraw(5000.0);
    std::cout << a1 << std::endl;

    std::cout << std::endl << "========== Savings Account Class" << std::endl;
    Savings_Account s1 {1000.0, 5.0};
    std::cout << s1 << std::endl;

    a1.deposit(500.0);
    std::cout << s1 << std::endl;

    a1.withdraw(1000.0);
    std::cout << s1 << std::endl;

    a1.withdraw(5000.0);
    std::cout << a1 << std::endl;
*/
    return 0;
}