// utils.cpp
#include <sstream>   
#include <iomanip>   
#include <string>    

using namespace std;

// Formats a number to a string with up to 5 decimal places.
// It also removes trailing zeros and any unnecessary decimal point.
string formatNumber(double num) {
    stringstream ss; // Create a stringstream to build the output string
    ss << fixed << setprecision(5) << num; // Set fixed format and precision
    string str = ss.str(); // Convert the number to string

    // Remove trailing zeros and possible decimal point
    str.erase(str.find_last_not_of('0') + 1, string::npos); // Erase trailing zeros
    if (str.back() == '.') str.pop_back(); // Remove trailing decimal point if present
    
    return str; // Return the formatted string
}
