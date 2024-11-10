#ifndef INIT_H
#define INIT_H
#include "../include/player.h"
#include "../include/room.h"
#include <vector>

void initializeGame(Player& player, std::vector<Room*>& rooms, Room*& lobby, int princessRoomIndex = -1, int monsterRoomIndex = -1);
#endif
