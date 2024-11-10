// pdremove.cpp
#include "diary.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Check for required date argument
    if (argc < 2) {
        std::cerr << "Usage: pdremove <date>" << std::endl;
        return 1;
    }

    std::string date = argv[1]; // Date for the diary entry to be removed
    Diary diary("../data/diary.txt");

    // Try to remove the entry and provide feedback on success or failure
    if (diary.removeEntry(date)) {
        return 0; // Successful removal
    } else {
        std::cerr << "No entry found for " << date << std::endl;
        return -1; // Entry not found
    }
}
