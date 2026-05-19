#pragma once
#include "Product.h"

class Order {
private:
    static int nextID;

    char* restaurantName;
    Product* products;
    size_t count;
    int id;

    void freeDynamic();

public:
    Order(const char* rname, const Product* prods, size_t cnt);
    Order(const Order&) = delete;
    Order& operator=(const Order&) = delete;
    ~Order();

    const char* getRestaurantName() const;
    int getID() const;
    const Product* getProducts() const;
    size_t getCount() const;

    static int getNextID();
    static void incrementID();
};
