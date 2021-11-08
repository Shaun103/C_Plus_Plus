#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Mystring {

    /*********************************************************************/

    // insertion operator
    friend std::ostream &operator << (std::ostream &os, const Mystring &rhs); 
    
    // extracion operator
    friend std::istream &operator >> (std::istream &in, Mystring &rhs); // not const, I want to modidfy the object

    /*********************************************************************/
    
friend bool operator==(const Mystring &lhs, const Mystring &rhs);
friend Mystring operator-(const Mystring &obj);
friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

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

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i<std::strlen(buff); i++) 
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

    // overloaded insertion operator
    std::ostream &operator << (std::ostream &os, const Mystring &rhs) {
        os << rhs.str;
        return os;
    }

    // overload extraction operator
    std::istream &operator >> (std::istream &in, Mystring &rhs) {
        char *buff = new char[1000];
        in >> buff;

        rhs = Mystring {buff};
        delete [] buff;
        return in;
    }

/*********************************************************************************/



int main() {
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}

