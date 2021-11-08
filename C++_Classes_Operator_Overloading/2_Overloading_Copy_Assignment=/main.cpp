#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Mystring{
    private:
        char *str;      // pointer to a char[] that holds a C-style string
    public:
        Mystring();                                  // No-args contstructor
        Mystring(const char *s);                     // Overloaded contstructor     
        Mystring(const Mystring &source);            // Copy constructor
        ~Mystring();                                 // Destructor

        Mystring &operator=(const Mystring &rhs);    // Copy assignment - rhs = rightHandSide

        void display() const;
        int get_length() const;                      
        const char *get_str() const;
};

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {                                // pointer *str
    str = new char[1];                              // helps to display the pointer
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

        /****************************************************/
        // Copy Assignment allows for objects to assign to other objects
        // Mystring a = Mystring b; 
        Mystring &Mystring::operator=(const Mystring &rhs){
            std::cout << "Copy assignment" << std::endl;
            // check to see if we are copying ourselves
            if (this == &rhs)
                return *this;

            delete [] this ->str;                           // deleting left side object on heap
            str = new char[std::strlen(rhs.str) + 1];       // copying the length of str + 1
            std::strcpy(this->str, rhs.str);
            return *this;
        }

        /****************************************************/

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }


int main () {
    
    Mystring a {"Hello"};                 // overloaded constructor
    Mystring b;                           // no-args contructor
    b = a;                                // copy assignment b.operator=(a)
    b = "This is a test";                 // b.operator=("This is a test");

    a.display();
    b.display();


    Mystring empty;                       // no-args constructor
    Mystring larry("Larry");              // overloaded constructor
    Mystring stooge {larry};              // copy constructor 
    Mystring stooges;                     // no-args constructor
    
    empty = stooge;                       // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                      // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                            // Larry
                                                                // Moe
                                                                // Curly
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment
        
    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed

    return 0; 
} 