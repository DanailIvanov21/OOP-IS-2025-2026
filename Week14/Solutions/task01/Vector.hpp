#pragma once
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const Vector<T>& other);
    void resize();

public:
    Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    void pushBack(const T& element);
    void pushAt(const T& element, size_t index);

    void popBack();
    void popAt(size_t index);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    bool empty() const;
    void clear();
    void swap(Vector<T>& other);

    size_t getSize() const;
};

template <typename T>
void Vector<T>::freeDynamic() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
void Vector<T>::copyDynamic(const Vector<T>& other) {
    T* newData = new T[other.capacity];
    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[i];

    freeDynamic();
    data = newData;
    size = other.size;
    capacity = other.capacity;
}

template <typename T>
void Vector<T>::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    T* newData = new T[newCap];

    for (size_t i = 0; i < size; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCap;
}

template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
    : data(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    freeDynamic();
}

template <typename T>
void Vector<T>::pushBack(const T& element) {
    if (size == capacity)
        resize();
    data[size++] = element;
}

template <typename T>
void Vector<T>::pushAt(const T& element, size_t index) {
    if (index > size)
        throw std::out_of_range("Invalid index");

    if (size == capacity)
        resize();

    for (size_t i = size; i > index; i--)
        data[i] = data[i - 1];

    data[index] = element;
    size++;
}

template <typename T>
void Vector<T>::popBack() {
    if (size == 0)
        throw std::out_of_range("Vector is empty");
    size--;
}

template <typename T>
void Vector<T>::popAt(size_t index) {
    if (index >= size)
        throw std::out_of_range("Invalid index");

    for (size_t i = index; i < size - 1; i++)
        data[i] = data[i + 1];

    size--;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Invalid index");
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Invalid index");
    return data[index];
}

template <typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template <typename T>
void Vector<T>::clear() {
    size = 0;
}

template <typename T>
void Vector<T>::swap(Vector<T>& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}
