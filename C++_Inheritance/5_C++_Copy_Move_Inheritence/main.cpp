#include <iostream>
using namespace std;

class Base {
    private:
        int value;
    public:
        Base()
            : value {0} {
                cout << "Base no-args constructor" << endl; 
        }
        Base(int x)                                             // overloaded int constructor
            : value {x} {
                cout << "int Base constructor" << endl; 
        }
        Base(const Base &other)                                // copy constructor
            : value {other.value} { 
                cout << "Base copy constructor" << endl; 
        }
        Base &operator =(const Base &rhs){                     // overloaded copy assignment operator
            cout << "Base operator=" << endl; 
               if (this == &rhs)
                    return *this;
                value = rhs.value;
                return *this;
        }
        ~Base() { cout << "Base destructor" << endl; }
};

class Derived: public Base {
    private:
        int doubled_value;
    public:
        Derived():
            Base{} {
                cout << "Derived no-args constructor" << endl;
        }
        Derived(int x)
            : Base{x}, doubled_value {x * 2} {
                cout << "int Derived constructor" << endl;
        }
        Derived(const Derived &other)                               // copy constructor
            : Base(other), doubled_value {other.doubled_value} {    // switches Base int value with what is passed in
                cout << "Derived copy constructor" << endl;
        }
        Derived &operator=(const Derived &rhs){                     
            cout << "Derived operator=" << endl; 
            if (this == &rhs)       // checks for self assignment 
                return *this;
            Base::operator=(rhs); // expects a base object
            doubled_value = rhs.doubled_value;
            return *this;
        }
        ~Derived() { cout << "Derived destructor" << endl; }
};

int main () {
    
    // Base b {100};   // overloaded constructor 
    // Base b1 {b};    // Copy constructor 
    // b = b1;         // Copy Assignment 

    /**************************************************/

    Derived d {100};   // 
    Derived d1 {d};    // Copy constructor 
    d = d1;            // 


    return 0; 
} 