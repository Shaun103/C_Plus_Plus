#include <iostream>


using namespace std;



// Account class
class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
protected:
    double balance;
public:
    Account();
    Account(double balance);            
    void deposit(double amount); 
    void withdraw(double amount);
};


Account::Account() 
    : Account(0.0) {    // delegating constructor
}
        
Account::Account(double balance)
    : balance(balance) { 
}
            
void Account::deposit(double amount) {   
    balance += amount;
}

/**********************************************
    WITHDRAWL Method is being reused!

************************************************/    
void Account::withdraw(double amount) {         
    if (balance-amount >= 0)
        balance-=amount;
    else    
        std::cout << "Insufficient funds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os <<  "Account balance: " << account.balance;
    return os;
}

/******************************************************************/
// Savings Account 

class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    void deposit(double amount);
    // Withdraw is inherited // REUSING!
};

Savings_Account::Savings_Account(double balance, double int_rate)
    : Account(balance), int_rate{int_rate} {
        
    }

Savings_Account::Savings_Account() 
    : Savings_Account{0.0, 0.0} {        
}
    
void Savings_Account::deposit(double amount) {
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}



int main() {

/*

    Reusing the withdraw method
    using static binding 

*/

    cout << "\n===== Account class ===================" << endl;

    Account a1 {1000.0};
    cout << a1 << endl;         // Account balance: 1000
    
    a1.deposit(500.0);
    cout << a1 << endl;         // Account balance: 1500
    
    a1.withdraw(1000);            // Account balance: 500
    cout << a1 << endl;
    
    a1.withdraw(5000.0);         // Insufficient funds
    cout << a1 << endl;         // Account balance: 500

    cout << "\n===== Savings Account class ===========" << endl;

    Savings_Account s1 {1000, 5.0}; 
    cout << s1 << endl;          // Savings Account balance: 1000, Interest rate: 5
    
    s1.deposit(1000);
    cout << s1 << endl;          // Savings Account balance: 2050, Interest rate: 5
    
    s1.withdraw(2000);
    cout << s1 << endl;          // Savings Account balance: 50, Interest rate: 5
    
    s1.withdraw(1000);           // Insufficient funds
    cout << s1 << endl;          // Savings Account balance: 50, Interest rate: 5
    
    
    return 0;
}