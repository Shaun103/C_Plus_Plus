#include <iostream>
using namespace std;


class Base {

    private:
        int value;
    public:
        Base() : value{0} { cout << "Base no-args constructor" << endl; }
        Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
        ~Base() { cout << "Base destructor" << endl; }
};



class Derived : public Base {
    using Base::Base;           // inherits all of the constructors from "Base"
    private:
        int doubled_value;
    public:
        Derived() : doubled_value{0} { cout << "Derived no-args constructor" << endl; }
        Derived(int x) : doubled_value{x*2} { cout << "Derived (int) overloaded constructor" << endl; }
        ~Derived() { cout << "Derived Destructor " << endl; }
};


int main () {
    
    // Base b; 

    // Base b{100};

    // Derived d;  // is being called from base, NOT calling from within its own class

    Derived d {1000};   // Base class constructor is called 

    
    return 0; 
} 