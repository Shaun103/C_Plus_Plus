// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s){

    std::deque<char> d;

    // add all the string characters that are alpha to the back of the deque in uppercase
    for (char c: s)
        if(std::isalpha(c))                 // grabs only the letters
            d.push_back(std::toupper(c));

    char c1 {};  // front
    char c2 {};  // back

    while(d.size() > 1) {
        c1 = d.front(); 
        c2 = d.back();

        d.pop_front();  // elem front
        d.pop_back();   // elem back
        if(c1 != c2)    // compare middle value
            return false;
    }
    return true;
}

int main(){

    std::vector<std::string> test_strings {
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" 
    };
   
    std::cout << std::boolalpha;

    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;

    return 0;
}