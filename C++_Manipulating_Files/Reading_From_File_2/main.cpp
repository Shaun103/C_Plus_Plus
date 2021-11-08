// Section 19
// Read File 3
// Read and display Shakespeare Sonnet 18 poem using getline
#include <iostream>
#include <fstream>




int main() {

    // std::ifstream in_file;
    // in_file.open("poem.txt");
    
    // if (!in_file) {
    //     std::cerr << "Problem opening file" << std::endl;
    //     return 1;
    // }

    // std::string line;  // Input from poem going into

    // while (std::getline(in_file, line)){ // reading one line at a time
    //     std::cout << line << std::endl;
    // }

    // in_file.close();


    /*******************************************************************************/
    // Reading unformatted get

    std::ifstream in_file;
    in_file.open("poem.txt");
    
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    char c{};   // input variable 

    while (in_file.get(c)){
        std::cout << c;
    }

    std::cout << std::endl;
    in_file.close();

    return 0;
}