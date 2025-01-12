// test.cpp
#include "..\include\Fraction.h"
#include <iostream>
#include <cassert>
#include <limits>
#include <sstream>

int main()
{
    // Test default constructor
    Fraction f1;
    std::cout << "Testing default constructor: f1 = " << f1 << " (Expected: 0/1)" << std::endl;
    assert(f1.toString() == "0/1");

    // Test constructor accepting two integers
    Fraction f2(3, 4);
    std::cout << "Testing constructor(3, 4): f2 = " << f2 << " (Expected: 3/4)" << std::endl;
    assert(f2.toString() == "3/4");

    // Test copy constructor
    Fraction f3(f2);
    std::cout << "Testing copy constructor: f3 = " << f3 << " (Expected: 3/4)" << std::endl;
    assert(f3.toString() == "3/4");

    // Test constructing a fraction from a decimal string
    Fraction f4("1.5");
    std::cout << "Testing constructor from string \"1.5\": f4 = " << f4 << " (Expected: 3/2)" << std::endl;
    assert(f4.toString() == "3/2");

    // Test addition
    Fraction sum = f2 + f4;
    std::cout << "Testing addition: f2 + f4 = " << sum << " (Expected: 9/4)" << std::endl;
    assert(sum.toString() == "9/4");

    // Test subtraction
    Fraction diff = f2 - f4;
    std::cout << "Testing subtraction: f2 - f4 = " << diff << " (Expected: -3/4)" << std::endl;
    assert(diff.toString() == "-3/4");

    // Test multiplication
    Fraction prod = f2 * f4;
    std::cout << "Testing multiplication: f2 * f4 = " << prod << " (Expected: 9/8)" << std::endl;
    assert(prod.toString() == "9/8");

    // Test division
    Fraction quot = f2 / f4;
    std::cout << "Testing division: f2 / f4 = " << quot << " (Expected: 1/2)" << std::endl;
    assert(quot.toString() == "1/2");

    // Test relational operator <
    bool less = (f2 < f4);
    std::cout << "Testing relational operator <: f2 < f4 = " << std::boolalpha << less << " (Expected: true)" << std::endl;
    assert(less == true);

    // Test relational operator <=
    bool lessEqual = (f2 <= f3);
    std::cout << "Testing relational operator <=: f2 <= f3 = " << std::boolalpha << lessEqual << " (Expected: true)" << std::endl;
    assert(lessEqual == true);

    // Test relational operator ==
    bool equal = (f2 == f3);
    std::cout << "Testing relational operator ==: f2 == f3 = " << std::boolalpha << equal << " (Expected: true)" << std::endl;
    assert(equal == true);

    // Test relational operator !=
    bool notEqual = (f2 != f4);
    std::cout << "Testing relational operator !=: f2 != f4 = " << std::boolalpha << notEqual << " (Expected: true)" << std::endl;
    assert(notEqual == true);

    // Test relational operator >=
    bool greaterEqual = (f4 >= f2);
    std::cout << "Testing relational operator >=: f4 >= f2 = " << std::boolalpha << greaterEqual << " (Expected: true)" << std::endl;
    assert(greaterEqual == true);

    // Test relational operator >
    bool greater = (f4 > f2);
    std::cout << "Testing relational operator >: f4 > f2 = " << std::boolalpha << greater << " (Expected: true)" << std::endl;
    assert(greater == true);

    // Test type conversion to double
    double d = static_cast<double>(f2);
    std::cout << "Testing type conversion: double(f2) = " << d << " (Expected: 0.75)" << std::endl;
    assert(d == 0.75);

    // Test toString method
    std::string str = f2.toString();
    std::cout << "Testing toString method: f2.toString() = " << str << " (Expected: 3/4)" << std::endl;
    assert(str == "3/4");

    // Test insertion operator
    std::cout << "Testing insertion operator: Outputting f2 again = " << f2 << " (Expected: 3/4)" << std::endl;
    assert(f2.toString() == "3/4");

    // Automated Testing for Extraction Operator with Valid Input
    {
        std::stringstream ss("5/6");
        Fraction f5;
        ss >> f5;
        std::cout << "Testing extraction operator with valid input '5/6': " << f5 << " (Expected: 5/6)" << std::endl;
        assert(f5.toString() == "5/6");
    }

    // Automated Testing for Extraction Operator with Invalid Input
    {
        std::stringstream ss_invalid("abc");
        Fraction f6;
        ss_invalid >> f6;
        std::cout << "Testing extraction operator with invalid input 'abc': ";
        if (ss_invalid)
        {
            std::cout << f6 << " (Unexpected: Should have failed)" << std::endl;
            // Depending on implementation, you might want to assert failure
            // For example:
            // assert(false && "Extraction should have failed for invalid input");
        }
        else
        {
            std::cout << "Failed to parse fraction from input. (Expected: Failure)" << std::endl;
            assert(!ss_invalid); // Ensure extraction failed
        }
    }

    // Automated Testing for Multiple Extraction Operators
    {
        std::stringstream ss_multiple("7/8 9/10");
        Fraction f7, f8;
        ss_multiple >> f7 >> f8;
        std::cout << "Testing multiple extraction operators with inputs '7/8 9/10': " << f7 << ", " << f8 << " (Expected: 7/8, 9/10)" << std::endl;
        assert(f7.toString() == "7/8");
        assert(f8.toString() == "9/10");
    }

    // Automated Testing for Zero Denominator
    {
        std::stringstream ss_zero_denominator("1/0");
        Fraction f9;
        try
        {
            ss_zero_denominator >> f9;
            std::cout << "Testing extraction operator with zero denominator '1/0': " << f9 << " (Unexpected: Should have handled zero denominator)" << std::endl;
            // Depending on implementation, you might want to assert failure or specific behavior
            // For example:
            // assert(false && "Extraction should have failed for zero denominator");
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Testing extraction operator with zero denominator '1/0': Caught exception: " << e.what() << " (Expected: Exception)" << std::endl;
        }
    }

    // Test: Attempt to construct Fraction object with non-integer parameters
    /*
    {
        Fraction f_invalid(3.3, 4); // Should cause compile-time error
        std::cout << "Testing constructor with non-integer parameters: f_invalid = " << f_invalid << " (Expected: Compile-time error)" << std::endl;
    }
    */

    std::cout << "All tests passed!" << std::endl;

    return 0;
}