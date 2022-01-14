// Section 19
// Challenge 2 - Solution
// Automated Grader 
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>



int main() {

    // int num{};
    // double total{};
    // std::string name{};
    
    // std::string info {"Moe 100 1234.5"};
    // std::istringstream iss {info};


    // iss >> name >> num >> total;
    // std::cout << std::setw(10) << std::left << name
    //     << std::setw(5) << num
    //     << std::setw(5) << total << std::endl;

    // std::cout << "\n-----------------------------------------------------" << std::endl;


    // //oss = stream, stream = string buffer
    // std::ostringstream oss {};  // output is stored in oss

    // oss << std::setw(10) << std::left << name
    //     << std::setw(5) << num
    //     << std::setw(10) << total << std::endl;
    // std::cout << oss.str() << std::endl;

    std::cout << "\n--------Data validation--------------------------------" << std::endl;

    int value {};           // holding the integer
    std::string entry {};   // holds the conversion
    bool done = false;

    do {

        std::cout << "Please enter an integer:";
        std::cin >> entry;

        std::istringstream validator {entry};   // string stream 

        if (validator >> value)  // validating conversion
            done = true;         // breaking the loop
        else
            std::cout << "Sorry, that's not an integer" << std::endl;

        // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    } while (!done);


    std::cout << "You entered the integer: " << value << std::endl;

    std::cout << std::endl;
    return 0;
}