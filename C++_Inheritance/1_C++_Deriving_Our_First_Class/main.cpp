// Section 15
// Deriving our First Class

#include <iostream>
#include <string>

using namespace std;

class Account {
    public:
        double balance;
        std::string name;
        void deposit(double amount);
        void withdraw(double amount);
        Account();
        ~Account();
};

Account::Account()  
    :  balance{0.0}, name{"An Account"} {
}

Account::~Account(){
}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount  << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}

class Savings_Account: public Account{
    public:
        double int_rate;
        void deposit(double amount);
        void withdraw(double amount);
        Savings_Account();
        ~Savings_Account();
};

Savings_Account::Savings_Account()
    : int_rate {3.0} {
}

Savings_Account::~Savings_Account() {
}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}

int main() { 
    
// Use the Account class
cout << "\n=== Account ==================================" << endl;

Account acc{};

acc.deposit(2000.0);               
acc.withdraw(500.0);

cout << endl;

Account *p_acc {nullptr};

p_acc = new Account();

p_acc->deposit(45000.0);
p_acc->withdraw(500.0);
delete p_acc;

// Use the Savings Account class

cout << "\n=== Savings Account ==========================" << endl;

Savings_Account sav_acc {};

sav_acc.deposit(2000.0);               
sav_acc.withdraw(500.0);

cout << endl;

Savings_Account *p_sav_acc {nullptr};

p_sav_acc = new Savings_Account();

p_sav_acc->deposit(3700.0);
p_sav_acc->withdraw(500.0);
delete p_sav_acc;

cout << "\n==============================================" << endl;

    return 0;
}