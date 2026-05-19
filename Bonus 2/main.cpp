#include <iostream>
#include "Foodpanda.h"

int main() {
    Restaurant r1("Happy", 5);
    r1.addProduct(Product("pizza"));
    r1.addProduct(Product("salad"));

    Restaurant r2("KFC", 5);
    r2.addProduct(Product("wings"));
    r2.addaddProduct(Product("fries"));

    Restaurant arr[2] = { r1, r2 };

    Foodpanda fp(arr, 2, 5);

    fp.readOrder();
    fp.readOrder();

    fp.printOrders();
}
