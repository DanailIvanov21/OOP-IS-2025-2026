#pragma once
#include "Laptop.h"
#include "Car.h"

class Inventory {
private:
    Device** items;
    size_t size;

    void freeDynamic();
    void copyDynamic(const Inventory& other);

public:
    Inventory();
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
    ~Inventory();

    void add(Device* d); 
    void printAll() const;
    bool isSortedByPerformance() const;
};
