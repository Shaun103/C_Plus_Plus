#ifndef _ACOUNT_H_
#define _ACOUNT_H_
#include <string>

class Account{
private:
    // attributes
    std::string name;
    double balance;

public:
    // methods
    // declared inline
    void set_balance(double bal){ 
        balance = bal;
    }
    
    double get_balance(){ 
        return balance;
    }

    // methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::set_name(std::string n){
    name = n;
};

std::string Account::get_name(){
    return name;
};

bool Account::deposit(double amount) {
    // if verify amount
    balance += amount;
    return true;
};

bool Account::withdraw(double amount) {
    if (balance-amount >= 0){
        balance -= amount;
        return true;
    } else {
        return false;
    }
};

#endif //_ACCOUNT_H_