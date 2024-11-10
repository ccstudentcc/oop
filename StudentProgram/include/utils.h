#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

template<typename T>
double Average(const std::vector<T>& v);

template<typename T>
T max(const std::vector<T>& v);

template<typename T>
T min(const std::vector<T>& v);

std::string FormatNumber(double num);


#endif // UTILS_H
