#include <iostream>

class I_Printable {
    friend std::ostream &operator << (std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const =0;  // pure virtual function
};

std::ostream &operator << (std::ostream &os, const I_Printable &obj){
    obj.print(os);
    return os;
}

class Account: public I_Printable {
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Account display: ";
    }
    virtual ~Account() { }
};




/********************************************************************************************/
// Checking

class Checking: public Account {
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Checking display: ";
    }
    virtual ~Checking() { }
};




/********************************************************************************************/
// Savings

class Savings: public Account {
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Savings display: ";
    }
    virtual ~Savings() { }
};




/********************************************************************************************/
// Trust

class Trust: public Account {
public: 
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Trust display: ";
    }
    virtual ~Trust() { }
};

/********************************************************************************************/
// Dog class - dog is a PRINTABLE

class Dog: public I_Printable {
    public:
        virtual void print(std::ostream &os) const override {
            os << "WOOF! WOOF!";
    }
};

void print(const I_Printable &obj){
    std::cout << obj << std::endl;
}



/********************************************************************************************/

int main() {

Account a;
std::cout << a << std::endl;

Checking c;
std::cout << c << std::endl;

Savings s;
std::cout << s << std::endl;

Trust t;
std::cout << t << std::endl;

/********************************************************************************************/
// no virtual functions to allow us to work with Account operator

Account *p1 = new Account();
std::cout << *p1 << std::endl;          // Dereferencing *pt1


Account *p2 = new Checking();            // Base class pointer
std::cout << *p2 << std::endl;


Account *p3 = new Savings();            // Base class pointer
std::cout << *p3 << std::endl;


Dog *dog = new Dog();                   // Explicitly printing Dog *dog
std::cout << *dog << std::endl;

print(*dog);                            // Dog is a PRINTABLE function

    return 0;
}
