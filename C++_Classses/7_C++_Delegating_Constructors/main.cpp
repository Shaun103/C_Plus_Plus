#include <iostream>
#include <string>
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

        // // setting function name to view
        // std::string get_name(){
        //     return name;
        // }
        
        // Overloaded Constructors(3)
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health, int xp_val);
};

    // initial zero default arguments
    Player::Player() 
        : Player("None",0,0){
            cout << "No-args constructor" << endl; 
    }

    // initial one defualt arugment 
    Player::Player(std::string name_val) 
        : Player{name_val,0,0} {
            cout << "One-args constructor" << endl; 
    }

    // This constructor does all of the work 
    Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{0}, xp{0} {
            cout << "Three-args constructor" << endl; 
    }

int main () {

    // no arg constructor  
    // one arge constructor calls three args constructor
    Player empty;
    
    // second arg constructor  
    // two args constructor calls three args constructor                          
    Player frank{"Frank"};
    
    // the last constructor (3 args constructor) 
    // three args constructor is called           
    Player villain {"Villain", 100, 55};    

    return 0; 
} 