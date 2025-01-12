// Fraction.h
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <sstream>
#include <numeric>

class Fraction {
private:
    int numerator;   // Numerator
    int denominator; // Denominator

    void simplify(); // Simplify the fraction

public:
    // Default constructor
    Fraction();

    // Constructor with two integer parameters
    explicit Fraction(int num, int den);

    // Construct fraction from decimal string
    explicit Fraction(const std::string& decimal);

    // Copy constructor
    Fraction(const Fraction& other);

    // Arithmetic operator overloads
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Comparison operator overloads
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;

    // Type conversion operator
    explicit operator double() const;

    // Return string representation
    std::string toString() const;

    // Input/output stream operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);

    // Delete constructors that take non-int types to prevent accidental implicit conversions
    template<typename T1, typename T2>
    Fraction(T1, T2) = delete;
};

#endif // FRACTION_H