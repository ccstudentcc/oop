// pdlist.cpp
#include "diary.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::string startDate, endDate;

    // Optional arguments for date range
    if (argc > 1) {
        startDate = argv[1];
    }
    if (argc > 2) {
        endDate = argv[2];
    }

    // Create Diary instance and list entries within date range
    Diary diary("diary.txt");
    diary.listEntries(startDate, endDate);

    return 0; // Successful completion
}
