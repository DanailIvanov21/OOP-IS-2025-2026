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
    void resizeOrders();

public:
    Foodpanda(Restaurant* arr, size_t count, size_t orderCap);
    ~Foodpanda();

    void readOrder();
    void printOrders() const;
