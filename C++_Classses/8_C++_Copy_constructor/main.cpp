#include <iostream>
#include <string>
using namespace std;

class Player{

    private:
        std::string name;
        int health;
        int xp;

    public:
        std::string get_name(){return name;}
        int get_health() {return health;}
        int get_xp() {return xp;}

        Player(std::string name_val="None", int health=0, int xp_val=0);
        // Copy constructor
        Player(const Player &source);
        // Destructor - when it will be destroyed
        ~Player() {cout << "Destructor called for: " << name << endl;}
};

// This constructor does all of the work 
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{0}, xp{0} { 
        cout << "Three-args constructor" << endl; 
}

/*******************/
// Copy constructor
/*******************/
Player::Player(const Player &source) 
    // : name {source.name, source.health, source.xp} {                   // initializing 
        : Player {source.name, source.health, source.xp} {                // delegating the copy to the constructor line 25
        cout << "Copy constructor - made a copy :" << source.name << endl; 
}

void display_player(Player p){
    cout << "Name: " << p.get_name() << endl; 
    cout << "Health: " << p.get_health() << endl; 
    cout << "Xp: " << p.get_xp() << endl; 
}

int main () {

    Player empty {"XXXXXXXXXXX", 100, 50};
    
    // Copying/Constructing empty obj
    Player my_new_object {empty};               

    display_player(empty);
    display_player(my_new_object);

    // Player frank{"Frank"};   
    // Player hero{"Hero", 100};  
    // Player villain{"Villain", 100, 55};    

    return 0; 
};