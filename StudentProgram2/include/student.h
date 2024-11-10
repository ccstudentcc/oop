#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <map>

struct Student {
    std::string name; 
    std::map<std::string, int> scores; 
    float average; 
};

void calculateAverages(std::vector<Student>& students);
int getMaxNameLength(const std::vector<Student>& students);
void printSummary(const std::vector<Student>& students);
void calculateCourseStats(const std::vector<Student>& students);
void readFromFile(std::vector<Student>* students);
void inputManually(std::vector<Student>* students);

#endif // STUDENT_H
