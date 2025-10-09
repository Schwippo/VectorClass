#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <stdexcept>
#include <cstddef>


class myVector {
    int* data;
    size_t size;
    size_t capacity;

public:
    myVector(size_t capacity = 0);

    void push_back(int e);
    int pop_back();
    void reserve(size_t newCapacity);
    void resize(size_t newCapacity);
    int& at(size_t index);

    size_t getSize() const;
    size_t getCapacity() const;

    ~myVector();
};



#endif //MYVECTOR_H
