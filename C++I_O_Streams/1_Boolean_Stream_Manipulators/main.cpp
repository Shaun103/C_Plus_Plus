// Section 19
// Stream manipulators - Boolean
// boolalpha and noboolalpha

#include <iostream>
#include <iomanip>  // Must include for manipulators

int main() {

// default way of displaying boolean values
/**********************************************************************************/
    std::cout << "noboolalpha - default (10 == 10) " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (10 == 20) << std::endl;


// Set to true/false formatting
/**********************************************************************************/
    std::cout << std::boolalpha; // change 1/0 to true/false
    std::cout << "noboolalpha - default (10 == 10) " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (10 == 20) << std::endl;

    // making sure 
    std::cout << "noboolalpha - default (10 == 10) " << (30 == 30) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (40 == 50) << std::endl;


// Toggle to 0/1
/**********************************************************************************/
    std::cout << std::noboolalpha; // changes back from true/false to 1/0
    std::cout << "noboolalpha - default (10 == 10) " << (30 == 30) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (40 == 50) << std::endl;


// Set back to true/false using 'setf' method
/**********************************************************************************/
    std::cout.setf(std::ios::boolalpha);
    std::cout << "noboolalpha - default (10 == 10) " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (10 == 20) << std::endl;


// resets to default which is 0/1
/**********************************************************************************/
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "noboolalpha - default (10 == 10) " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20) " << (10 == 20) << std::endl;

    return 0;
}