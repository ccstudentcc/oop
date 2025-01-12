#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include <iomanip>

#include "MemoryPool.h"

using Point2D = std::pair<int, int>;

// Different sizes for testing memory allocation performance
const std::vector<int> TestSizes = {1000, 4000, 16000};

// Template function to test allocator performance
template <template <class> class MyAllocator>
void test(int TestSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, TestSize);
    int PickSize = TestSize / 5;  // Randomly resize 1/5 of the vectors

    // Vector of vectors of ints with custom allocator
    using IntVec = std::vector<int, MyAllocator<int>>;
    std::vector<IntVec, MyAllocator<IntVec>> vecints(TestSize);
    for (int i = 0; i < TestSize; i++) vecints[i].resize(dis(gen));

    // Vector of vectors of Point2D with custom allocator
    using PointVec = std::vector<Point2D, MyAllocator<Point2D>>;
    std::vector<PointVec, MyAllocator<PointVec>> vecpts(TestSize);
    for (int i = 0; i < TestSize; i++) vecpts[i].resize(dis(gen));

    // Randomly resize some of the inner vectors
    for (int i = 0; i < PickSize; i++) {
        int idx = dis(gen) - 1;
        int size = dis(gen);
        vecints[idx].resize(size);
        vecpts[idx].resize(size);
    }

    // Test assignment for vectors of ints
    int val = 10;
    int idx1 = dis(gen) - 1;
    int idx2 = vecints[idx1].size() / 2;
    vecints[idx1][idx2] = val;
    if (vecints[idx1][idx2] == val)
        std::cout << "vecints assignment correct: " << idx1 << std::endl;
    else
        std::cout << "vecints assignment incorrect: " << idx1 << std::endl;

    // Test assignment for vectors of Point2D
    Point2D valPt(11, 15);
    idx1 = dis(gen) - 1;
    idx2 = vecpts[idx1].size() / 2;
    vecpts[idx1][idx2] = valPt;
    if (vecpts[idx1][idx2] == valPt)
        std::cout << "vecpts assignment correct: " << idx1 << std::endl;
    else
        std::cout << "vecpts assignment incorrect: " << idx1 << std::endl;
}

template <template <class> class custom>
void runTests() {
    std::cout << std::fixed << std::setprecision(3);
    for (const auto& TestSize : TestSizes) {
        double custom_alloc_time, std_alloc_time;
        clock_t start;

        // Test with custom allocator
        start = clock();
        test<custom>(TestSize);
        custom_alloc_time = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
        std::cout << "TestSize: " << TestSize << " | Custom allocator cost: " << custom_alloc_time << "s" << std::endl;

        // Test with standard allocator
        start = clock();
        test<std::allocator>(TestSize);
        std_alloc_time = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
        std::cout << "TestSize: " << TestSize << " | std::allocator cost: " << std_alloc_time << "s" << std::endl;

        // Compare allocator performance
        double ratio = custom_alloc_time / std_alloc_time;
        std::cout << "Custom allocator is " << ratio << " times std::allocator for TestSize " << TestSize << "\n" << std::endl;
    }
}

int main() {
    runTests<Allocator>();
    return 0;
}
