#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>
#include <map>
#include <set>
#include "..\include\student.h"

using namespace std;

int main() {
    vector<Student> students;
    int choice;

    cout << "Choose an option:\n";
    cout << "1. Read from file\n";
    cout << "2. Enter manually\n";
    cin >> choice;
    cin.ignore(); // Ignore the newline character left in the buffer

    if (choice == 1) {
        readFromFile(&students);
    } else if (choice == 2) {
        inputManually(&students);
    } else {
        cerr << "Invalid choice\n";
        return 1;
    }

    // print data in required form
    calculateAverages(students);
    printSummary(students);
    calculateCourseStats(students);
    system("pause");

    return 0;
}
