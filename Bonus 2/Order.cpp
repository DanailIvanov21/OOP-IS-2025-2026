#include "Order.h"
#include <cstring>

int Order::nextID = 1;

void Order::freeDynamic() {
    delete[] restaurantName;
    delete[] products;
}

Order::Order(const char* rname, const Product* prods, size_t cnt)
    : restaurantName(nullptr), products(nullptr), count(cnt), id(nextID++)
{
    restaurantName = new char[strlen(rname) + 1];
    strcpy(restaurantName, rname);

    products = new Product[cnt];
    for (size_t i = 0; i < cnt; i++)
        products[i] = prods[i];
}

Order::~Order() {
    freeDynamic();
}

const char* Order::getRestaurantName() const { return restaurantName; }
int Order::getID() const { return id; }
const Product* Order::getProducts() const { return products; }
size_t Order::getCount() const { return count; }

int Order::getNextID() { return nextID; }
void Order::incrementID() { nextID++; }
