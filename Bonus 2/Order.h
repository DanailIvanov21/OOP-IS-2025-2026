#pragma once
#include "Product.h"

class Order {
private:
    static int nextID;

    char* restaurantName;
    int id;
    Product* products;
    size_t count;

    void freeDynamic();
    void copyDynamic(const Order& other);

public:
    Order(const char* rname, const Product* prods, size_t cnt);
    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();

    const char* getRestaurantName() const;
    int getID() const;
    const Product* getProducts() const;
    size_t getCount() const;
};
