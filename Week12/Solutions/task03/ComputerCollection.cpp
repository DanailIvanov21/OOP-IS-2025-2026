#include "ComputerCollection.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

void ComputerCollection::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete items[i];
    delete[] items;

    items = nullptr;
    size = 0;
    capacity = 0;
}

void ComputerCollection::copyDynamic(const ComputerCollection& other) {
    Computer** newArr = new Computer*[other.capacity];
    size_t i = 0;

    try {
        for (; i < other.size; i++)
            newArr[i] = other.items[i]->clone();
    } catch (...) {
        for (size_t j = 0; j < i; j++)
            delete newArr[j];
        delete[] newArr;
        throw;
    }

    freeDynamic();
    items = newArr;
    size = other.size;
    capacity = other.capacity;
}

void ComputerCollection::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    Computer** newArr = new Computer*[newCap];

    for (size_t i = 0; i < size; i++)
        newArr[i] = items[i];

    delete[] items;
    items = newArr;
    capacity = newCap;
}

ComputerCollection::ComputerCollection()
    : items(nullptr), size(0), capacity(0) {}

ComputerCollection::ComputerCollection(const ComputerCollection& other)
    : items(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

ComputerCollection& ComputerCollection::operator=(const ComputerCollection& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

ComputerCollection::~ComputerCollection() {
    freeDynamic();
}

void ComputerCollection::add(const Computer& c) {
    if (size == capacity)
        resize();

    items[size++] = c.clone();
}

bool ComputerCollection::removeByVideo(const char* videoModel) {
    if (!videoModel)
        throw std::invalid_argument("Null video model");

    for (size_t i = 0; i < size; i++) {
        if (strcmp(items[i]->getVideoModel(), videoModel) == 0) {
            delete items[i];
            for (size_t j = i; j < size - 1; j++)
                items[j] = items[j + 1];
            size--;
            return true;
        }
    }
    return false;
}

void ComputerCollection::printAll() const {
    for (size_t i = 0; i < size; i++) {
        items[i]->printType();
        size_t count;
        const MyString* per = items[i]->getPeripherals(count);

        std::cout << "CPU: " << items[i]->getCpuPower()
                  << " | GPU: " << items[i]->getVideoModel()
                  << " | PSU: " << items[i]->getPsuPower()
                  << " | RAM: " << items[i]->getRam() << "\n";

        std::cout << "Peripherals: ";
        for (size_t j = 0; j < count; j++)
            std::cout << per[j] << " ";
        std::cout << "\n\n";
    }
}
