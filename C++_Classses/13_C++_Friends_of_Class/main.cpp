#include <iostream>
using namespace std;

/*
    *********************************
    THIS CODE IS NOT SUPPOSED TO RUN!
    *********************************
*/

class Player {
        friend void display_player(Player &p);
        friend void Other_class::display_player(Player &p);
        std::string name;
        int health;
        int xp;
    public:
        
};

class Other_class {
    . . .
    public: 
        void display_player(Player &p) {
            std::cout << p.name << std::endl;
            std::cout << p.health << std::endl;
            std::cout << p.xp << std::endl;
        }
};

void display_player(Player &p) {
    std::cout << p.name << std::endl;
    std::cout << p.health << std::endl;
    std::cout << p.xp << std::endl;
}

int main () {
    

    return 0; 
} 