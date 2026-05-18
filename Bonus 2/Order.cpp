#include "Order.h"
#include <cstring>
#include <stdexcept>

int Order::nextID = 1;

void Order::freeDynamic() {
    delete[] restaurantName;
    delete[] products;

    restaurantName = nullptr;
    products = nullptr;
    count = 0;
}

void Order::copyDynamic(const Order& other) {
    char* newName = new char[strlen(other.restaurantName) + 1];
    strcpy(newName, other.restaurantName);

    Product* newArr = new Product[other.count];
    for (size_t i = 0; i < other.count; i++)
        newArr[i] = other.products[i];

    freeDynamic();
    restaurantName = newName;
    products = newArr;
    count = other.count;
}

Order::Order(const char* rname, const Product* prods, size_t cnt)
    : restaurantName(nullptr), id(nextID++), products(nullptr), count(cnt) {
    restaurantName = new char[strlen(rname) + 1];
    strcpy(restaurantName, rname);

    products = new Product[cnt];
    for (size_t i = 0; i < cnt; i++)
        products[i] = prods[i];
}

Order::Order(const Order& other)
    : restaurantName(nullptr), id(other.id), products(nullptr), count(0) {
    copyDynamic(other);
}

Order& Order::operator=(const Order& other) {
    if (this != &other) {
        id = other.id;
        copyDynamic(other);
    }
    return *this;
}

Order::~Order() {
    freeDynamic();
}

const char* Order::getRestaurantName() const { return restaurantName; }
int Order::getID() const { return id; }
const Product* Order::getProducts() const { return products; }
size_t Order::getCount() const { return count; }
