#include "Store.h"
#include <iostream>

void Store::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete items[i];
    delete[] items;
}

void Store::copyDynamic(const Store& other) {
    items = new Phone*[other.size];
    for (size_t i = 0; i < other.size; i++)
        items[i] = other.items[i]; 
    size = other.size;
    usedBudget = other.usedBudget;
}

Store::Store(double initialBudget)
    : items(nullptr), size(0), budget(initialBudget), usedBudget(0) {}

Store::Store(const Store& other)
    : items(nullptr), size(0), budget(other.budget) {
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

    Phone** newArr = new Phone*[size + 1];
    for (size_t i = 0; i < size; i++)
        newArr[i] = items[i];
    newArr[size] = p;

    delete[] items;
    items = newArr;
    size++;
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
