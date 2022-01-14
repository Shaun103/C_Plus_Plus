#include <iostream>

class Account {
    // friend functions are not inherited
    friend std::ostream &operator << (std::ostream &os, const Account &acc);
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() { }
};

std::ostream &operator << (std::ostream &os, const Account &acc){
    os << "Account display";
    return os;
}


/********************************************************************************************/
// Checking

class Checking: public Account {
    // friend functions are not inherited
    friend std::ostream &operator << (std::ostream &os, const Checking &acc);
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() { }
};

std::ostream &operator << (std::ostream &os, const Checking &acc){
    os << "Checking display";
    return os;
}


/********************************************************************************************/
// Savings

class Savings: public Account {
    // friend functions are not inherited
    friend std::ostream &operator << (std::ostream &os, const Savings &acc);
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() { }
};

std::ostream &operator << (std::ostream &os, const Savings &acc){
    os << "Savings display";
    return os;
}


/********************************************************************************************/
// Trust

class Trust: public Account {
    // friend functions are not inherited
    friend std::ostream &operator << (std::ostream &os, const Trust &acc);
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { }
};

std::ostream &operator << (std::ostream &os, const Trust &acc){
    os << "Trust display";
    return os;
}


/********************************************************************************************/

int main() {

// Account a;
// std::cout << a << std::endl;

// Checking c;
// std::cout << c << std::endl;

// Savings s;
// std::cout << s << std::endl;

// Trust t;
// std::cout << t << std::endl;

/********************************************************************************************/
// no virtual functions to allow us to work with Account operator

Account *p1 = new Account();
std::cout << *p1 << std::endl;         // dereferencing *pt1


Account *p2 = new Account();            // base class pointer
std::cout << *p2 << std::endl;







    return 0;
}
