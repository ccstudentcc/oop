#include <gtest/gtest.h>
#include "../include/player.h"
#include "../include/room.h"
#include "../include/init.h"

// Test for checking room exits
TEST(RoomTest, Exits) {
    Room lobby("Lobby", "A central room");
    Room hall("Hall", "A grand hall");
    lobby.addExit("east", &hall);
    hall.addExit("west", &lobby);

    EXPECT_EQ(lobby.getExit("east"), &hall);
    EXPECT_EQ(hall.getExit("west"), &lobby);
}


// Test for initializing the game with princess and monster
TEST(GameTest, PrincessAndMonster) {
    std::vector<Room*> rooms;  
    Room* lobby = nullptr;
    Player player(nullptr);

    // Manually set princess in room 1 (hall) and monster in room 2 (library)
    initializeGame(player, rooms, lobby, 1, 2);

    // Ensure that princess is in hall and monster is in library
    EXPECT_TRUE(rooms[1]->isPrincessRoom());
    EXPECT_TRUE(rooms[2]->isMonsterRoom());
}

// Test for winning condition by finding the princess
TEST(GameTest, WinCondition) {
    std::vector<Room*> rooms;  // Assuming there are at least 3 rooms
    Room* lobby = nullptr;
    Player player(nullptr);

    // Manually set princess in room 1 (hall)
    initializeGame(player, rooms, lobby, 1, -1);

    // Player finds princess and returns to the lobby
    player.move("east");  // Assuming east leads to the hall where the princess is
    EXPECT_TRUE(player.hasFoundPrincess());
    player.move("west");   // Move back to the lobby
    EXPECT_EQ(player.getCurrentRoom(), lobby);
}

// Test for player movement between rooms
TEST(PlayerTest, Move) {
    Room lobby("Lobby", "A central room");
    Room hall("Hall", "A grand hall");
    lobby.addExit("east", &hall);
    hall.addExit("west", &lobby);

    Player player(&lobby);
    player.move("east");
    EXPECT_EQ(player.getCurrentRoom(), &hall);

    player.move("west");
    EXPECT_EQ(player.getCurrentRoom(), &lobby);
}

// Test for invalid move
TEST(PlayerTest, InvalidMove) {
    Room lobby("Lobby", "A central room");
    Room hall("Hall", "A grand hall");
    lobby.addExit("east", &hall);
    hall.addExit("west", &lobby);

    Player player(&lobby);
    player.move("north"); // Invalid direction

    EXPECT_EQ(player.getCurrentRoom(), &lobby); // Should still be in the lobby
}

// Test for finding the princess multiple times
TEST(PlayerTest, FindPrincessTwice) {
    Room lobby("Lobby", "A central room");
    Room hall("Hall", "A grand hall");
    Room balcony("Balcony", "You can see garden from here");
    
    lobby.addExit("east", &hall);
    hall.addExit("west", &lobby);
    hall.addExit("east", &balcony);
    balcony.addExit("west", &hall);

    Player player(&lobby);
    hall.setPrincess(true); // Setting princess in the hall

    player.move("east");
    EXPECT_TRUE(player.hasFoundPrincess());

    // Simulate trying to find the princess again
    player.move("east"); // for test
    player.move("west"); // Move back to the hall

    EXPECT_TRUE(player.hasFoundPrincess()); // Should still indicate the princess was found
}

// Test for encountering a monster
TEST(PlayerTest, EncounterMonster) {
    Room lobby("Lobby", "A central room");
    Room hall("Hall", "A grand hall");
    Room library("Library", "A dark library");
    
    lobby.addExit("east", &hall);
    hall.addExit("west", &lobby);
    hall.addExit("north", &library); // Adding north exit to library
    library.addExit("south", &hall);
    

    library.setMonster(true); // Setting monster in the library

    Player player(&lobby);
    player.move("east"); // Move to hall
    player.move("north"); // Move to library

    // Player should encounter the monster and the program should exit
    EXPECT_EXIT(player.move("north"), ::testing::ExitedWithCode(0), "You encounters the monster. The monster kills you. You are dead!");
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }