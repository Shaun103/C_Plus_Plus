#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    
    int a, b;
    
    
    string one[] = { "", "one ", "two ", "three ", "four ", 
                 "five ", "six ", "seven ", "eight ", 
                 "nine "
               }; 
        
    std::cin >> a >> b;
    
    for (int i=a;i<=b;i++){
        if(i<=9){
            std::cout << one[i] << std::endl;
        } 
        else if(i%2==0){
            std::cout << "even" << std::endl;
        } 
        else {
            std::cout << "odd" << std::endl;
        }
    }

    return 0;
}