#include <iostream>
#include "Foodpanda.h"

int main() {
    Restaurant r1("Happy", 5);
    r1.addProduct("pizza");
    r1.addProduct("salad");

    Restaurant r2("KFC", 5);
    r2.addProduct("wings");
    r2.addProduct("fries");

    Restaurant arr[2] = { r1, r2 };

    Foodpanda fp(arr, 2, 5);

    fp.readOrder();
    fp.readOrder();

    fp.printOrders();

    return 0;
}
