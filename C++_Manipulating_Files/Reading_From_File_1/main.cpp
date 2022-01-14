// Section 19
// Read File 1
// Test for file open and simple read of 3 data items
#include <iostream>
#include <fstream>
#include <iomanip>




int main() {

    // std::ifstream in_file;
    // // in_file.open("../test.txt"); // codelite - exe debug folder 
    // in_file.open("test.txt");

    // // if (!in_file.is_open()) // alternative
    // if (!in_file){
    //     std::cerr << "Problem opening file" << std::endl;
        
    //     // std::exit(1); // alternative
    //     return 1;
    // }
    // std::cout << "File is good to go, ready to read from" << std::endl; 


    /***********************************************************************************/

    // std::ifstream in_file;
    // std::string line;

    // in_file.open("test.txt");
    // if (!in_file){
    //     std::cerr << "Problem opening file" << std::endl;

    //     return 1;
    // }

    // in_file >> line;
    // std::cout << line << std::endl;
    // in_file.close();


   /***********************************************************************************/

    // std::ifstream in_file;
    // std::string line;
    // int num;
    // double total;

    // in_file.open("test.txt");
    // if (!in_file){
    //     std::cerr << "Problem opening file" << std::endl;
    //     return 1;
    // }

    // in_file >> line >> num >> total;
    // std::cout << line << std::endl;
    // std::cout << num << std::endl;
    // std::cout << total << std::endl;
    
    // in_file.close();

    /***********************************************************************************/

    // std::ifstream in_file;
    // std::string line;
    // int num;
    // double total;

    // in_file.open("test.txt");
    // if (!in_file){
    //     std::cerr << "Problem opening file" << std::endl;
    //     return 1;
    // }

    // while (!in_file.eof()) {  // eof() - function to read entire file
    //     in_file >> line >> num >> total; 
    //     std::cout << std::setw(10) << std::left << line
    //         << std::setw(10) << num
    //         << std::setw(10) << total
    //         << std::endl;
    // }

    // in_file.close();

/***********************************************************************************/

    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");
    if (!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    while (in_file >> line >> num >> total){
        std::cout << std::setw(10) << std::left << line
            << std::setw(10) << num
            << std::setw(10) << total
            << std::endl;
    }


    return 0;
}