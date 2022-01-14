// Section 17
// Weak Pointers
// Created from shared ptrs
#include <iostream>
#include <memory>
using namespace std;

class B;    // forward declaration - class prototype

class A {
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B {
    // std::weak_ptr<A> a_ptr;    // MAKE WEAK TO BREAK THE STRONG CIRCULAR REFERENCE
    std::shared_ptr<A> a_ptr;   
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};



int main() {

// Memory leak - Destructors are never called
shared_ptr<A> a = make_shared<A> ();
shared_ptr<B> b = make_shared<B> ();

a->set_B(b);
b->set_A(a);

    return 0;
}

