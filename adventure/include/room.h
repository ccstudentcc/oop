#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>

class Room {
private:
    std::string name;
    std::map<std::string, Room*> exits;
    std::string description;
    bool hasPrincess;
    bool hasMonster;

public:
    Room(const std::string& name, const std::string& description);
    void addExit(const std::string& direction, Room* room);
    Room* getExit(const std::string& direction);
    void setPrincess(bool value);
    void setMonster(bool value);
    bool isPrincessRoom() const;
    bool isMonsterRoom() const;
    void describe() const;
    std::string getName() const;
};

#endif
