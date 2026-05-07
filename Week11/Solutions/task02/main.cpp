#include <iostream>
#include "Inventory.h"

int main() {
    Inventory inv;

    inv.add(new Laptop("Dell", 3200));
    inv.add(new Car("BMW", 250, 3000));
    inv.add(new Laptop("HP", 2800));

    inv.printAll();

    std::cout << "Sorted? " << inv.isSortedByPerformance() << "\n";

    return 0;
}
