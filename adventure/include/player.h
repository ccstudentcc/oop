#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include <string>

class Player {
private:
    Room* currentRoom;
    bool hasPrincess;

public:
    Player(Room* startingRoom);
    void move(const std::string& direction);
    bool hasFoundPrincess() const;
    Room* getCurrentRoom() const;
};

#endif
