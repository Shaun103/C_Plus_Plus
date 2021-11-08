// Section 16
// Using Base class pointers

#include <iostream>
#include <vector>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
}
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
}
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
}
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
}
    virtual ~Trust() {  }
};

class Bond: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Bond::withdraw" << std::endl;
}
    virtual ~Bond() {  }
};

int main() {

    std::cout << "\n === Pointers ==== " << std::endl;

    Account *p1 = new Account();     // 'new' creates heap storage (free storage) for large arrays
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    Account *p5 = new Bond();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    p5->withdraw(1000);

    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = { p1, p2, p3, p4 };     // creating an arry with four pointers (Account, Savings, Checking, Trust)
    for (auto i=0; i<5; ++i)
        array[i]->withdraw(1000);     // calls the withdraw method for each different class
        
    std::cout << "\n === Array2 ==== " << std::endl;
    array[0] = p4;      // Trust Account in first position
    for (auto i=0; i<5; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account*> accounts {p1,p2,p3,p4,p5};  // vector of pointers of Account   
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);
        
    std::cout << "\n === Vector ==== " << std::endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    accounts.push_back(p5);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}