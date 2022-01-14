// Section 17
// Shared Pointers 
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

void displayPtrCount(std::shared_ptr<Test> p) {
    std::cout << "displayPtrCount: " << std::endl;
    std::cout << "Use count: " << p.use_count() << std::endl;
}

using namespace std;

int main() {

    // std::shared_ptr<int> p1 {new int {100}};
    // std::cout << "Use count: " << p1.use_count() << std::endl; // 1

    // std::shared_ptr<int> p2 {p1};  // copy constructor 
    // std::cout << "Use count: " << p1.use_count() << std::endl; // 2

    // p1.reset(); // decrement the use_count; p1 is nulled out
    // std::cout << "Use count: " << p1.use_count() << std::endl; // 0 
    // std::cout << "Use count: " << p2.use_count() << std::endl; // 1

    /************************************************************************************/

    std::cout << "\n=========================================================" << std::endl;
    std::shared_ptr<Test> ptr = std::make_shared<Test> (100);
    displayPtrCount(ptr);
    std::cout << "Use count: " << ptr.use_count() << std::endl;             // 1
    {
        std::shared_ptr<Test> ptr1 = ptr; 
        std::cout << "Use count: " << ptr.use_count() << std::endl;         // 2
        {
            std::shared_ptr<Test> ptr2 = ptr; 
            std::cout << "Use count: " << ptr.use_count() << std::endl;     // 3
            ptr.reset();                                                    // cout reset to 0
        }
        std::cout << "Use count: " << ptr.use_count() << std::endl;         // 0
    }
    std::cout << "Use count: " << ptr.use_count() << std::endl;             // 0


    /************************************************************************************/
    // Using polymorphism
    // 

    std::cout << "\n=========================================================" << std::endl;
    std::cout << "\n" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account> ("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account> ("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account> ("Curly", 6000);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl; 
    }
    
    std::cout << "\n=========================================================" << std::endl;

    return 0;
}

