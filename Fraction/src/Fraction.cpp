// Fraction.cpp
#include "..\include\Fraction.h"
#include <cmath>

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

// Constructor that takes two integer parameters
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

// Construct a fraction from a decimal string
Fraction::Fraction(const std::string& decimal) {
    size_t pos = decimal.find('.');
    if (pos != std::string::npos) {
        int decimal_places = decimal.length() - pos - 1;
        int denom = static_cast<int>(std::pow(10, decimal_places));
        int num = static_cast<int>(std::stod(decimal) * denom);
        numerator = num;
        denominator = denom;
    } else {
        numerator = std::stoi(decimal);
        denominator = 1;
    }
    simplify();
}

// Copy constructor
Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

// Simplify the fraction
void Fraction::simplify() {
    int gcd_value = gcd(abs(numerator), abs(denominator));
    numerator /= gcd_value;
    denominator /= gcd_value;
    // Ensure the denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Overload arithmetic operators
Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

// Overload comparison operators
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

// Type conversion operator
Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

// Return string representation
std::string Fraction::toString() const {
    // Always returns "numerator/denominator" format
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Overload output stream operator
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.toString();
    return os;
}

// Overload input stream operator
std::istream& operator>>(std::istream& is, Fraction& frac) {
    int num, den;
    char slash;
    is >> num >> slash >> den;
    if (slash == '/') {
        frac = Fraction(num, den);
    } else {
        is.setstate(std::ios::failbit);
    }
    return is;
}