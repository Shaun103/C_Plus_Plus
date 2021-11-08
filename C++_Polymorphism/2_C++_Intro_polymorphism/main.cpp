#include <iostream>
#include <memory>

using namespace std;

class Base {
    public:
        void say_hello() const {
            std::cout  << "Hello - I'm a Base class object" << std::endl;
        }
};

class Derived: public Base {
    public:
        void say_hello() const {
            std::cout  << "Hello - I'm a Derived class object" << std::endl;
        }
};

void greetings(const Base &obj){   // always bind to "Base::say_hello"
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main () {
    
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greetings(b);
    greetings(d);

    // *ptr can hold a memory address of any base object, 
    // but Derived is a Base object (this is not what we want)
    Base *ptr = new Derived();      
    ptr->say_hello();               // will bind to Base::say_hello();

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();  // still stacticly bound - Base::say_hello(); - we cannnot access Derived::say_hello()    

    // staticly bound - 



    delete ptr;

    return 0; 
} 