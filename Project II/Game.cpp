//
// Created by jcox1 on 4/7/17.
//

#include "Game.h"

namespace Game {

    void cave::set_rooms(vector<vector<int>> &rooms) {
        vector<int> temp_room;
        for (int i = 0; i < 20; ++i)
            temp_room.push_back(i);

        srand(unsigned(time(0)));
        random_shuffle(temp_room.begin(), temp_room.end());

        rooms.resize(20);
        rooms[0].push_back(temp_room[0]);
        rooms[0].push_back(temp_room[4]);
        rooms[0].push_back(temp_room[7]);
        rooms[0].push_back(temp_room[1]);

        rooms[1].push_back(temp_room[1]);
        rooms[1].push_back(temp_room[0]);
        rooms[1].push_back(temp_room[9]);
        rooms[1].push_back(temp_room[2]);

        rooms[2].push_back(temp_room[2]);
        rooms[2].push_back(temp_room[1]);
        rooms[2].push_back(temp_room[11]);
        rooms[2].push_back(temp_room[3]);

        rooms[3].push_back(temp_room[3]);
        rooms[3].push_back(temp_room[2]);
        rooms[3].push_back(temp_room[13]);
        rooms[3].push_back(temp_room[4]);


        rooms[4].push_back(temp_room[4]);
        rooms[4].push_back(temp_room[0]);
        rooms[4].push_back(temp_room[5]);
        rooms[4].push_back(temp_room[3]);

        rooms[5].push_back(temp_room[5]);
        rooms[5].push_back(temp_room[4]);
        rooms[5].push_back(temp_room[6]);
        rooms[5].push_back(temp_room[14]);

        rooms[6].push_back(temp_room[6]);
        rooms[6].push_back(temp_room[7]);
        rooms[6].push_back(temp_room[16]);
        rooms[6].push_back(temp_room[5]);

        rooms[7].push_back(temp_room[7]);
        rooms[7].push_back(temp_room[0]);
        rooms[7].push_back(temp_room[6]);
        rooms[7].push_back(temp_room[8]);

        rooms[8].push_back(temp_room[8]);
        rooms[8].push_back(temp_room[7]);
        rooms[8].push_back(temp_room[9]);
        rooms[8].push_back(temp_room[17]);

        rooms[9].push_back(temp_room[9]);
        rooms[9].push_back(temp_room[8]);
        rooms[9].push_back(temp_room[1]);
        rooms[9].push_back(temp_room[10]);

        rooms[10].push_back(temp_room[10]);
        rooms[10].push_back(temp_room[9]);
        rooms[10].push_back(temp_room[11]);
        rooms[10].push_back(temp_room[18]);

        rooms[11].push_back(temp_room[11]);
        rooms[11].push_back(temp_room[2]);
        rooms[11].push_back(temp_room[10]);
        rooms[11].push_back(temp_room[12]);

        rooms[12].push_back(temp_room[12]);
        rooms[12].push_back(temp_room[11]);
        rooms[12].push_back(temp_room[19]);
        rooms[12].push_back(temp_room[13]);

        rooms[13].push_back(temp_room[13]);
        rooms[13].push_back(temp_room[3]);
        rooms[13].push_back(temp_room[12]);
        rooms[13].push_back(temp_room[14]);

        rooms[14].push_back(temp_room[14]);
        rooms[14].push_back(temp_room[13]);
        rooms[14].push_back(temp_room[15]);
        rooms[14].push_back(temp_room[5]);

        rooms[15].push_back(temp_room[15]);
        rooms[15].push_back(temp_room[14]);
        rooms[15].push_back(temp_room[16]);
        rooms[15].push_back(temp_room[19]);

        rooms[16].push_back(temp_room[16]);
        rooms[16].push_back(temp_room[6]);
        rooms[16].push_back(temp_room[15]);
        rooms[16].push_back(temp_room[17]);

        rooms[17].push_back(temp_room[17]);
        rooms[17].push_back(temp_room[8]);
        rooms[17].push_back(temp_room[16]);
        rooms[17].push_back(temp_room[18]);

        rooms[18].push_back(temp_room[18]);
        rooms[18].push_back(temp_room[10]);
        rooms[18].push_back(temp_room[17]);
        rooms[18].push_back(temp_room[19]);

        rooms[19].push_back(temp_room[19]);
        rooms[19].push_back(temp_room[12]);
        rooms[19].push_back(temp_room[15]);
        rooms[19].push_back(temp_room[18]);
    }

