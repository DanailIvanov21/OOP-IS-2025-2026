#include <iostream>
#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"
#include "ComputerCollection.h"

int main() {
    ComputerCollection shop;

    PC pc(3.5, "RTX 3060", 650, 16);
    Laptop lap(2.8, "Intel Iris", 120, 8);
    GamingConsole gc(3.2, "Custom GPU", 200, 16);

    shop.add(pc);
    shop.add(lap);
    shop.add(gc);

    std::cout << "All computers:\n";
    shop.printAll();

    std::cout << "Removing by GPU model RTX 3060...\n";
    shop.removeByVideo("RTX 3060");

    std::cout << "After removal:\n";
    shop.printAll();

    return 0;
}
