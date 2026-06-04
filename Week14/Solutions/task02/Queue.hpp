#pragma once
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    size_t size;
    size_t capacity;
    size_t frontIndex;
    size_t backIndex;

    void freeDynamic();
    void copyDynamic(const Queue<T>& other);
    void resize();

public:
    Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);
    ~Queue();

    void enqueue(const T& element);
    T dequeue();

    bool isEmpty() const;
    void clear();

    size_t getSize() const;
};

template <typename T>
void Queue<T>::freeDynamic() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
void Queue<T>::copyDynamic(const Queue<T>& other) {
    T* newData = new T[other.capacity];

    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[(other.frontIndex + i) % other.capacity];

    freeDynamic();
    data = newData;
    size = other.size;
    capacity = other.capacity;
    frontIndex = 0;
    backIndex = size;
}

template <typename T>
void Queue<T>::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    T* newData = new T[newCap];

    for (size_t i = 0; i < size; i++)
        newData[i] = data[(frontIndex + i) % capacity];

    delete[] data;
    data = newData;
    capacity = newCap;
    frontIndex = 0;
    backIndex = size;
}

template <typename T>
Queue<T>::Queue()
    : data(nullptr), size(0), capacity(0), frontIndex(0), backIndex(0) {}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
    : data(nullptr), size(0), capacity(0), frontIndex(0), backIndex(0) {
    copyDynamic(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    freeDynamic();
}

template <typename T>
void Queue<T>::enqueue(const T& element) {
    if (size == capacity)
        resize();

    data[backIndex] = element;
    backIndex = (backIndex + 1) % capacity;
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty())
        throw std::out_of_range("Queue is empty");

    T result = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    size--;
    return result;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void Queue<T>::clear() {
    size = 0;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
size_t Queue<T>::getSize() const {
    return size;
}
