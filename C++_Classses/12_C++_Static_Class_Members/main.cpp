#include <iostream>
#include "Player.h"

using namespace std;


// Easy way to see how many objects you have


void display_active_player(){
    cout << "Active players: " << Player::get_num_players() << endl; 
}

int main () {

    display_active_player();
    Player hero {"Hero", 0, 0};
    display_active_player();


    {
        // within scope
        // out of scope its destroyed
        Player frank {"Frank",0,0};
        display_active_player();
    }

    // out of scope
    // should display 1
    display_active_player();


    Player *enemy = new Player("Enemy",100,100);
    display_active_player();
    delete enemy;
    display_active_player();

    return 0; 
};