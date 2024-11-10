// pdshow.cpp
#include "diary.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Check for required date argument
    if (argc < 2) {
        std::cerr << "Usage: pdshow <date>" << std::endl;
        return 1;
    }

    std::string date = argv[1]; // Date for the diary entry
    Diary diary("data/diary.txt");
    std::string entry = diary.getEntry(date);

    // Check if entry exists and display it, or show an error
    if (entry.empty()) {
        std::cerr << "No entry found for " << date << std::endl;
        return -1;
    } else {
        std::cout << entry << std::endl;
    }

    return 0; // Successful completion
}
