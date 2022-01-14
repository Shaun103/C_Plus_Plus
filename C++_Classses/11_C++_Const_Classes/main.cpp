#include <iostream>
#include <string>
using namespace std;

/*
    All functions that display
    what a value is, should 
    use CONST 
*/

class Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        std::string get_name() const {
            // xp = 100
            // CONTRADICTION - connot change 
            // after adding CONST 
            return name;
        }
        void set_name(std::string name_val) {
            name = name_val;
        }

    // Overloaded Constructors
        // Prototype - Player(std::string name_val) const; 
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player{"None", 0, 0} {
}

Player::Player(std::string name_val)
    : Player{name_val, 0, 0}{
}

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}{
}


// p.get_name is a CONST
void display_player_name(const Player &p){
    cout << p.get_name() << endl;
}

int main () {
    
    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

    // villain.set_name("Super villain");       // should NEVER work, Player villain CONST
    // cout << villain.get_name() << endl;      // should not work CONST
    // cout << hero.get_name() << endl;         // should work, it is ok (copy)

// _____________________________________________________________________________________________________

    display_player_name(villain);
    display_player_name(hero);


    
    return 0; 
} 