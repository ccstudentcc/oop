// student.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "..\include\student.h"
#include "..\include\utils.h"

using namespace std;

void calculateAverages(vector<Student>& students) {
    for (auto& student : students) {
        int totalScore = 0;
        int courseCount = 0;
        for (const auto& entry : student.scores) {
            totalScore += entry.second;
            courseCount++;
        }
        student.average = (courseCount > 0) ? static_cast<float>(totalScore) / courseCount : 0.0f;
    }
}

int getMaxNameLength(const vector<Student>& students) {
    int maxLength = 0; 

    for (const auto& student : students) {
        int length = student.name.length(); 
        if (length > maxLength) {
            maxLength = length; 
        }
    }

    return maxLength; 
}

void printSummary(const vector<Student>& students) {
    cout << setiosflags(ios::left);
    int maxlen_name = getMaxNameLength(students);
    cout << setw(8) << "no" << setw(max(maxlen_name+1, 8)) << "name"; // Adjust the length according to the student name

    // Print course headers
    set<string> courses;
    for (const auto& student : students) {
        for (const auto& entry : student.scores) {
            courses.insert(entry.first);
        }
    }

    vector<string> courseList(courses.begin(), courses.end());
    for (const auto& course : courseList) {
        cout << setw(max(course.length()+1, (size_t)8)) << course; // Adjust the length according to the course name
    }
    cout << setw(8) << "average" << endl;

    // Print each student's scores
    for (size_t i = 0; i < students.size(); ++i) {
        const auto& student = students[i];
        cout << setw(8) << (i + 1) << setw(maxlen_name+1) << student.name;

        for (const auto& course : courseList) {
            auto scoreIt = student.scores.find(course);
            if (scoreIt != student.scores.end()) {
                cout << setw(max(course.length()+1, (size_t)8)) << scoreIt->second; 
            } else {
                cout << setw(max(course.length()+1, (size_t)8)) << "-"; // Placeholder for missing scores
            }
        }
        cout << setw(8) << formatNumber(student.average) << endl;
    }
}

void calculateCourseStats(const vector<Student>& students) {
    map<string, int> minScores;
    map<string, int> maxScores;
    map<string, float> courseAvg;
    map<string, int> courseCount;
    int maxlen_name = getMaxNameLength(students);

    for (const auto& student : students) {
        for (const auto& entry : student.scores) {
            const string& course = entry.first;
            int score = entry.second;

            // Update minimum and maximum scores
            if (minScores.find(course) == minScores.end() || score < minScores[course]) {
                minScores[course] = score;
            }
            if (maxScores.find(course) == maxScores.end() || score > maxScores[course]) {
                maxScores[course] = score;
            }

            // Update average calculations
            courseAvg[course] += score;
            courseCount[course]++;
        }
    }

    // Print average, min, and max for each course
    cout << setiosflags(ios::left);
    cout << "\t" << setw(maxlen_name+1) << "average";
    for (const auto& course : courseAvg) {
        cout << setw(max(course.first.length()+1, (size_t)8))  << (course.second / courseCount[course.first]); // Adjust the length according to the course name
    }
    cout << endl;

    cout << "\t" << setw(maxlen_name+1) << "min";
    for (const auto& course : minScores) {
        cout << setw(max(course.first.length()+1, (size_t)8)) << course.second;
    }
    cout << endl;

    cout << "\t" << setw(maxlen_name+1) << "max";
    for (const auto& course : maxScores) {
        cout << setw(max(course.first.length()+1, (size_t)8)) << course.second; 
    }
    cout << endl;
}

void readFromFile(vector<Student>* students) {
    // Open the file for reading student data
    ifstream file("../data/student_data.txt");
    string line;

    // Check if the file opened successfully
    if (!file) {
        cerr << "Error opening file\n"; // Output error message if the file cannot be opened
        return;
    }

    // Loop through each line in the file
    while (getline(file, line)) {
        Student student; // Create a new Student object
        student.name = line; // The first line is the student's name

        string courseName; // Variable to hold the course name
        int score; // Variable to hold the course score

        // Read course scores until "done" is encountered
        while (getline(file, line) && line != "done") {
            size_t spacePos = line.find(' '); // Find the position of the space
            if (spacePos != string::npos) { // Ensure there is a space in the line
                courseName = line.substr(0, spacePos); // Extract the course name
                score = stoi(line.substr(spacePos + 1)); // Extract the score and convert it to an integer
                student.scores[courseName] = score; // Store the course and its score in the student's scores map
            }
        }

        // Add the populated Student object to the vector of students
        students->push_back(student);
    }

    // Close the file after reading
    file.close();
}


void inputManually(std::vector<Student>* students){
    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;
    cin.ignore(); // To ignore the newline character after the integer input

    for (int i = 0; i < studentCount; ++i) {
        Student student;
        cout << "Enter name for student " << (i + 1) << ": ";
        getline(cin, student.name); // Use getline to allow spaces in names

        string courseName;
        int score;

        cout << "Enter course scores (format: <course_name> <score>, type 'done' when finished):\n";
        while (true) {
            cout << "> ";
            cin >> courseName;
            if (courseName == "done") break;

            cin >> score;
            student.scores[courseName] = score;
        }

        students->push_back(student);
        cin.ignore(); // Clear the newline character before the next iteration
    }
}
