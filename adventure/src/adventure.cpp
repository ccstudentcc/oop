#include "..\include\room.h"
#include "..\include\player.h"
#include "..\include\init.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


// Main Game Loop
int main() {
    Player player(nullptr);
    std::vector<Room*> rooms;
    Room* lobby; // Reference to the lobby room
    initializeGame(player, rooms, lobby);

    std::string command;
    while (true) {
        std::cout << "Enter your command: ";
        std::getline(std::cin, command);

        if (command.rfind("go", 0) == 0) {
            std::string direction = command.substr(3);
            player.move(direction);

            // Check if the player has the princess and is in the lobby
            if (player.hasFoundPrincess() && player.getCurrentRoom() == lobby) {
                std::cout << "You return to the lobby with the princess. You win!\n";
                break;
            }
        } else {
            std::cout << "Unknown command. Please use 'go <direction>'.\n";
        }
    }

    // Clean up allocated memory for rooms
    for (Room* room : rooms) {
        delete room;
    }

    return 0;
}
