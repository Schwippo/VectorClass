#include "myVector.h"
#include <iostream>

myVector::myVector(size_t capacity) : data(nullptr), size(0), capacity(capacity) {
    if (capacity > 0)
        data = new int[capacity];
}

myVector::~myVector () {
    delete[] data;
}

void myVector::push_back(int e) {
    // Falls Array voll -> Kapazität verdoppeln + neues Array erstellen
    if (size == capacity) {
        size_t newCapacity;
        if (capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity = capacity * 2;
        }
        reserve(newCapacity);
    }
    // size inkrementieren
    data[size++] = e;
}

int myVector::pop_back() {
    if (size == 0)
        throw std::out_of_range("Vektor ist leer");

    // letztes Element des Containers entfernen -> size dekrementieren
    int lastElement = data[size - 1];
    size--;

    // Wenn Anzahl Elemente < Hälfte der Kapazität -> neues halbgroßes Array erzeugen
    if (size < capacity / 2 && capacity > 1)
        reserve(capacity / 2);

    return lastElement;
}

void myVector::reserve(size_t newCapacity) {
    // neue Kapazität < Anzahl der gespeichertes Elemente (size) -> out of range Exception
    if (newCapacity < size)
        throw std::out_of_range("Neue Kapazität ist kleiner als die aktuelle Größe");

    int* newData = new int[newCapacity];
    for (size_t i = 0; i < size; ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void myVector::resize(size_t newCapacity) {
    int* newData = new int[newCapacity];
    size_t elementsToCopy;

    if (newCapacity < size) {
        elementsToCopy = newCapacity;
    } else {
        elementsToCopy = size;
    }
    for (size_t i = 0; i < elementsToCopy; ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
    size = elementsToCopy;
}

int& myVector::at(size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

size_t myVector::getSize() const { return size; }
size_t myVector::getCapacity() const { return capacity; }
