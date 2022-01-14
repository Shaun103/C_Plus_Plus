#include <iostream>
#include <cstring>
using namespace std;


class Mystring{

    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;                                                   // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                  // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                            // Copy constructor
    Mystring( Mystring &&source);                                // Move constructor
    ~Mystring();                                                 // Destructor
    
    Mystring &operator=(const Mystring &rhs);                    // Copy assignment
    Mystring &operator=(Mystring &&rhs);                         // Move assignment


    /*****************************************************************************************/

    // booleans
    bool operator==(const Mystring &rhs) const; 
    bool operator!=(const Mystring &rhs) const; 
    bool operator<(const Mystring &rhs) const; 
    bool operator>(const Mystring &rhs) const; 

    // lowercase
    Mystring operator-() const; 

    //concatenating
    Mystring operator+(const Mystring &rhs) const;

    // concat and assign
    Mystring &operator+=(const Mystring &rhs);

    // s1 = s2 * 3; repeat s2 n times
    Mystring operator*(int n) const;

    // s1 *= 3; s1 = s1 * 3
    Mystring &operator*=(int n);

    // pre-incrememnt ++s1;
    Mystring &operator++();
    
    // post-increment s1++;
    Mystring operator++(int);


    /*****************************************************************************************/

    void display() const;
    
    int get_length() const; // getters
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
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
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

// Not Equal
bool Mystring::operator!=(const Mystring &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
} 

// Less Than
bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

// Greater Than
bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}


// Make Lowercase
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concatenante 
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//concat and asign
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// repeat
Mystring Mystring::operator*(int n) const {
    Mystring temp;
    for (int i = 0; i < n; i++)
        temp = temp + *this;
    return temp; 

// // alternative
//     size_t buff_size = std::strlen(str) * n + 1;
//     char *buff = new char[buff_size];
//     strcpy(buff, "");
//     for (int i = 0; i <= n; i++)
//         strcat(buff, str);
//     Mystring temp{buff};
//     delete [] buff;
//     return temp; 
}

// repeat and asign
Mystring &Mystring::operator*=(int n){
    *this = *this * n;
    return *this;
}

// Pre-increment
Mystring &Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

// post-increment
Mystring Mystring::operator++(int){
    Mystring temp (*this);
    operator++();
    return temp; 
}

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}


// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

/*****************************************************************************************/

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }


int main() {
    
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};
    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;         // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;         // true
     cout << (a<b) << endl;         // true
    cout << (a>b) << endl;          // false
    
    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl;             // frank              

    s1 = s1 + "*****";
    cout << s1 << endl;             // frank*****       
    
    s1 += "-----";                  // frank*****-----
    cout << s1 << endl;
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;             // 123451234512345
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    Mystring repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    cout << (repeat_string * 12) << endl;
    
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    repeat_string += (repeat_string * 3);
    cout << repeat_string << endl;
    
    repeat_string = "RepeatMe";
    repeat_string += (repeat_string + repeat_string + repeat_string);


    Mystring s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    Mystring result;
    result = ++s;                           
    cout << s << endl;                  // FRANK
    cout << result << endl;             // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    result = s++;
    cout << s << endl;                  // FRANK
    cout << result << endl;             // frank



    return 0;
}
