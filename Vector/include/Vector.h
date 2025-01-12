#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <class T>
class Vector {
public:
    Vector();                      // creates an empty vector
    Vector(int size);             // creates a vector for holding 'size' elements 
    Vector(const Vector& r);      // copy constructor
    ~Vector();                    // destructor

    T& operator[](int index);     // access element without bounds checking
    T& at(int index);            // access element with bounds checking
    int size() const;            // get container size
    void push_back(const T& x);  // add element to end
    void clear();                // clear contents
    bool empty() const;          // check if empty

private:
    void inflate();              // expand storage capacity
    T* m_pElements;             // dynamic storage
    int m_nSize;                // current size
    int m_nCapacity;            // total capacity
};

// Default constructor
template <class T>
Vector<T>::Vector() : m_pElements(nullptr), m_nSize(0), m_nCapacity(0) {}

// Constructor with size parameter
template <class T>  
Vector<T>::Vector(int size) : m_nSize(size), m_nCapacity(size) {
    if (size < 0) {
        throw std::invalid_argument("Size must be non-negative");
    }
    m_pElements = new T[size];
}

// Copy constructor
template <class T>
Vector<T>::Vector(const Vector& r) : m_nSize(r.m_nSize), m_nCapacity(r.m_nCapacity) {
    if (m_nCapacity > 0 && r.m_pElements != nullptr) {
        try {
            m_pElements = new T[m_nCapacity];
            for (int i = 0; i < m_nSize; i++) {
                m_pElements[i] = r.m_pElements[i];
            }
        }
        catch (...) {
            delete[] m_pElements;
            throw;  // 重新抛出异常
        }
    }
    else {
        m_pElements = nullptr;
    }
}

// Destructor
template <class T>
Vector<T>::~Vector() {
    delete[] m_pElements;
}

// Operator[] for element access without bounds checking
template <class T>
T& Vector<T>::operator[](int index) {
    return m_pElements[index];
}

// at() method for element access with bounds checking
template <class T>
T& Vector<T>::at(int index) {
    if(index < 0 || index >= m_nSize) {
        throw std::out_of_range("Index out of range");
    }
    return m_pElements[index];
}

// Method to get the size of the vector
template <class T>
int Vector<T>::size() const {
    return m_nSize;
}

// Method to add an element to the end of the vector
template <class T>
void Vector<T>::push_back(const T& x) {
    if(m_nSize == m_nCapacity) {
        inflate();
    }
    m_pElements[m_nSize++] = x;
}

// Method to clear the vector
template <class T>
void Vector<T>::clear() {
    for(int i = 0; i < m_nSize; i++) {
        m_pElements[i].~T();
    }
    m_nSize = 0;
}

// Method to check if the vector is empty
template <class T>
bool Vector<T>::empty() const {
    return m_nSize == 0;
}

// Method to increase the capacity of the vector
template <class T>
void Vector<T>::inflate() {
    m_nCapacity = (m_nCapacity == 0) ? 1 : m_nCapacity * 2;
    T* newElements = new T[m_nCapacity];
    for(int i = 0; i < m_nSize; i++) {
        newElements[i] = m_pElements[i];
    }
    delete[] m_pElements;
    m_pElements = newElements;
}

#endif