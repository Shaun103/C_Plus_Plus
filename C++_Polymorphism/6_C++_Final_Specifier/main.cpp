#include <iostream>
using namespace std;

class A {
    public:
        virtual void do_something();
};

class B: public A {
    virtual void do_something() final;  // prevents the futher inheriting overriding function 
};


class C: public B {
    virtual void do_something(){        // COMPILER ERROR - cant override from class B function
    }
};

int main () {

    return 0; 
} 