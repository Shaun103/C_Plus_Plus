using namespace std;
#include <iostream>
#include <memory>
#include <vector>


/***************************************************/
// Illegal Balance Exception
class IllegalBalanceException: public std::exception{
    public:
        IllegalBalanceException() noexcept = default;
        ~IllegalBalanceException() = default;
        virtual const char *what() const noexcept {
            return "Illegal balance exception";
        }
};

/***************************************************/
// Insufficient Funds Exception
class InsufficientFundsException: public std::exception{
    public:
        InsufficientFundsException() noexcept = default;
        ~InsufficientFundsException() = default;
        virtual const char *what() const noexcept {
            return "Insufficient funds exception";
        }
};

/***************************************************************************************/
class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;

};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

/***************************************************************************************/
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
    // if the balance is negative, we will throw an exception
        if (balance < 0.0)      
            throw IllegalBalanceException{};
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
    } else{
        throw InsufficientFundsException{};
    }
}

 void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

/***************************************************************************************/

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

Checking_Account::Checking_Account(std::string name, double balance)
    try : Account {name, balance} {
        
    }
    catch (...) {
        ;
    }

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance  << "]";
}

/***************************************************************************************/

class Savings_Account: public Account {
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
    virtual void print(std::ostream &os) const override;

    virtual ~Savings_Account() = default;
};

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited

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

/***************************************************************************************/

class Trust_Account: public Savings_Account {
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

    virtual ~Trust_Account() = default;
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
/***************************************************************************************/

// Displays Account objects in a vector of Account objects 
void display(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts===========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << "\n=== Savings Accounts=====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts===========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts=======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

// Helper functions for Checking Account class

// Displays Checking Account objects in a  vector of Checking Account objects 
void display(const std::vector<Checking_Account> &accounts) {
    std::cout << "\n=== Checking Accounts=====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Checking Account object in the vector
void deposit(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts===========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Checking Account object in the vector
void withdraw(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts=======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Trust Account objects 
void display(const std::vector<Trust_Account> &accounts) {
    std::cout << "\n=== Trust Accounts=====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Trust Account object in the vector
void deposit(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts===========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Trust Account object in the vector
void withdraw(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts=======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

int main() {

    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;

    try {
        larrys_account = std::make_unique<Savings_Account> ("Larry", -2000.0);
        std::cout  << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl; // calls virtual function (negative balance)
    }

    try {
        moes_account = std::make_unique<Savings_Account> ("Moe", 1000.0);
        std::cout  << *moes_account << std::endl;
        moes_account->withdraw(500.0); 
        std::cout  << *moes_account << std::endl;
        moes_account->withdraw(1000.0);   // throw an exception
        std::cout  << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex){      // Illegal Balance Exception
        std::cerr << ex.what() << std::endl;
    }
    catch (const InsufficientFundsException &ex){   // Insufficient Funds Exception
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;

    return 0;
}