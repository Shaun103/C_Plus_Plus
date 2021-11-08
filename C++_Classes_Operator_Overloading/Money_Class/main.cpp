#include <iostream>

using namespace std;

class Money {
    int dollars;
    int cents;
public:
    Money(int dollars, int cents);
    Money(int total);
  
    bool operator==(const Money &rhs) const;
    bool operator!=(const Money &rhs) const;
    void display() const;
    
};

// #include "Money.h"

Money::Money(int dollars, int cents) : dollars(dollars), cents(cents) {}

Money::Money(int total) {
    dollars = total/100;
    cents = total % 100;
}

bool Money::operator==(const Money &rhs) const {
    return dollars == rhs.dollars &&
           cents == rhs.cents;
}

bool Money::operator!=(const Money &rhs) const {
    return !(rhs == *this);
}

// Display method
void Money::display() const {
    std::cout << dollars << cents<< std::endl;
}


int main() {

    Money dollars{1};
    Money cents{2};
    



    
    return 0;
}