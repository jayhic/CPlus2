#include "Game.h"

using namespace Game;

void to_play(bool &replay){ //Function that pulls together all the functions I made for the game
    char ch;
    cout << "Do you want to see the instructions? (y/n)" << endl;
    cin >> ch;
    if (ch == 'y') instructions();
    cave c;
    player p;
    wumpus w;
    pits pi;
    bats b;
    vector<vector<int>> rooms;
    c.set_rooms(rooms);
    int player_location;
    int arrows = 5;
    int pit1;
    int pit2;
    int bat1;
    int bat2;
    int wumpus;
    c.set_chars(player_location,pit1, pit2, bat1, bat2, wumpus);
    string command;

    bool game_set=true;
    while (game_set==true) {
        c.room_con(rooms, player_location);
        c.check_hazards(rooms, player_location, pit1, pit2, bat1, bat2, wumpus);
        cout << "Enter command: ";
        cin >> command;
        try {
            if (command[0] == 'm')
                p.move(command, player_location, rooms);
            else if (command[0] == 's') {
                bool close = true;
                p.shoot(command, player_location, wumpus, rooms, arrows, close, game_set);
                if (close == false)
                    w.wumpus_shoot(wumpus, rooms);
            }
            else if (command == "debug")
                debug(rooms, pit1, pit2, bat1, bat2, wumpus, arrows);
            else
                cout<< "Command not recognized please try again" << endl;
        }
    catch(exception& e){
        cout << "Command not recognized please try again" << endl;
    }

        if(game_set==true)
            p.check(arrows, game_set);
        if(game_set==true)                              //If already lost wont display more info
            w.check(player_location,wumpus,game_set);   //Check when the player moves
        w.wumpus_start(wumpus,rooms);
        if(game_set==true)                              //If already lost wont display more info
            w.check(player_location,wumpus,game_set);   //Check when the wumpus moves
        if(game_set==true)                              //If already lost wont display more info
            pi.check(player_location, pit1, pit2, game_set);
        if(game_set==true)                              //If already lost wont display more info
            b.check(player_location, bat1, bat2, pit1, pit2, wumpus);
    };
    cout << "Do you want to play again? (y/n)" << endl;
    cin >> ch;
    if(ch != 'y')
        replay=false;

}

int main(){
    bool replay=true;
    while (replay==true){
        to_play(replay);
    }
    cout << "Thanks for playing!";
}