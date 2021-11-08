// Section 12
// Passing Pointers 1
#include <iostream>

using namespace std;


void double_data(int *ptr) {
   *ptr *= 2;	
}

int main() {


    
    
    int value {10};
    int *int_ptr {nullptr};
    
    cout << "Value: " << value << endl;
    double_data(&value);
    cout << "Value after function: " << value << endl;

    cout << "-----------------------------" << endl;
    
    int_ptr = &value;           // int_ptr pointing to &value (20)
    double_data(int_ptr);
    cout << "Value after function: " << value << endl;

    
    
    cout  << endl;    
    return 0;
}