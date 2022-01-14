#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Mystring {

    /*********************************************************************/
    // Does not matter where you place friend declaration

    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

    /*********************************************************************/

private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring( Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
   
    void display() const;

    int get_length() const;
    const char *get_str() const;
};


// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str {nullptr} {
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
        // std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        // std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    // std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
Mystring &Mystring::operator=( Mystring &&rhs) {
    // std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }



/*********************************************************************************/
    // Friend non-member function 

    // Equality
    bool operator==(const Mystring &lhs, const Mystring &rhs) {
        return (std::strcmp(lhs.str, rhs.str) == 0);
    }

    // Make lowercase
    Mystring operator-(const Mystring &obj) {
        char *buff = new char[std::strlen(obj.str) + 1];
        std::strcpy(buff, obj.str);
        for (size_t i=0; i < std::strlen(buff); i++) 
            buff[i] = std::tolower(buff[i]);

        Mystring temp {buff};
        delete [] buff;
        return temp;
    }

    // Concatenation
    Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
        char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
        std::strcpy(buff, lhs.str);
        std::strcat(buff, rhs.str);

        Mystring temp {buff};
        delete [] buff;
        return temp;
    }

/*********************************************************************************/

int main() {
    
    Mystring larry {"Larry"};
    larry.display();                                                // Larry
    
    larry = -larry;
    larry.display();                                                // larry
    
    cout << boolalpha << endl;

    Mystring moe{"Moe"};
    Mystring stooge = larry;
    
    cout << (larry == moe) << endl;                                 // false
    cout << (larry == stooge) << endl;                              // true
        
    // Mystring stooges = larry + "Moe";   
    Mystring stooges = "Larry " + moe;                               // Now OK with non-member function
    stooges.display();                                               // LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                                          // Moe Larry

    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                                        // Moe larry Curly             

    return 0;
}