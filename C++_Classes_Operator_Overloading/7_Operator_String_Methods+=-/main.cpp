#include <iostream>
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
        

        /********************************************/
        
        Mystring operator-()const;                         // Make lowercase - unary operator 
        Mystring operator+(const Mystring &rhs) const;     // Concatenate (binary opperators need on argument)
        bool operator==(const Mystring &rhs) const;        // compare 

        /********************************************/
        
        void display() const;
        int get_length() const;                     // getters
        const char *get_str() const;        
};

// No-args constructor
Mystring::Mystring(): str{nullptr}{                 // pointer *str
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
Mystring::Mystring(Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
        // std::cout << "Move constructor used " << std::endl; 
    }

// Destructor
Mystring::~Mystring() {

    // if (str == nullptr){
    //     std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    // } else {
    //     std::cout << "Calling destructor for Mystring : " << str << std::endl;
    // }
    delete [] str;
}

// Copy Assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    // std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;

    delete [] this ->str;                           // deleting left side object on heap
    str = new char[std::strlen(rhs.str) + 1];       // copying the length of str + 1
    std::strcpy(this->str,rhs.str);
    return *this;
}


/****************************************************/
// Move assignment 
Mystring &Mystring::operator=(Mystring &&rhs){
    // std::cout << "Using move assignment" << std::endl; 
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

/**********************************************************************************************/

// Equality operator- compare 'this' to 'rhs' 
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) ==0);
}

// Male lowercase
Mystring Mystring::operator-() const{
    char *buff = new char[std::strlen(str)+1];  // *buff - creating a space in memory
    std::strcpy(buff, str);                     // capturing the str into buff
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);

    Mystring temp {buff};           // temp of buff    
    delete [] buff;                 // Dealocating place in memory 

    return temp;
}

// Concatenate 
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    Mystring temp {buff}; 
    delete [] buff;
    return temp; 
}

/**********************************************************************************************/

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }

int main () {
    
    cout << boolalpha << endl;
    
    Mystring larry{"Larry"}; 
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();                                                        // Larry
    moe.display();                                                          // Moe



    /********************************************/
    // equal operators
    cout << (larry == moe) << endl;                                         // false
    cout << (larry == stooge) << endl;                                      // true

    larry.display();                                                        // Larry

    /********************************************/
    // negating operators
    Mystring larry2 = -larry;
    larry2.display();                                                       // larry
     
    Mystring stooges = larry + "Moe";                                       // ok with member function
    //Mystring stooges = "Larry" + moe;                                     // Compiler error
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();  

    return 0; 
} 