    void cave::set_chars(int &player_location, int &pit1, int &pit2, int &bat1, int &bat2, int &wumpus){
        vector<int> temp_room;
        for (int i = 0; i < 20; ++i)
            temp_room.push_back(i);

        srand(unsigned(time(0)));
        random_shuffle(temp_room.begin(), temp_room.end());

        player_location = temp_room[0];
        pit1 = temp_room[2];
        pit2 = temp_room[4];
        bat1 = temp_room[12];
        bat2 = temp_room[15];
        wumpus = temp_room[19];
    }

    void cave::room_con(vector<vector<int>> rooms, int player_location){
        cout << "You are in room number " << player_location << endl;
        for (int i = 0; i < rooms.size(); ++i){
            if(player_location == rooms[i][0]){
                cout << "Connecting rooms are " << rooms[i][1] << " , " << rooms[i][2] << " , " << rooms[i][3] << endl;
            }
        }
    }

    void cave::check_hazards(vector<vector<int>> rooms, int player_location, int pit1, int pit2, int bat1, int bat2, int wumpus){
        for(int i = 0; i <rooms.size(); ++i){
            if(player_location == rooms[i][0]){
                if(pit1 == rooms[i][1] or pit1 == rooms[i][2] or pit1 == rooms[i][3] or pit2 == rooms[i][1] or pit2 == rooms[i][2] or pit2 == rooms[i][3])
                    cout << "I feel a breeze" << endl;
                if (bat1 == rooms[i][1] or bat1 == rooms[i][2] or bat1 == rooms[i][3] or bat2 == rooms[i][1] or bat2 == rooms[i][2] or bat2 == rooms[i][3])
                    cout << "I hear a bat" << endl;
                if (wumpus == rooms[i][1] or wumpus == rooms[i][2] or wumpus == rooms[i][3])
                    cout << "I smell a wumpus" << endl;
            }

        }
        cout << endl;
    }

    void player::move(string command, int &player_location, vector<vector<int>> rooms) {
        command.erase(command.begin());
        int move = stoi(command);
        bool check_room = true;
        for (int i=0; i<rooms.size(); ++i){
            if(player_location==rooms[i][0]){
                if (move!=rooms[i][1] and move!=rooms[i][2] and move!=rooms[i][3]) {
                    cout << "You walked into a wall and are still in the same room" << endl;
                    check_room=false;
                }
            }
        }
        if(check_room==true)
            player_location=move;
    }

    void player::shoot(string command, int player_location, int wumpus, vector<vector<int>> rooms, int &arrows, bool &close, bool &game_set) {
        command.erase(command.begin());
        command.insert(command.begin()+command.find('-'),' ');
        command.erase(command.begin()+command.find('-'));
        command.insert(command.begin()+command.find('-'),' ');
        command.erase(command.begin()+command.find('-'));
        istringstream iss(command);
        vector<int> arrow_path;
        int buff;
        int path_check=player_location;
        while (iss>>buff)
            arrow_path.push_back(buff);
        bool check_room=true;
        for(int j=0; j<arrow_path.size(); ++j) {
            if(check_room==true) {
                for (int i = 0; i < rooms.size(); ++i) {    //Check to make sure the room is connected
                    if (path_check == rooms[i][0]) {
                        if (arrow_path[j] != rooms[i][1] and arrow_path[j] != rooms[i][2] and arrow_path[j] != rooms[i][3]) {
                            cout << "Your arrow hit a wall" << endl;
                            check_room = false;
                        }
                    }
                }
                for (int i = 0; i < rooms.size(); ++i) {    //Check if wumpus moves
                    if (path_check == rooms[i][0]) {
                        if (wumpus == rooms[i][1] or wumpus == rooms[i][2] or wumpus== rooms[i][3]) {
                            close = false;
                        }
                    }
                }
                if (check_room == true) {       //Check if the wumpus was shot and killed
                    path_check = arrow_path[j];
                    if (path_check == wumpus) {
                        cout << "You killed the wumpus!" << endl;
                        game_set = false;
                    }
                }
            }
        }
        arrows= arrows-1;
    }

