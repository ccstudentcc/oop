#include "../include/Vector.h"
#include <cassert>
#include <iostream>
#include <string>

// Test constructors
void testConstructors() {
    // Test default constructor
    Vector<int> v1;
    assert(v1.empty());
    assert(v1.size() == 0);

    // Test size constructor
    Vector<int> v2(5);
    assert(v2.size() == 5);
    assert(!v2.empty());

    // Test negative size
    try {
        Vector<int> v3(-1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        // Expected
    }

    // Test copy constructor
    Vector<int> v4(3);
    v4[0] = 1;
    v4[1] = 2;
    v4[2] = 3;
    Vector<int> v5(v4);
    assert(v5.size() == 3);
    assert(v5[0] == 1);
    assert(v5[1] == 2);
    assert(v5[2] == 3);
}

// Test element access
void testAccess() {
    Vector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;

    // Test operator[]
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);

    // Test at() with valid indices
    assert(v.at(0) == 10);
    assert(v.at(1) == 20);
    assert(v.at(2) == 30);

    // Test at() with invalid indices
    try {
        v.at(-1);
        assert(false);
    }
    catch (const std::out_of_range&) {
        // Expected
    }

    try {
        v.at(3);
        assert(false);
    }
    catch (const std::out_of_range&) {
        // Expected
    }
}

// Test vector modifications
void testModifications() {
    Vector<std::string> v;

    // Test push_back and automatic growth
    for (int i = 0; i < 100; i++) {
        v.push_back("test" + std::to_string(i));
    }
    assert(v.size() == 100);
    assert(v[0] == "test0");
    assert(v[99] == "test99");

    // Test clear
    v.clear();
    assert(v.empty());
    assert(v.size() == 0);

    // Test push_back after clear
    v.push_back("new");
    assert(v.size() == 1);
    assert(v[0] == "new");
}

// Test different data types
void testTypes() {
    // Test with int
    Vector<int> vi;
    vi.push_back(42);
    assert(vi[0] == 42);

    // Test with double
    Vector<double> vd;
    vd.push_back(3.14);
    assert(vd[0] == 3.14);

    // Test with string
    Vector<std::string> vs;
    vs.push_back("hello");
    assert(vs[0] == "hello");

    // Test with user-defined type
    struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y) {}
        bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    };
    Vector<Point> vp;
    vp.push_back(Point(1, 2));
    assert(vp[0] == Point(1, 2));
}

int main() {
    std::cout << "Starting vector tests...\n";

    try {
        testConstructors();
        std::cout << "Constructor tests passed\n";

        testAccess();
        std::cout << "Access tests passed\n";

        testModifications();
        std::cout << "Modification tests passed\n";

        testTypes();
        std::cout << "Type tests passed\n";

        std::cout << "All tests passed!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}