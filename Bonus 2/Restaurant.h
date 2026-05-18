#pragma once
#include "Product.h"

class Restaurant {
private:
    char name[25];
    Product* products;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const Restaurant& other);

public:
    Restaurant(const char* n, size_t cap);
    Restaurant(const Restaurant& other);
    Restaurant& operator=(const Restaurant& other);
    ~Restaurant();

    const char* getName() const;

    void addProduct(const Product& p);
    bool offers(const char* p) const;

    int processOrder(const Product* orderProducts, size_t count) const;
};
