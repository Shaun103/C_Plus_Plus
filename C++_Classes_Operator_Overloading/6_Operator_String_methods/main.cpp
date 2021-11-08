#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Mystring{
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();                                                          // No-args constructor
    Mystring(const char *s);                                      // Overloaded constructor
    Mystring(const Mystring &source);                     // Copy constructor
    Mystring( Mystring &&source);                          // Move constructiror
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);    // Copy assignment
    Mystring &operator=(Mystring &&rhs);          // Move assignment


    /********************************************************/

    Mystring operator-() const;                             // make lowercase
    Mystring operator+(const Mystring &rhs) const;          // concatenate
    bool operator==(const Mystring &rhs) const;             // compare

    /********************************************************/

    void display() const;

    int get_length() const;                                        // getters
    const char *get_str() const;
};


// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    cout << "Destructor called: " << str << std::endl;
    delete [] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
Mystring &Mystring::operator=( Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


/*****************************************************************************************/

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Make lowercase
Mystring Mystring::operator-() const {
    char *buff= new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}

// Concatentate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}

/*****************************************************************************************/

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }

int main() {
    cout << boolalpha << endl;
    
    Mystring larry{"Larry"}; 
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();                                                    // Larry
    moe.display();                                                      // Moe
    
    cout << (larry == moe) << endl;                                     // false
    cout << (larry == stooge) << endl;                                  // true

    larry.display();                                                    // Larry
    // Mystring larry2 = -larry;
    // larry2.display();                                                   // larry
     
    // Mystring stooges = larry + "Moe";                                   // ok with member function
    // //Mystring stooges = "Larry" + moe;                                 // Compiler error
    
    // Mystring two_stooges = moe + " " + "Larry";
    // two_stooges.display();                                              // Moe Larry
    // Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    // three_stooges.display();                                            // Moe Larry Curly
    
    return 0;
}

