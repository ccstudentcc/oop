#include "../include/player.h"
#include "../include/room.h"
#include "../include/init.h"
#include <vector>
#include <cstdlib>  // For rand()

// Game Initialization
void initializeGame(Player& player, std::vector<Room*>& rooms, Room*& lobby, int princessRoomIndex, int monsterRoomIndex) {
    // Create rooms
    lobby = new Room("Lobby", "This is the starting room.");
    Room* hall = new Room("Hall", "This is a grand hall.");
    Room* library = new Room("Library", "Books line the shelves from floor to ceiling, and the smell of old parchment fills the air.");
    Room* diningRoom = new Room("Dining Room", "An elegant dining room with a long table set for a feast, adorned with silverware and candles.");
    Room* basement = new Room("Basement", "The basement is cool and dark, with shelves full of jars and strange equipment scattered about.");
    Room* balcony = new Room("Balcony", "A charming balcony overlooking the garden, where one can enjoy a beautiful view of the surroundings.");
    Room* storageRoom = new Room("Storage Room", "A cluttered storage room filled with boxes and old furniture, perfect for hiding secrets.");
    Room* mysticalChamber = new Room("Mystical Chamber", "A mysterious room filled with glowing crystals and ancient runes, where magic seems to linger in the air.");

    // Connect rooms
    lobby->addExit("east", hall);
    hall->addExit("west", lobby);
    hall->addExit("south", library);
    library->addExit("north", hall);
    library->addExit("down", basement);
    basement->addExit("up", library);
    hall->addExit("up", balcony);
    balcony->addExit("down", hall);
    lobby->addExit("north", diningRoom);
    diningRoom->addExit("south", lobby);
    hall->addExit("north", storageRoom);
    storageRoom->addExit("south", hall);
    storageRoom->addExit("west", diningRoom);
    diningRoom->addExit("east", storageRoom);
    lobby->addExit("west", mysticalChamber);
    mysticalChamber->addExit("east", lobby);

    // Add rooms to the list
    rooms = {lobby, hall, library, diningRoom, basement, storageRoom, mysticalChamber};

    // Manually set princess and monster if specified
    if (princessRoomIndex == -1) {
        do {
            princessRoomIndex = rand() % rooms.size();
        } while (princessRoomIndex == 0);  // Ensure princess is not in the lobby
    }
    if (monsterRoomIndex == -1) {
        do {
            monsterRoomIndex = rand() % rooms.size();
        } while (monsterRoomIndex == princessRoomIndex || monsterRoomIndex == 0);  // Ensure the monster is not in the lobby or princess room
    }

    rooms[princessRoomIndex]->setPrincess(true);
    rooms[monsterRoomIndex]->setMonster(true);

    // Start the player in the lobby
    player = Player(lobby);
    lobby->describe();
}