    void player::check(int arrows, bool &game_set){
        if (arrows == 0) {
            cout << "You ran out of arrows. The wumpus found you and killed you" << endl;
            game_set = false;
        }
    }

    void wumpus::wumpus_start(int &wumpus, vector<vector<int>> rooms){
        srand(unsigned(time(0)));
        int chance = rand()%100; //Select a number between 0 and 99
        if(chance==25 or chance==50 or chance==75){ //3% = 3 random numbers from a pool of 100
            for(int i=0; i<rooms.size(); ++i){
                if(wumpus==rooms[i][0]) {
                    int j = rand() % 2 + 1;
                    wumpus = rooms[i][j];
                }
            }
        }
    }

    void wumpus::wumpus_shoot(int &wumpus, vector<vector<int>> rooms){
        srand(unsigned(time(0)));
        int chance = rand()%5; //Select a number between 0 and 4
        if(chance==2){ //20% = 1 random number from a pool of 5
            for(int i=0; i<rooms.size(); ++i){
                if(wumpus==rooms[i][0]) {
                    int j = rand() % 2 + 1;
                    wumpus = rooms[i][j];
                }
            }
        }
    }
    void wumpus::check(int player_location, int wumpus, bool &game_set){
        if(player_location==wumpus) {
            cout << "You were killed by the wumpus!" << endl;
            game_set = false;
        }
    }

    void pits::check(int player_location, int pit1, int pit2, bool &game_set){
        if (player_location== pit1 or player_location==pit2){
            srand(unsigned(time(0)));
            int chance = rand()%10; //Select a number between 0-9
            if(chance==2 or chance==4 or chance==6 or chance==8) { //40% = 4 random numbers from a pool of 10
                cout << "You fell to your death" << endl;
                game_set = false;
            }
        }
    }

    void bats::check(int &player_location, int bat1, int bat2, int pit1, int pit2, int wumpus){
        if(player_location==bat1 or player_location==bat2){
            vector<int> temp;
            for(int i=0; i<20; ++i){
                if(i!=bat1 and i!=bat2 and i!=pit1 and i!=pit2 and i!=wumpus)
                    temp.push_back(i);
            }
            srand(unsigned(time(0)));
            int chance=rand()%temp.size();
            player_location=temp[chance];
            cout << "A bat moved you!" << endl;
        }

    }

    void instructions() {
        cout << "At the begining of each turn you can move or shoot." << endl <<
             "To move type: m# where # is the room number you want to move into." << endl <<
             "To shoot type: s#-#-# where # is 3 connecting rooms you are shooting into." << endl <<
             "To reveal the map type 'debug'" << endl;
        cout << endl;
    }

    void debug(vector<vector<int>> rooms, int pit1, int pit2, int bat1, int bat2, int wumpus, int arrows) {
        for(int i=0; i<rooms.size(); ++i){
            cout<< "Room number " << rooms[i][0] << " is connected to rooms: " << rooms[i][1] << " , " << rooms[i][2] << " , " << rooms[i][3] << endl;
        }
        cout << "Pits are in rooms " << pit1 << " , " << pit2 << endl;
        cout << "Bats are in rooms " << bat1 << " , " << bat2 << endl;
        cout << "The wumpus is in room " << wumpus << endl;
        cout << "Player has " << arrows << " arrows" << endl;
        cout << endl;
    }
}