#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

struct Student {
    std::string name;
    std::vector<int> scores;
};

void PrintRecord(const std::vector<Student>& students);
void CalculateAverageMinMax(const std::vector<Student>& students);
void ReadFromFile(std::vector<Student>* students);
void InputManually(std::vector<Student>* students);


#endif // STUDENT_H
