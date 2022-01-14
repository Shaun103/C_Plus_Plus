#include <iostream>
using namespace std;

class Player{
    private:
        std::string name;
        int health;
        int xp;
    public:
        // displaying function name
        void set_name(std::string name_val){
            name = name_val;
        }
        // setting function name to view
        std::string get_name(){
            return name;
        }
        // Overloaded Constructors(3)
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health, int xp_val);
};

    // initializers
    Player::Player() 
        : name{"None"}, health{0}, xp{0} {
    }

    // initializing name_val
    Player::Player(std::string name_val) 
        : name{name_val}, health{0}, xp{0}{
    }

    // initializing name_val, health_val, xp_val
    Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{0}, xp{0} {
    }

int main () {
    
    Player empty;
    cout <<  empty.get_name() << endl;
    Player frank{"Frank"};
    cout <<  frank.get_name() << endl;
    Player villain {"Villain", 100, 55};
    cout <<  villain.get_name() << endl;

    return 0; 
} 