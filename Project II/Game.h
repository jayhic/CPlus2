//
// Created by jcox1 on 4/7/17.
//

#ifndef PROJECT_II_GAME_H
#define PROJECT_II_GAME_H

#include "std_lib_facilities.h"

namespace Game {


    class cave {
        //Functions and Variables here
    public:
        void set_rooms(vector<vector<int>>& rooms);  //Start of every game room connections are made random
        void set_chars(int &player_location, int &pit1, int &pit2, int &bat1, int &bat2, int &wumpus);  //Start of every game Player, Pits, Bats, and Wumpus start in different rooms
        void room_con(vector<vector<int>> rooms, int player_location); //Start of every turn player is shown what room they are in and the connecting rooms
        void check_hazards(vector<vector<int>> rooms, int player_location, int pit1, int pit2, int bat1, int bat2, int wumpus); //Start of every turn player is shown hazards in connecting rooms
    };

    class wumpus: public cave{
    public:
        void wumpus_start(int &wumpus, vector<vector<int>> rooms);  //%3 chance for wumpus to move every turn
        void wumpus_shoot(int &wumpus, vector<vector<int>> rooms);  //If arrow goes in room next to wumpus 20% chance to move
        void check(int player_location, int wumpus, bool &game_set);    //Check if player was killed by wumpus & Also my attempt at polymorphism
    };

    class bats: public cave{
    public:
        void check(int &player_location, int bat1, int bat2, int pit1, int pit2, int wumpus);   //Checks if player was moved by bat if if they were moves player to safe room & Also my attempt at polymorphism
    };

    class pits: public cave{
    public:
        void check(int player_location, int pit1, int pit2, bool &game_set);    //Checks if player entered room with a pit then a 40% chance to kill the player & Also my attempt at polymorphism
    };

    class player: public cave{
    public:

        void move(string command, int &player_location, vector<vector<int>> rooms); //Move command that checks move is legal or if the player walks into a wall
        void shoot(string command, int player_location, int wumpus, vector<vector<int>> rooms, int &arrows, bool &close, bool &game_set);  //Shoot command that checks shot, close call, and updates game status if wumpus is killed
        void check(int arrows, bool &game_set); //Checks if player is out of arrows & Also my attempt at polymorphism
    };
    //Need a way to print instructions for new players
    void instructions();

    //Need a command to show locations of things
    void debug(vector<vector<int>> rooms, int pit1, int pit2, int bat1, int bat2, int wumpus, int arrows);

}
#endif //PROJECT_II_GAME_H
