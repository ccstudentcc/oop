#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "..\include\student.h"

using namespace std;

int main() {
    vector<Student> students(10);
    int choice;

    cout << "Choose an option:\n";
    cout << "1. Read from file\n";
    cout << "2. Enter manually\n";
    cin >> choice;
    cin.ignore(); // Ignore the newline character left in the buffer

    if (choice == 1) {
        ReadFromFile(&students);
    } else if (choice == 2) {
        InputManually(&students);
    } else {
        cerr << "Invalid choice\n";
        return 1;
    }

    // print data in required form
    PrintRecord(students);
    CalculateAverageMinMax(students);

    system("pause");
    
    return 0;
}
