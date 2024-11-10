#include "..\include\room.h"
#include <iostream>

// construct the rooms
Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description), hasPrincess(false), hasMonster(false) {}

// add exits to the room
void Room::addExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

// get the exit of the chosen direction
Room* Room::getExit(const std::string& direction) {
    if (exits.find(direction) != exits.end()) {
        return exits[direction];
    }
    return nullptr;
}

void Room::setPrincess(bool value) {
    hasPrincess = value;
}

void Room::setMonster(bool value) {
    hasMonster = value;
}

// judge whether the room is the princess room or not
bool Room::isPrincessRoom() const {
    return hasPrincess;
}

// judge whether the room is the monster room or not
bool Room::isMonsterRoom() const {
    return hasMonster;
}

// give basic information of the room and its exits.
void Room::describe() const {
    std::cout << "Welcome to the " << name << ". " << description << "\n";
    if(exits.size() > 1){
        std::cout << "There are " << exits.size() << " exits: ";
    }
    else {
        std::cout << "There is " << exits.size() << " exit: ";
    }
    
    for (const auto& exit : exits) {
        std::cout << exit.first << " ";
    }
    std::cout << "\n";
}

// get the name of the room
std::string Room::getName() const {
    return name;
}
