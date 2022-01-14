// Section 18
// Miles per Gallon - No Exception handling
#include <iostream>

int main() {   

    int miles {};
    int gallons {};
    double miles_per_gallon {};   
 
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    //    miles_per_gallon = miles / gallons;
    
    if (gallons != 0) {
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } else {
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;

    /*****************************************************************/

    int miles {};
    int gallons {};
    double miles_per_gallon {};   
 
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try{
        if (gallons == 0)
            throw 0;   // next code does not execute 
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) {  // always by reference - '&ex'  
        std::cout << "Sorry, you can't divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;

    return 0;
}
