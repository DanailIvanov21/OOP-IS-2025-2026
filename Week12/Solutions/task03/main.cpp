#include <iostream>
#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"

int main() {
    PC pc(3.5, "RTX 3060", 650, 16);
    Laptop lap(2.8, "Intel Iris", 120, 8);
    GamingConsole gc(3.2, "Custom GPU", 200, 16);

    Computer* arr[3] = { &pc, &lap, &gc };

    for (int i = 0; i < 3; i++) {
        arr[i]->printType();
        size_t count;
        const MyString* per = arr[i]->getPeripherals(count);
        std::cout << "Peripherals: ";
        for (size_t j = 0; j < count; j++)
            std::cout << per[j] << " ";
        std::cout << "\n\n";
    }

    return 0;
}
