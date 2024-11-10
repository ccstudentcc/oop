#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include "..\include\student.h"
#include "..\include\utils.h"

using namespace std;

void PrintRecord(const vector<Student>& students){
    // format output
    cout << resetiosflags(ios::showpoint) << setiosflags(ios::fixed) << setprecision(5) << setiosflags(ios::left);
    cout << setw(8) << "no" << setw(8) << "name" << setw(8) << "score1" << setw(8) << "score2" << setw(8) << "score3" << setw(8) <<  "average" << endl;

    for(size_t i = 0; i < students.size(); i++){
        cout << setw(8) << i + 1 << setw(8) << students[i].name << setw(8) << students[i].scores[0] << setw(8) 
             << students[i].scores[1] << setw(8) << students[i].scores[2] << setw(8) << FormatNumber(Average(students[i].scores)) << endl;
    }
}

void CalculateAverageMinMax(const vector<Student>& students){
    // data processing
    vector<vector<int>> score(3, vector<int>(students.size()));
    for(size_t i = 0; i < students.size(); i++){
        score[0][i] = students[i].scores[0];
        score[1][i] = students[i].scores[1];
        score[2][i] = students[i].scores[2];
    }

    // format output
    cout << resetiosflags(ios::showpoint) << setiosflags(ios::fixed) << setprecision(5) << setiosflags(ios::left);
    cout << "\t" << setw(8) << "average" << setw(8) << FormatNumber(Average(score[0])) << setw(8) << FormatNumber(Average(score[1])) << setw(8) << FormatNumber(Average(score[2])) << endl;
    cout << "\t" << setw(8) << "min" << setw(8) << min(score[0]) << setw(8) << min(score[1]) << setw(8) << min(score[2]) << endl;
    cout << "\t" << setw(8) << "max" << setw(8) << max(score[0]) << setw(8) << max(score[1]) << setw(8) << max(score[2]) << endl;
}

void ReadFromFile(vector<Student>* students) {
    ifstream file("../data/student_data.txt");
    string line;

    if (!file) {
        cerr << "Error opening file\n";
        return;
    }

    for (size_t i = 0; i < students->size(); i++) {
        (*students)[i].scores.resize(3);
        getline(file, line);
        istringstream iss(line);
        iss >> (*students)[i].name >> (*students)[i].scores[0] >> (*students)[i].scores[1] >> (*students)[i].scores[2];
    }

    file.close();
}

void InputManually(vector<Student>* students) {
    cout << "Enter student data in the format 'Name Score1 Score2 Score3' for 10 times:\n";
    for (size_t i = 0; i < students->size(); i++) {
        (*students)[i].scores.resize(3);
        string line;
        getline(cin, line);
        istringstream iss(line);
        iss >> (*students)[i].name >> (*students)[i].scores[0] >> (*students)[i].scores[1] >> (*students)[i].scores[2];
    }
}