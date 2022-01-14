#include <iostream>
using namespace std;

class Base {
    public:
        virtual void say_hello() const{
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
    virtual ~Base() { std::cout << "Account::destructor" << std::endl; }
};

class Derived: public Base {
    public:                      // OVERRIDE keyword - allows for polymorphic outcome
        virtual void say_hello() const override {  
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
    virtual ~Derived() { std::cout << "Derived::destructor" << std::endl; }
};

class Test: public Base {
    public:                     // OVERRIDE keyword - allows for polymorphic outcome
        virtual void say_hello() const override {
            std::cout << "Hello - I'm a Test class object" << std::endl;
        }
    virtual ~Test() { std::cout << "Test::destructor" << std::endl; }
};


int main () {
    
Base *p1 = new Base();              // Base::say_hello();
p1-> say_hello();

Derived *p2 = new Derived();        // Derived::say_hello();
p2->say_hello();

Base *p3 = new Derived();           // // Base::say_hello(); ????? i wanted Derived::say_hello();
p3->say_hello();

Base *p4 = new Base();              // Base::say_hello();
p4->say_hello();

std::cout << "\n=== Clean up ===" << std::endl;

delete p1;
delete p2;
delete p3;
delete p4;

    return 0; 
} 