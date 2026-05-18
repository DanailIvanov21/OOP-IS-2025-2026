#include "Restaurant.h"
#include <cstring>
#include <stdexcept>

void Restaurant::freeDynamic() {
    delete[] products;
    products = nullptr;
    size = 0;
    capacity = 0;
}

void Restaurant::copyDynamic(const Restaurant& other) {
    Product* newArr = new Product[other.capacity];

    for (size_t i = 0; i < other.size; i++)
        newArr[i] = other.products[i];

    freeDynamic();
    products = newArr;
    size = other.size;
    capacity = other.capacity;
    strcpy(name, other.name);
}

Restaurant::Restaurant(const char* n, size_t cap)
    : products(nullptr), size(0), capacity(cap) {
    strncpy(name, n, 24);
    name[24] = '\0';

    products = new Product[capacity];
}

Restaurant::Restaurant(const Restaurant& other)
    : products(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

Restaurant::~Restaurant() {
    freeDynamic();
}

const char* Restaurant::getName() const {
    return name;
}

void Restaurant::addProduct(const Product& p) {
    if (size == capacity)
        throw std::runtime_error("Restaurant product list full");

    products[size++] = p;
}

bool Restaurant::offers(const char* p) const {
    for (size_t i = 0; i < size; i++)
        if (strcmp(products[i].getName(), p) == 0)
            return true;
    return false;
}

int Restaurant::processOrder(const Product* orderProducts, size_t count) const {
    for (size_t i = 0; i < count; i++)
        if (!offers(orderProducts[i].getName()))
            throw std::runtime_error("Restaurant does not offer product");

    return 20 + (int)count * 5;
}
