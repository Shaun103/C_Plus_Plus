#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player {
    private:
        // belongs to the class - only has access to static variables
        static int num_players;

        std::string name;
        int health;
        int xp;
    public:
        std::string get_name() {return name;}
        int get_health() {return health;}
        int get_xp() {return xp;}
        Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
        
        // Copy constructor
        Player(const Player &source);
        
        // Destructor
        ~Player();

    // static class function
    static int get_num_players();

};

#endif // _Player_H_

// initializing to zero
int Player::num_players {0}; 

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}{
        ++num_players;
    }   

Player::Player(const Player &source)
    : Player {source.name, source.health, source.xp} {
    }

// empty destructor
Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}