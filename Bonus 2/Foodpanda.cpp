#include "Foodpanda.h"
#include <iostream>
#include <cstring>

void Foodpanda::freeDynamic() {
    for (size_t i = 0; i < orderCount; i++)
        delete orders[i];
    delete[] orders;
}

void Foodpanda::copyDynamic(const Foodpanda& other) {
    restaurants = other.restaurants;

    Order** newArr = new Order*[other.orderCap];
    size_t i = 0;

    try {
        for (; i < other.orderCount; i++)
            newArr[i] = new Order(
                other.orders[i]->getRestaurantName(),
                other.orders[i]->getProducts(),
                other.orders[i]->getCount()
            );
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
      orders(new Order*[cap]), orderCount(0), orderCap(cap) {}

Foodpanda::Foodpanda(const Foodpanda& other)
    : restaurants(nullptr), orders(nullptr),
      restCount(other.restCount), orderCount(0), orderCap(0) {
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

bool Foodpanda::orderExists(int id) const {
    for (size_t i = 0; i < orderCount; i++)
        if (orders[i]->getID() == id)
            return true;
    return false;
}

void Foodpanda::readOrder() {
    char restName[50];
    size_t cnt;

    std::cout << "Restaurant name: ";
    std::cin >> restName;

    std::cout << "Number of products: ";
    std::cin >> cnt;

    Product* prods = new Product[cnt];
    for (size_t i = 0; i < cnt; i++) {
        char buff[50];
        std::cout << "Product " << i + 1 << ": ";
        std::cin >> buff;
        prods[i] = Product(buff);
    }

    int currentID = Order::getNextID();

    Restaurant* target = nullptr;
    for (size_t i = 0; i < restCount; i++)
        if (strcmp(restaurants[i].getName(), restName) == 0)
            target = &restaurants[i];

    if (!target) {
        std::cout << "Invalid order: restaurant does not exist\n";
        Order::incrementID();
        delete[] prods;
        return;
    }

    if (orderExists(currentID)) {
        std::cout << "Invalid order: duplicate ID\n";
        Order::incrementID();
        delete[] prods;
        return;
    }

    try {
        int time = target->processOrder(prods, cnt);
        std::cout << "Delivery time: " << time << " minutes\n";
    } catch (...) {
        std::cout << "Restaurant does not offer some product\n";
        Order::incrementID();
        delete[] prods;
        return;
    }

    if (orderCount == orderCap)
        resizeOrders();

    orders[orderCount++] = new Order(restName, prods, cnt);

    delete[] prods;
}

void Foodpanda::printOrders() const {
    for (size_t i = 0; i < orderCount; i++)
        std::cout << "Order ID: " << orders[i]->getID()
                  << " | Restaurant: " << orders[i]->getRestaurantName() << "\n";
}
