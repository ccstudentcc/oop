# Project Introduction

Given the declaration of a class template `Vector` as shown below, implement the bodies of all the member functions. Please also write a main function to test all the facilities of the class `Vector`.

```c++
template <class T>
class Vector {
public:
  Vector();                      // creates an empty vector
  Vector(int size);              // creates a vector for holding 'size' elements
  Vector(const Vector& r);       // the copy ctor
  ~Vector();                     // destructs the vector 
  T& operator[](int index);      // accesses the specified element without bounds checking
  T& at(int index);              // accesses the specified element, throws an exception of
                                 // type 'std::out_of_range' when index <0 or >=m_nSize
  int size() const;              // return the size of the container
  void push_back(const T& x);    // adds an element to the end 
  void clear();                  // clears the contents
  bool empty() const;            // checks whether the container is empty 
private:
  void inflate();                // expand the storage of the container to a new capacity,
                                 // e.g. 2*m_nCapacity
  T *m_pElements;                // pointer to the dynamically allocated storage
  int m_nSize;                   // the number of elements in the container
  int m_nCapacity;               // the total number of elements that can be held in the
                                 // allocated storage
};

```

## Directory Structure

```plaintext
Vector
│  CMakeLists.txt
│  README.md
│
├─include
│      Vector.h
│
└─src
        test.cpp
```

## Instructions

Please use `CMakeLists.txt` as follows:

1. `mkdir build`
2. `cd build`
3. `cmake ..`

    If you encounter the following error:

    ```
    -- Building for: NMake Makefiles
    CMake Error at CMakeLists.txt:3 (project):
      Running
    
       'nmake' '-?'
    
      failed with:
    
       系统找不到指定的文件。
    CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
    CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
    -- Configuring incomplete, errors occurred!
    ```
    
    Please use:
    
    ```bash
    cmake -G "MinGW Makefiles" ..
    ```
    
    instead of `cmake ..`

4. `make`
5. `VectorTest.exe` is the final file.


## Test Suite for the Fraction class(`test.cpp`)
This program performs a series of tests to verify the correctness and functionality of the `Vector` class. The tests include:
### Constructor Tests
- **Default Constructor**: Verifies empty vector creation
- **Parameterized Constructor**: Tests vector creation with specified size
- **Copy Constructor**: Ensures correct vector copying
- **Exception Handling**: Tests invalid parameters like negative size

### Element Access Tests
- **operator[]**: Element access without bounds checking
- **at() Method**: Element access with bounds checking
- **Bounds Handling**: Verifies exception handling in at()

### Container Modification Tests
- **push_back()**: Tests element addition and auto-expansion
- **clear()**: Verifies clearing operations
- **empty()**: Checks empty container detection
- **size()**: Validates size calculations

### Type Support Tests
- **Basic Types**: int, double, string etc.
- **Custom Types**: Ensures support for user-defined types
- **Large Data**: Verifies container expansion mechanism

### Error Handling Tests
- **Out-of-bounds Access**: Boundary checking in at() method
- **Memory Management**: Ensures no memory leaks
- **Exception Safety**: Verifies state maintenance during exceptions

