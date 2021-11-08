// Section 18
// Miles per Gallon - Function - Multiple Exceptions
#include <iostream>
#include <string>

class DivideByZeroException {   // using default objects/constructors - 0 
};
class NegativeValueException {
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw DivideByZeroException();
    else if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main() {    

    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (const DivideByZeroException &ex){
        std::cerr << "Sorry, you can't divide by zero" << std:: endl; 
    }
    catch (const NegativeValueException &ex){
        std::cerr << "Sorry, one of you parameters is negative" << std:: endl; 
    }
    std::cout << "..terminating program...BYE!" << std::endl;

    return 0;
}
