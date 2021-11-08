// Section 19
// Copy File 2
// File copy using get/put
#include <iostream>
#include <fstream>
#include <string>

int main() {

    /***********************************************************************************/
    // uses .get() method

    std::ifstream in_file {"poem.txt"};        // file reading from
    std::ofstream out_file{"poem_out.txt"};    // creating copy file 

    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
     if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    
    char c;
    while (in_file.get(c))      // by character
        out_file.put(c);        // outputting copy character to another file
    
    std::cout << "File copied" << std::endl;

    in_file.close();
    out_file.close();

    /***********************************************************************************/
    // uses getline() method

    // std::ifstream in_file {"poem.txt"};        // file reading from
    // std::ofstream out_file{"copy_poem_out.txt"};    // creating copy file 

    // if (!in_file) {
    //     std::cerr << "Error opening input file" << std::endl;
    //     return 1;
    // }
    //  if (!out_file) {
    //     std::cerr << "Error opening output file" << std::endl;
    //     return 1;
    // }
    
    // std::string line{};
    // while (std::getline(in_file, line))      // by string
    //     out_file << line << std::endl;        // outputting copy string to another file
    
    // std::cout << "File copied" << std::endl;

    // in_file.close();
    // out_file.close();

    return 0;
}