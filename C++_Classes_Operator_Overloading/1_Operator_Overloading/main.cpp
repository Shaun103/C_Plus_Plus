// Section 14
// Mystring - starting point
#include <iostream>
#include <cstring>
// #include "Mystring.h"
// #include "/Users/User/Desktop/TAMUCT_C++/C++_Operator_Overloading/src/Mystring.h"


 /*
    Operators that CANNOT be overloaded
    ____________________________________
    ::
    :?
    .?
    .
    sizeof
*/

using namespace std;

class Mystring{
    private:
        char *str;      // pointer to a char[] that holds a C-style string
    public:
        Mystring();                             // No-args contstructor
        Mystring(const char *s);                // Overloaded contstructor   

        Mystring(const Mystring &source);       // Copy constructor 

        ~Mystring();                            // Destructor
        void display() const;
        int get_length() const;                 // getters
        const char *get_str() const;
};

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {                            // pointer *str
    str = new char[1];                          // helps to display the pointer
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)                   // overloaded constructor
    : str {nullptr} {                               // checking if there was a nullptr sent, is so, setting empty
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';                            // setting str to empty string 
        } else {
            str = new char[std::strlen(s)+1];       // find the length of *s (string)
            std::strcpy(str, s);                    // copy the strcpy after finding length
        }
}



// Copy constructor
Mystring::Mystring(const Mystring &source) 
     : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { 
     return std::strlen(str); 
}
 
  // string getter
 const char *Mystring::get_str() const { 
     return str; 
}

int main() {

    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};             // copy constructor call
    Mystring moe("Moe");
    Mystring harry("Harry");
    Mystring test(nullptr);              // testing nullptr

    empty.display();
    larry.display();
    stooge.display();                   // copy of harry
    moe.display();
    harry.display();
    test.display();

    return 0;
};

