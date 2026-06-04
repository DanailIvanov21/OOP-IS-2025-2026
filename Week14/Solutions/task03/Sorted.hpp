#pragma once
#include <iostream>
#include <stdexcept>

template <typename T, size_t capacity>
class Sorted {
private:
    T data[capacity];
    size_t size;

    int findIndex(const T& elem) const;

public:
    Sorted();

    void add(const T& elem);
    void remove(const T& elem);
    void print() const;

    size_t getSize() const;
};

template <typename T, size_t capacity>
Sorted<T, capacity>::Sorted() : size(0) {}

template <typename T, size_t capacity>
int Sorted<T, capacity>::findIndex(const T& elem) const {
    for (size_t i = 0; i < size; i++)
        if (data[i] == elem)
            return (int)i;
    return -1;
}

template <typename T, size_t capacity>
void Sorted<T, capacity>::add(const T& elem) {
    if (size == capacity)
        throw std::runtime_error("Sorted array is full");

    size_t pos = 0;
    while (pos < size && data[pos] < elem)
        pos++;

    for (size_t i = size; i > pos; i--)
        data[i] = data[i - 1];

    data[pos] = elem;
    size++;
}

template <typename T, size_t capacity>
void Sorted<T, capacity>::remove(const T& elem) {
    int index = findIndex(elem);
    if (index == -1)
        throw std::runtime_error("Element not found");

    for (size_t i = index; i < size - 1; i++)
        data[i] = data[i + 1];

    size--;
}

template <typename T, size_t capacity>
void Sorted<T, capacity>::print() const {
    for (size_t i = 0; i < size; i++)
        std::cout << data[i] << "\n";
}

template <typename T, size_t capacity>
size_t Sorted<T, capacity>::getSize() const {
    return size;
}
