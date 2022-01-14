// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(){

    /***************************************************************************************************/
    // numbers all lines 

    // std::ifstream in_file {"romeoandjuliet.txt"};
    // std::ofstream out_file {"copy_romeoandjuliet_out.txt"};

    // if (!in_file.is_open()){
    //     std::cerr << "Error opening input file" << std::endl;
    //     return 1;
    // }

    // if (!in_file.is_open()){
    //     std::cerr << "Error opening input file" << std::endl;
    //     return 1;
    // }

    // std::string line {};
    // int line_number {0};

    // while (getline(in_file, line)){
    //     ++line_number;
    //     out_file << std::setw(7) << std::left << line_number << line << std::endl;
    // }

    // std::cout << "\nCopy complete" << std::endl;

    // in_file.close();
    // out_file.close();

    /***************************************************************************************************/
    // numbers only lines with words


    std::ifstream in_file {"romeoandjuliet.txt"};
    std::ofstream out_file {"copy_romeoandjuliet_out.txt"};


    if (!in_file.is_open()){
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (!in_file.is_open()){
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    std::string line{};
    int line_number{0};
    
    while (getline(in_file, line)){
        if (line == " "){            // if statement to check for blank lines
            out_file << std::endl;  // displays blank line 
        } else {
            ++line_number;
            out_file << std::setw(7) << std::left << line_number << line << std::endl;
        }
    }

    std::cout << "\nCopy complete" << std::endl;

    in_file.close();
    out_file.close();

    return 0;
}