#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
    // Attribues
    string name {"Player"};
    int health {0};
    int xp {3};    // Experience

public:
    // Methods
    void talk(string testToSay) { cout << name << " says " << testToSay << endl; };
    bool isDead();

};

class Account {
public:
    //Attribues
    string name {"Account"};
    double balance {0.0};

    // Method
    bool deposit(double bal) {
        balance += bal;
        cout << "Deposited" << endl;
    };
    bool withdraw(double bal) {
        balance -= bal;
        cout << "Withdrawn" << endl;
    };
};

int main() {

    Account account1;
    account1.name = "Account1";
    account1.balance = 15000;
    account1.deposit(1500);
    account1.withdraw(500);
    cout << "Balance : £" << account1.balance << endl;

    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi There!");

    Player *enemy = new Player;
    enemy->name = "Enemy";
    enemy->health = 100;
    enemy->xp = 12;
    enemy->talk("I will destroy you!");

    return 0;
}