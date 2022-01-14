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

        Mystring( Mystring &&source);                // Move constructor

        ~Mystring();                                 // Destructor
        Mystring &operator=(const Mystring &rhs);    // Copy assignment - rhs = rightHandSide        

        Mystring &operator=(Mystring &&rhs);         // Move Assignment

        void display() const;
        int get_length() const;                     // getters
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

/****************************************************/
// Move Constructor - based on a an R value reference
// creating a new object

Mystring::Mystring(Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used " << std::endl; 
}

/****************************************************/

// Destructor
Mystring::~Mystring() {

    if (str == nullptr){
        std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    } else {
        std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

// Copy Assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;

    delete [] this ->str;                           // deleting left side object on heap
    str = new char[std::strlen(rhs.str) + 1];       // copying the length of str + 1
    std::strcpy(this->str,rhs.str);
    return *this;
}


/****************************************************/
// Move assignment - r value reference 

Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Using move assignment" << std::endl; 
    if (this == &rhs)  // Checking self assginment 
        return *this;

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;  // make sure its pointing no where
    return *this;
}

/****************************************************/

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

int main () {
    
    Mystring a {"Hello"};
    a.display();
    a = Mystring {"Hola"}; 
    a.display();
    a = "Bonjour"; 
    a.display();
    
 
    Mystring empty;                                         // no-args constructor
    Mystring larry("Larry");                                // overloaded constructor
    Mystring stooge {larry};                                // copy constructor 
    Mystring stooges;                                       // no-args constructor
    
    empty = stooge;                                         // copy assignment operator
                                                            // stooge is an l-value
    
    empty = "Funny";                                        // move assignment operator
                                                            // "Funny" is an r-value
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();
    
    vector<Mystring> stooges_vec;

    stooges_vec.push_back("Larry");                         // Move constructor
    stooges_vec.push_back("Moe");                           // Move constructor
    stooges_vec.push_back("Curly");                         // Move constructor    
    
    cout << "\nHere: " << endl;
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();
        
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed"; // 7 - lenth of string               // move assignment
        
    cout << "=== Loop 3 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();

    return 0; 
} 