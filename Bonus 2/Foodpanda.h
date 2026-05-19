#pragma once
#include "Restaurant.h"
#include "Order.h"

class Foodpanda {
private:
    Restaurant* restaurants;
    size_t restCount;

    Order** orders;
    size_t orderCount;
    size_t orderCap;

    void freeDynamic();
    void copyDynamic(const Foodpanda& other);
    void resizeOrders();

    bool orderExists(int id) const;

public:
    Foodpanda(Restaurant* arr, size_t count, size_t cap);
    Foodpanda(const Foodpanda& other);
    Foodpanda& operator=(const Foodpanda& other);
    ~Foodpanda();

    void readOrder();
    void printOrders() const;
};
