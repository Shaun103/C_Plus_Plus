#include <iostream>
#include <fstream>

int main(){
    std::cout  << "Write the path of the file\n";
	std::string path;
	std::cin >> path;

	std::ifstream file(path);

	if(file.is_open()){
		std::cout << "File '" << path << "' opened.\n";

		std::cout << "Write the word you're searching for\n";
		std::string word;
		std::cin >> word;

		int countwords = 0;
		int no_match = 0;
		
		std::string candidate;
		while (file >> candidate){ // for each candidate word read from the file 
			++no_match;
			if (word == candidate) 
                ++countwords;
		}
		std::cout << "\nWords searched: " << no_match << std::endl;
		std::cout << "The word '" << word << "' has been found " << countwords << " times.\n";
	} else {
		std::cerr << "Error! File not found!\n";
		return 1;
	}
    return 0;
}