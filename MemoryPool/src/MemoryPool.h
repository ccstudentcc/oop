#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <cstddef>
#include <cstdlib>
#include <new>
#include <iostream>

/*
 * MemoryPool class manages memory allocation using a memory pool.
 * Inspired by SGI's two-level allocator:
 * 1. For requests > MAX_BYTES, use malloc/free directly.
 * 2. For requests ≤ MAX_BYTES, use a memory pool with multiple free lists.
 */
class MemoryPool {
public:
    // Allocate a memory block of the given size
    static void* Allocate(std::size_t size);

    // Deallocate a previously allocated memory block
    static void Deallocate(void* ptr, std::size_t size);

private:
    // Constants for managing small blocks
    static const std::size_t ALIGN      = 8;       // Alignment boundary
    static const std::size_t MAX_BYTES  = 128;     // Maximum block size
    static const std::size_t NFREELISTS = MAX_BYTES / ALIGN; // Number of free lists

    // Free list node structure
    union FreeNode {
        FreeNode* next; // Pointer to the next free node
        char data[1];   // Placeholder for data
    };

    // Array of free lists, each managing blocks of a specific size
    static FreeNode* freeLists[NFREELISTS];

    // Pointers for chunk allocation
    static char*  startFree;  
    static char*  endFree;    
    static size_t heapSize;

private:
    // Utility functions
    // Determine the index of the appropriate free list
    static std::size_t FreeListIndex(std::size_t bytes) {
        return (bytes + ALIGN - 1) / ALIGN - 1;
    }

    // Round up the size to the nearest multiple of ALIGN
    static std::size_t RoundUp(std::size_t bytes) {
        return (bytes + ALIGN - 1) & ~(ALIGN - 1);
    }

    // Add new nodes to a specific free list
    static void* Refill(std::size_t n);

    // Allocate a large chunk and split it into blocks of size n
    static char* ChunkAlloc(std::size_t size, int& nobjs);
};

// Initialize static members
MemoryPool::FreeNode* MemoryPool::freeLists[NFREELISTS] = {nullptr};
char*  MemoryPool::startFree = nullptr;
char*  MemoryPool::endFree   = nullptr;
size_t MemoryPool::heapSize  = 0;

// Allocation interface
void* MemoryPool::Allocate(std::size_t size) {
    if(size > MAX_BYTES) {
        void* res = std::malloc(size);
        if(!res) throw std::bad_alloc();
        return res;
    }
    size = RoundUp(size);
    std::size_t idx = FreeListIndex(size);
    FreeNode* list = freeLists[idx];
    if(list == nullptr) {
        return Refill(size);
    }
    freeLists[idx] = list->next;
    return list;
}

// Deallocation interface
void MemoryPool::Deallocate(void* ptr, std::size_t size) {
    if(!ptr) return;
    if(size > MAX_BYTES) {
        std::free(ptr);
        return;
    }
    size = RoundUp(size);
    std::size_t idx = FreeListIndex(size);
    FreeNode* node = static_cast<FreeNode*>(ptr);
    node->next = freeLists[idx];
    freeLists[idx] = node;
}

// Add nodes to a free list
void* MemoryPool::Refill(std::size_t n) {
    int nobjs = 20; // Number of objects to add
    char* chunk = ChunkAlloc(n, nobjs);
    if(nobjs == 1) return chunk;

    // Initialize the free list with remaining objects
    freeLists[FreeListIndex(n)] = reinterpret_cast<FreeNode*>(chunk + n);
    FreeNode* current = freeLists[FreeListIndex(n)];
    for(int i = 1; i < nobjs - 1; ++i) {
        current->next = reinterpret_cast<FreeNode*>(reinterpret_cast<char*>(current) + n);
        current = current->next;
    }
    current->next = nullptr;
    return chunk;
}

// Allocate a large chunk and split into blocks
char* MemoryPool::ChunkAlloc(std::size_t size, int& nobjs) {
    std::size_t totalBytes = size * nobjs;
    std::size_t leftBytes  = endFree - startFree;

    if(leftBytes >= totalBytes) {
        char* res = startFree;
        startFree += totalBytes;
        return res;
    } else if(leftBytes >= size) {
        nobjs = static_cast<int>(leftBytes / size);
        totalBytes = size * nobjs;
        char* res = startFree;
        startFree += totalBytes;
        return res;
    } else {
        // Calculate new chunk size
        std::size_t bytesToGet = 2 * totalBytes + RoundUp(heapSize >> 4);
        if(leftBytes > 0) {
            std::size_t idx = FreeListIndex(leftBytes);
            reinterpret_cast<FreeNode*>(startFree)->next = freeLists[idx];
            freeLists[idx] = reinterpret_cast<FreeNode*>(startFree);
        }
        startFree = static_cast<char*>(std::malloc(bytesToGet));
        if(!startFree) throw std::bad_alloc();
        endFree = startFree + bytesToGet;
        heapSize += bytesToGet;
        return ChunkAlloc(size, nobjs);
    }
}

/* 
 * Allocator template class providing memory allocation interface.
 * Includes necessary typedefs and methods, conforming to allocator requirements.
 */
template<class T>
class Allocator {
public:
    typedef T                 value_type;
    typedef T*                pointer;
    typedef const T*          const_pointer;
    typedef T&                reference;
    typedef const T&          const_reference;
    typedef std::size_t       size_type;
    typedef ptrdiff_t         difference_type;

    template<typename U>
    struct rebind { 
        typedef Allocator<U> other;
    };

    Allocator() noexcept {}
    ~Allocator() noexcept {}

    template<class U>
    Allocator(const Allocator<U>&) noexcept {}

    // Get address of a reference
    pointer address(reference val) const noexcept {
        return &val;
    }

    const_pointer address(const_reference val) const noexcept {
        return &val;
    }

    // Allocate memory
    pointer allocate(std::size_t n) {
        if(n > max_size()) {
            std::cerr << "Allocation size too large.\n";
            throw std::bad_alloc();
        }
        pointer allocPtr = static_cast<pointer>(MemoryPool::Allocate(n * sizeof(T)));
        if(!allocPtr) {
            std::cerr << "Memory allocation failed.\n";
            throw std::bad_alloc();
        }
        return allocPtr;
    }

    // Deallocate memory
    void deallocate(pointer ptr, size_type n) noexcept {
        MemoryPool::Deallocate(ptr, n * sizeof(T));
    }

    // Return the maximum allocation size
    size_type max_size() const noexcept {
        return size_type(-1) / sizeof(T);
    }

    // Construct an object
    template<class U, class... Args>
    void construct(U* ptr, Args&&... args) {
        ::new (static_cast<void*>(ptr)) U(std::forward<Args>(args)...);
    }

    // Destroy an object
    template<class U>
    void destroy(U* ptr) {
        ptr->~U();
    }
};

// Compare allocators for equality
template <class T1, class T2>
bool operator==(const Allocator<T1>&, const Allocator<T2>&) {
    return true;
}

template <class T1, class T2>
bool operator!=(const Allocator<T1>&, const Allocator<T2>&) {
    return false;
}

#endif // MEMORY_POOL_H
