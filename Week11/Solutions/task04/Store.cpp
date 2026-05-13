#include "Store.h"
#include <iostream>

void Store::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete items[i];
    delete[] items;
    items = nullptr;
    size = 0;
    capacity = 0;
}

void Store::copyDynamic(const Store& other) {
    items = new Phone*[other.capacity];
    for (size_t i = 0; i < other.size; i++)
        items[i] = other.items[i]; 

    size = other.size;
    capacity = other.capacity;
    usedBudget = other.usedBudget;
}

void Store::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    Phone** newArr = new Phone*[newCap];

    for (size_t i = 0; i < size; i++)
        newArr[i] = items[i];

    delete[] items;
    items = newArr;
    capacity = newCap;
}

Store::Store(double initialBudget)
    : items(nullptr), size(0), capacity(0),
      budget(initialBudget), usedBudget(0) {}

Store::Store(const Store& other)
    : items(nullptr), size(0), capacity(0), budget(other.budget) {
    copyDynamic(other);
}

Store& Store::operator=(const Store& other) {
    if (this != &other) {
        freeDynamic();
        copyDynamic(other);
    }
    return *this;
}

Store::~Store() {
    freeDynamic();
}

bool Store::add(Phone* p) {
    double price = p->getPrice();
    if (usedBudget + price > budget)
        return false;

    if (size == capacity)
        resize();

    items[size++] = p;
    usedBudget += price;
    return true;
}

bool Store::remove(const MyString& brand, const MyString& model) {
    for (size_t i = 0; i < size; i++) {
        if (items[i]->getBrand() == brand &&
            items[i]->getModel() == model) {

            usedBudget -= items[i]->getPrice();
            delete items[i];

            for (size_t j = i; j < size - 1; j++)
                items[j] = items[j + 1];

            size--;
            return true;
        }
    }
    return false;
}

void Store::print() const {
    for (size_t i = 0; i < size; i++)
        std::cout << *items[i] << "\n";
}

double Store::getRemainingBudget() const {
    return budget - usedBudget;
}
