#include "Inventory.h"

void Inventory::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete items[i];
    delete[] items;
    items = nullptr;
    size = 0;
}

void Inventory::copyDynamic(const Inventory& other) {
    items = new Device*[other.size];
    for (size_t i = 0; i < other.size; i++)
        items[i] = other.items[i]; 
    size = other.size;
}

Inventory::Inventory() : items(nullptr), size(0) {}

Inventory::Inventory(const Inventory& other)
    : items(nullptr), size(0) {
    copyDynamic(other);
}

Inventory& Inventory::operator=(const Inventory& other) {
    if (this != &other) {
        freeDynamic();
        copyDynamic(other);
    }
    return *this;
}

Inventory::~Inventory() {
    freeDynamic();
}

void Inventory::add(Device* d) {
    Device** newArr = new Device*[size + 1];
    for (size_t i = 0; i < size; i++)
        newArr[i] = items[i];
    newArr[size] = d;

    delete[] items;
    items = newArr;
    size++;
}

void Inventory::printAll() const {
    for (size_t i = 0; i < size; i++) {
        if (items[i]->getType() == DeviceType::Laptop)
            ((Laptop*)items[i])->print();
        else
            ((Car*)items[i])->print();
    }
}

bool Inventory::isSortedByPerformance() const {
    for (size_t i = 1; i < size; i++) {
        int prev = (items[i - 1]->getType() == DeviceType::Laptop)
                   ? ((Laptop*)items[i - 1])->get_perf()
                   : ((Car*)items[i - 1])->get_perf();

        int curr = (items[i]->getType() == DeviceType::Laptop)
                   ? ((Laptop*)items[i])->get_perf()
                   : ((Car*)items[i])->get_perf();

        if (prev > curr)
            return false;
    }
    return true;
}
