#include <iostream>
using namespace std;

int mainMenu(){

    int menuChoice{0};

    std::cout << "\nPlease select a number from the menu: " << std::endl;
    std::cout << "1: Add Records" << std::endl;
    std::cout << "2: List Records" << std::endl;
    std::cout << "3: Modify Records" << std::endl;
    std::cout << "4: Delete Records" << std::endl;
    std::cout << "5: Exit Program" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Select Your Choice :=>" << std::endl;
    std::cin >> menuChoice;

    return menuChoice;
}

int main () {
    
    bool toContinue = true; 

    do {

        switch (mainMenu()) {
        case 1:
            std::cout << "Add Records";
            break;
        case 2:
            std::cout << "List Records";
            break;
        case 3:
            std::cout << "Modify Records";
            break;
        case 4:
            std::cout << "Delete Records";
            break;
        case 5:
            cout << "..Now terminating program" << endl;
            toContinue = false;  // breaks the do-while loop, end program
            break;
        default: 
            std::cout << "You did not select an option from the menu..." << std::endl;
        }

    } while (toContinue != false); 

    return 0; 
} 