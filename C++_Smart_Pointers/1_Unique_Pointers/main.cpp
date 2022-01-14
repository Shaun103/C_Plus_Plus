// Section 17
// Unique Pointers 
#include <iostream>
#include <memory>
#include <vector>

/************************************************************************/
// Abstract class

class I_Printable{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

/************************************************************************/
// Account - Base Abstract class

class Account: public I_Printable {
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const override;
    virtual ~Account() = default;
};

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Account::print(std::ostream &os) const  {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

/************************************************************************/
// Checking_Account

class Checking_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Checking_Account() = default;
};

// Constructor Checking_Account
Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance  << "]";  
}

/************************************************************************/
// Savings_Account

class Savings_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Savings_Account() = default;
};

// Constructor
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

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;   
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}

/************************************************************************/
// Trust_Account

class Trust_Account : public Savings_Account {
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
    Trust_Account(std::string name = def_name,  double balance = def_balance, double int_rate = def_int_rate);
    
    // Deposits of $5000.00 or more will receive $50 bonus
    virtual bool deposit(double amount) override;
    
    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_withdrawals {0}  {
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

/************************************************************************/
// Test class

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main() {

    /************************************************************************/
    // // Raw Pointer
    Test *tt1  = new Test {};
    delete tt1;

    /************************************************************************/
    // Unique Pointer - points to any type 
    // CANNOT have unique pointers point to the same thing

    std::unique_ptr<Test> t1 {new Test {100}};

    /************************************************************************/
    // BEST WAY - modern way 
    // make_unique function - makes any unique pointer
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000); 
    
    // The auto keyword decides what type of t100 based on what is returned
    auto t100 = std::make_unique<Checking_Account>("Mickey Mouse", 10);
    cout << *t100 << endl; 


    /************************************************************************/
    // std::move() function 

    std::unique_ptr<Test> t3;
    // t1 = t3; // COMPILER ERROR - NOT copy or assign 

    t3 = std::move(t1); // points t3 to t1, t1 is now null

    // t1 is now null since it was moved to t3
    if (!t1) 
            std::cout << "t1 is nullptr" << std::endl;

    /************************************************************************/
    // Dynamic polymorphism
    // Base/Abstract class - one of the accounts 

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;  // Dereferencing - to display
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    // /************************************************************************/
    // // auto keyword 

    // auto t200 = make_unique<Checking_Account>("Minie Mouse", 420);
    // std::cout << *t200 << std::endl;  // Dereferencing - to display
    // t200-> deposit(100);
    // std::cout << *t200 << std::endl;

    // /************************************************************************/
    // // vector of unique pointers 

    // // creating the vector 
    // std::vector<std::unique_ptr<Account>> myAccounts;

    // // placing into the vector
    // myAccounts.push_back(make_unique<Checking_Account>("James", 1000));
    // myAccounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    // myAccounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));

    // /************************************************************************/
    // // looping through the vector 


    // // // COMPITER ERROR - by copy 
    // // for (auto acc: accounts)
    // //     std::cout << *acc << std::endl; 

    // /************************************************************************/

    // for (auto &i: myAccounts)   
    //     std::cout << *i << std::endl; 

    return 0;
}