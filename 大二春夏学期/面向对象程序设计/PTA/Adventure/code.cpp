/*
* Author: Xuanming, Liu
* Usage:
* This program is a CLI advantrue game,
* When the game starts, the player is in the lobby of the castle. 
* Then the program shows information about the lobby：
* name of the room, how many exits are there, and names of all exits.
* The player then can input "go" followed by the name of one exit to enter the room connected to that door.
* Once the player enters a room with a monster, 
* the program shows a message and game over. 
* Once the player enters the room of princess, 
* the program shows a message about the princess, 
* and the princess is going to leave with the player. 
* The player then has to find their way out the castle. 
* The only way to leave the castle is via the lobby.
* There are at least three different kinds of rooms,
* and at least five rooms,
* Latest revised: 2020.03.27             
*/

#ifndef _ADV_H
#define _ADV_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

#define ROOM_TYPE 7

// define the Room class
class Room{
private:
    int roomId;
    int exitNum;
    int roomType[ROOM_TYPE];

public:
    bool princess, monster;
    
    Room(int idx);
    void getRoomType();
    void getMonsterAndPrincess();
    // The monster and princess is randomly processed in the game.
    void printInfo();
    int* retRoomType();
    int  retExitNum();
    int  retRoomId();
};

#endif

int getChoice(string msg1, string msg2, Room* room);
int choice;

// There are six types of exits.
string ExitTypes[] = {"NULL", "east", "up", "north", "south",  "down", "west"};
// Some flags to control the game.
int isMonsterSelected, isPrincessSelected, isPrincessSaved;

int main()
{
    // Random seed
    srand((int)time(NULL));
    vector<Room*> rooms;
    vector<int> choices;
    string go, exit;
    int roomIdx = 1;
    int gameWin = 1;
    choice = isMonsterSelected = isPrincessSelected = isPrincessSaved = 0;

    // The game begin here.
    cout << "Welcome to the Adventure!" << endl << "Enjoy your time!" << endl;
        
    // At first the player is in the lobby,
    // output the information about the lobby.
    Room* hobby = new Room(0);
    hobby->printInfo();
    // Input at the first time( in lobby ).
    cin >> go >> exit;
    // Jugde if the choice and input is legal.
    while(!(choice = getChoice(go, exit, hobby))){
        cout << "Illegal command or there isn't such a exit." << endl;
        hobby->printInfo();
        cin >> go >> exit;
    }
    // push the room and the choice made into a vector.
    rooms.push_back(hobby);
    choices.push_back(choice);

    // Main loop, to make the game continue.
    while(true){
        // A new room is processed.
        Room* room = new Room(roomIdx++);
        rooms.push_back(room);
        // if meet the monster or the princess, jump out.
        // and some flags are changed accroding to the situation.
        if(room->princess){
            cout << "Congraduation! You have found the Princess." << endl;
            cout << "Now please go back in the origin way. Remember if you go to a unknown room, you will be lost!" << endl;
            isPrincessSaved = 1;
            break;
        }
        if(room->monster){
            cout << "Wow! You are beat by the Monster." << endl;
            gameWin = 0;
            break;
        }
        // player input, and go into the other room,
        // almost the same as before in lobby.
        room->printInfo();
        cin >> go >> exit;
        while(!(choice = getChoice(go, exit, room))){
            cout << "Illegal command or there isn't such a exit." << endl;
            room->printInfo();
            cin >> go >> exit;
        }
        choices.push_back(choice);
    }
    // After save the princess
    while(isPrincessSaved){
        // like a stack,
        // pop the last room, and the input must be reverse to before.
        Room* room = rooms.back();
        rooms.pop_back();
        if(rooms.empty())
            break;
        room->printInfo();
        cin >> go >> exit;
        while(!(choice = getChoice(go, exit, room))){
            cout << "Illegal command or there isn't such a exit." << endl;
            room->printInfo();
            cin >> go >> exit;
        }
        // judge if the input is reversely.
        // like at the last time we input "go west", now you must input "go east".
        if(choice != (ROOM_TYPE - choices.back())){
            cout << "Wrong way! You are lost in the castle!" << endl;
            gameWin = 0;
            break;
        }
        choices.pop_back();
    }
    // game end.
    if(gameWin){
        cout << "Good job! You win the game." << endl;
        cout << "Now you are in the lobby!" << endl;
    }
    else
        cout << "You lose!" << endl;
    system("PAUSE");
    return 0;
}

int getChoice(string msg1, string msg2, Room* room)
{
    // Using a hash way, to get the index that player input.
    int i;
    int* types;
    if(msg1 == "go"){
        for(i = 0; i < room->retExitNum(); i++){
            types = room->retRoomType();
            if(msg2 == ExitTypes[types[i]])
                return types[i];
        }
        // if not find, return false.
        if(i == room->retExitNum())
            return false;
    } 
    return false;
}

Room::Room(int idx)
{
    roomId = idx;
    getMonsterAndPrincess();
    getRoomType();
}

void Room::getMonsterAndPrincess()
{
    // Randomly set the position that monster and princess in.
    if(roomId == 0)
        return;
    if(isMonsterSelected && isPrincessSelected)
        return;
    if(isMonsterSelected){
        princess = ((rand() % 5) == 0) ? true : false; // 1/5 probability.
        isPrincessSelected = (princess == true ? true : false);
    }
    else if(isPrincessSelected){
        monster = ((rand() % 5) == 0) ? true : false; // 1/5 probability.
        isMonsterSelected = (monster == true ? true : false);
    }
    else{
        princess = ((rand() % 5) == 0) ? true : false; // 1/5 probability.
        if(princess == true){
            isPrincessSelected = true;
            return;
        }
        else {
            monster = ((rand() % 5) == 0) ? true : false;
            if(monster)
                isMonsterSelected = true;
        }
    }
}

void Room::getRoomType()
{
    // Randomly set the exit type.
    // Remember that the first exit is reverse to the last input.
    int type, isSelected;
    exitNum = 0;
    if(choice)
        roomType[exitNum++] = ROOM_TYPE - choice;
    for(int i = 0; i < (ROOM_TYPE - 1); i++ ){
        type = (rand() % (ROOM_TYPE - 1)) + 1;
        isSelected = false;
        for(int j = 0; j < exitNum; j++)
            if(roomType[j] == type){
                isSelected = true;
                break;
            }
        if(!isSelected)
            roomType[exitNum++] = type;
    }
}

void Room::printInfo()
{
    // Print the info about the current room.
    if(!roomId)
        cout << "Welcome to the lobby." ;
    else
        cout << "Welcome to Room " << roomId << "." ;
    cout << "There are " << exitNum << " exits: ";
    for(int i = 0; i < exitNum; i++){
        if(i == 0)
            cout << ExitTypes[roomType[i]];
        else if( i == exitNum - 1 )
            cout << " and " << ExitTypes[roomType[i]];
        else
            cout << ", " << ExitTypes[roomType[i]];
    }
    cout << "." << endl;
    cout << "Enter your command:" << endl;
}

int* Room::retRoomType()
{
    return roomType;
}

int  Room::retExitNum()
{
    return exitNum;
}

int Room::retRoomId()
{
    return roomId;
}