#include "..\include\player.h"
#include <iostream>

Player::Player(Room* startingRoom) : currentRoom(startingRoom), hasPrincess(false) {}

// the movement of the player
void Player::move(const std::string& direction) {
    Room* nextRoom = currentRoom->getExit(direction);
    if (nextRoom) {
        currentRoom = nextRoom;
        currentRoom->describe();

        if (currentRoom->isMonsterRoom()) {
            std::cout << "You encounters the monster. The monster kills you. You are dead!\n";
            exit(0);
        }
        else if (currentRoom->isPrincessRoom() && !hasPrincess) {
            std::cout << "You find the princess.\n";
            std::cout << "Princess: \"I'm so grateful you've come for me! Please help me get out of here!\"\n";
            std::cout << "You: \"Fear not, princess! I will protect you and lead you to freedom!\"\n";
            hasPrincess = true;
            currentRoom->setPrincess(false);
        }
    }
    else {
        std::cout << "There's no exit in that direction.\n";
    }
}

// whether the player have found the princess
bool Player::hasFoundPrincess() const {
    return hasPrincess;
}

// the player's current position
Room* Player::getCurrentRoom() const {
    return currentRoom;
}
