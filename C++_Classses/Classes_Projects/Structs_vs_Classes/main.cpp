#include <iostream>
#include <string>
using namespace std;

// members of a struct are public by default
// members of a Class are private by default 


/*
    struct
    passive objects, 
    dont need to declare methods

    use class
    when the objects are active
    need to declare methods
*/


struct Person {
    std::string name;
    std::string get_name();
};

int main () {
    
    Person p; 
    p.name = "Frank";
    std::cout << p.get_name(); 




    return 0; 
} 