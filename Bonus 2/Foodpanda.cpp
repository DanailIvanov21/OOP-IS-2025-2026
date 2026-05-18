#include "Foodpanda.h"
#include <iostream>
#include <cstring>

void Foodpanda::freeDynamic() {
    for (size_t i = 0; i < orderCount; i++)
        delete orders[i];
    delete[] orders;

    restaurants = nullptr;
    orders = nullptr;
    orderCount = 0;
    orderCap = 0;
}

void Foodpanda::copyDynamic(const Foodpanda& other) {
    restaurants = other.restaurants;

    Order** newArr = new Order*[other.orderCap];
    size_t i = 0;

    try {
        for (; i < other.orderCount; i++)
            newArr[i] = new Order(*other.orders[i]);
    } catch (...) {
        for (size_t j = 0; j < i; j++)
            delete newArr[j];
        delete[] newArr;
        throw;
    }

    freeDynamic();
    orders = newArr;
    orderCount = other.orderCount;
    orderCap = other.orderCap;
    nextID = other.nextID;
}

void Foodpanda::resizeOrders() {
    size_t newCap = orderCap * 2;
    Order** newArr = new Order*[newCap];

    for (size_t i = 0; i < orderCount; i++)
        newArr[i] = orders[i];

    delete[] orders;
    orders = newArr;
    orderCap = newCap;
}

Foodpanda::Foodpanda(Restaurant* arr, size_t count, size_t cap)
    : restaurants(arr), restCount(count),
      orders(new Order*[cap]), orderCount(0), orderCap(cap), nextID(1) {}

Foodpanda::Foodpanda(const Foodpanda& other)
    : restaurants(nullptr), orders(nullptr),
      restCount(other.restCount), orderCount(0), orderCap(0), nextID(1) {
    copyDynamic(other);
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

Foodpanda::~Foodpanda() {
    freeDynamic();
}

void Foodpanda::readOrder() {
    char restName[50];
    size_t count;

    std::cout << "Restaurant name: ";
    std::cin >> restName;

    std::cout << "Number of products: ";
    std::cin >> count;

    char** prods = new char*[count];
    for (size_t i = 0; i < count; i++) {
        char buff[50];
        std::cout << "Product " << i + 1 << ": ";
        std::cin >> buff;

        prods[i] = new char[strlen(buff) + 1];
        strcpy(prods[i], buff);
    }

    bool exists = false;
    Restaurant* target = nullptr;

    for (size_t i = 0; i < restCount; i++)
        if (strcmp(restaurants[i].getName(), restName) == 0) {
            exists = true;
            target = &restaurants[i];
            break;
        }

    if (!exists) {
        std::cout << "Invalid order: restaurant does not exist\n";
        nextID++;
        for (size_t i = 0; i < count; i++) delete[] prods[i];
        delete[] prods;
        return;
    }

    for (size_t i = 0; i < orderCount; i++)
        if (strcmp(orders[i]->getRestaurantName(), restName) == 0 &&
            orders[i]->getID() == nextID) {
            std::cout << "Invalid order: duplicate ID\n";
            nextID++;
            return;
        }

    try {
        int time = target->processOrder(prods, count);
        std::cout << "Delivery time: " << time << " minutes\n";
    } catch (...) {
        std::cout << "Restaurant does not offer some product\n";
        nextID++;
        for (size_t i = 0; i < count; i++) delete[] prods[i];
        delete[] prods;
        return;
    }

    if (orderCount == orderCap)
        resizeOrders();

    orders[orderCount++] = new Order(restName, nextID, prods, count);
    nextID++;

    for (size_t i = 0; i < count; i++) delete[] prods[i];
    delete[] prods;
}

void Foodpanda::printOrders() const {
    for (size_t i = 0; i < orderCount; i++)
        std::cout << orders[i]->getRestaurantName()
                  << " | ID: " << orders[i]->getID() << "\n";
}
