#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>
#include "..\include\utils.h"

using namespace std;

template<typename T>
double Average(const vector<T>& v){
    if (v.empty()) {
        return 0;
    }
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

template<typename T>
T max(const vector<T>& v){
    if (v.empty()) {
        return -1;
    }
    return *max_element(v.begin(), v.end());
}

template<typename T>
T min(const vector<T>& v){
    if (v.empty()) {
        return -1;
    }
    return *min_element(v.begin(), v.end());
}

string FormatNumber(double num) {
    stringstream ss;
    ss << fixed << setprecision(5) << num;
    string str = ss.str();
    // Remove trailing zeros and possible decimal point
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') str.pop_back(); // Remove trailing decimal point if present
    return str;
}

// Explicit instantiation of template functions
template double Average(const vector<int>& v);
template int max(const vector<int>& v);
template int min(const vector<int>& v);
