#include <iostream>
#include <string>
#include <fstream>



int main() {

/********************************************************************/
// default - truncation (deletes everything when entering new data) 

    // std::ofstream out_file {"output.txt"};

    // if (!out_file){
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // std::string line;
    // std::cout << "Enter something to write to the file: " << std::endl;
    // std::getline(std::cin, line);
    // out_file << line << std::endl;

    // out_file.close();

/********************************************************************/
// Append mode - adds new data instead of deleting old data 

    std::ofstream out_file {"output.txt", std::ios::app};  // append mode 

    if (!out_file){
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Enter something to write to the file: " << std::endl;
    std::getline(std::cin, line);
    out_file << line << std::endl;

    out_file.close();

    return 0;
}