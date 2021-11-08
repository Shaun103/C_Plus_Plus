// Section 18
// Miles per Gallon - Function - Multiple Exceptions
#include <iostream>
#include <string>

void func_a();
void func_b();
void func_c();

void func_a(){
    std::cout << "Starting func_a" << std::endl;
    func_b();   // goes back here
    std::cout << "Ending func_a" << std::endl;  // this wont execute 
}

void func_b(){
    std::cout << "Starting func_b" << std::endl;
    try {
        func_c(); // goes back here 
    }
    catch (int &ex){
        std:: cout << "Caught error! in function b" << std::endl;  // handling exception
    }
    std::cout << "Ending func_b" << std::endl;  // this wont execute
}

void func_c(){
    std::cout << "Starting func_c" << std::endl;
    throw 100; // goes back to 'c'
    std::cout << "Ending func_c" << std::endl;
}

int main() {    

    std::cout << "Starting main" << std::endl;
    try {
        func_a();
    }
    catch (int &ex){
        std:: cout << "Caught error!" << std::endl;
    }
    
    std::cout << "Finnishing main" << std::endl;
    
        return 0;
}

