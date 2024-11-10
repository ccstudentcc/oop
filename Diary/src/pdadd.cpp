// pdadd.cpp
#include "diary.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Check for required date argument
    if (argc < 2) {
        std::cerr << "Usage: pdadd <date>" << std::endl;
        return 1;
    }

    std::string date = argv[1]; // Date for the diary entry
    std::string content, line;

    // Prompt user to enter diary content, ending with '.' on a new line
    std::cout << "Enter diary content (end with '.' on a new line):" << std::endl;
    while (std::getline(std::cin, line) && line != ".") {
        content += line + "\n"; // Accumulate lines of input into content
    }

    // Create Diary instance and add entry
    Diary diary("../data/diary.txt");
    diary.addEntry(date, content);

    return 0; // Successful completion
}
