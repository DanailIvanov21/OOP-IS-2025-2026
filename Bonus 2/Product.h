#pragma once
#include <iostream>

class Product {
private:
    char* name;

    void freeDynamic();
    void copyDynamic(const Product& other);

public:
    Product(const char* n = "");
    Product(const Product& other);
    Product& operator=(const Product& other);
    ~Product();

    const char* getName() const;
};
