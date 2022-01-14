// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/******************************************************************************************/
// I_Printable
// Base class that connects with Account

class I_Printable{
        // friend classes are not inheritable
        friend std::ostream &operator << (std::ostream &os, const I_Printable &obj);
    public:
        virtual void print(std::ostream &os) const = 0;
        virtual ~I_Printable() = default;
};

// Operator that returns the obj passed into it
std::ostream &operator << (std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

/******************************************************************************************/
// Account

class Account: public I_Printable{
    // friend output
    // friend std::ostream &operator << (std::ostream &os, const Account &account); 
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);     // Default values - if not passed in   
    virtual bool deposit(double amount) = 0;                                // pure virtual function '=0'
    virtual bool withdraw(double amount)= 0;
    virtual void print(std::ostream &os) const override;                    // pure virtual function of 'I_Printable'
    virtual ~Account() = default;
};

// Account Constructors
Account::Account(std::string name, double balance) 
    : name {name}, balance {balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else 
        balance = balance + amount;    /**/ 
        return true;
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

// // No longer needed
// // friend output // NOT NEEDED NOW - LINE 59
// std::ostream &operator<<(std::ostream &os, const Account &account) {
//     os << "[Account: " << account.name << ": " << account.balance << "]";
//     return os;
// }

/******************************************************************************************/
// Checking

class Checking_Account: public Account {
    // friend std::ostream &operator << (std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override; // Deposit Checking
    virtual void print(std::ostream &os) const override;    // pure virtual function of 'I_Printable' 

    virtual ~Checking_Account() = default;
};

// Checking_Account Constructor
Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

// Deposit Checking
bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance  << "]";
} 

// // friend output // NOT NEEDED NOW - LINE 106
// std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
//     os << "[Checking_Account: " << account.name << ": " << account.balance  << "]";
//     return os;
// }

/******************************************************************************************/
// Savings_Account

class Savings_Account: public Account {
    // friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override; // pure virtual function of 'I_Printable' 

    virtual ~Savings_Account() = default;
};

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount){
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}

// NOT NEEDED - LINE 154
// std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
//     os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
//     return os;
// }

/******************************************************************************************/
// Trust

class Trust_Account : public Savings_Account {
    // friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_withdrawals;
public:
    // Trust_Account Constructor
    Trust_Account(std::string name = def_name,  double balance = def_balance, double int_rate = def_int_rate);
    
    // Deposits of $5000.00 or more will receive $50 bonus
    virtual bool deposit(double amount) override;
    
    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;                    // pure virtual function of 'I_Printable'

    virtual ~Trust_Account() = default;
};

// Trust_Account Constructor
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_withdrawals {0}{     
}

// Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}
    
// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate 
    << "%, withdrawals: " << num_withdrawals <<  "]";
}

// NOT NEEDED - LINE 216
// std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
//     os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate 
//         << "%, withdrawals: " << account.num_withdrawals <<  "]";
//     return os;
// }


/******************************************************************************************/
// Helper functions 
// Utility helper functions for Account class

// Displays Account objects in a  vector of Account objects pointers
void display(const std::vector<Account *> &accounts) {
    std::cout << "\n=== Accounts===========================================" << std::endl;
    for (const auto acc: accounts) 
        std::cout << *acc << std::endl;  // dereferencing pointer - overloaded 
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto acc: accounts) 
        if (acc->deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;             // dereferencing *acc
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;     // dereferencing *acc
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto acc:accounts)
        if (acc->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
}

int main() {

/******************************************************************************************/
// Direct instance cretor
    
    
// default Checking_Account constructor
Checking_Account jim;                       
std::cout << jim << std::endl;              

Checking_Account frank {"Frank", 5000};
std::cout << frank << std::endl; 

// default Savings_Account constructor
Savings_Account jerry;
std::cout << jerry << std::endl;

Savings_Account john {"John", 10000, 2.5};
std::cout << john << std::endl;

// default Trust_Account constructor
Trust_Account june;
std::cout << june << std::endl;

Trust_Account jane {"Jane", 20000, 1.5};
std::cout << jane << std::endl;

/******************************************************************************************/
// vector of pointers 

Account *trust = new Trust_Account("James");
cout << *trust << endl; 

Account *p1 = new Checking_Account("Larry", 10000);
Account *p2 = new Savings_Account("Moe", 1000);
Account *p3 = new Trust_Account("Curly");

std::vector<Account *> accounts {p1, p2, p3};

display(accounts);
deposit(accounts, 1000);
withdraw(accounts, 2000);
display(accounts);

delete p1;
delete p2;
delete p3;

    return 0;
}