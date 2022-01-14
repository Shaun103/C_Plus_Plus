#include <iostream>
using namespace std;


class Player {
private:
    // attributes
    string name {"Player"};
    int health;
    int xp;
public:
    // methods
    void talk(string text_to_say) {cout << name << " says " << text_to_say << endl; }
    bool is_dead();
};

int main () {
    
    Player frank;
    // frank.name = "Frank";            // accessing private variable
    // cout << frank.health << endl;    // accessing private variable
    frank.talk("Hello there!");


    return 0; 
} 