#include "Product.h"
#include <cstring>
#include <stdexcept>

void Product::freeDynamic() {
    delete[] name;
    name = nullptr;
}

void Product::copyDynamic(const Product& other) {
    char* newName = new char[strlen(other.name) + 1];
    strcpy(newName, other.name);

    freeDynamic();
    name = newName;
}

Product::Product(const char* n) : name(nullptr) {
    if (!n) throw std::invalid_argument("Null product name");
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Product::Product(const Product& other) : name(nullptr) {
    copyDynamic(other);
}

Product& Product::operator=(const Product& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

Product::~Product() {
    freeDynamic();
}

const char* Product::getName() const {
    return name;
}
