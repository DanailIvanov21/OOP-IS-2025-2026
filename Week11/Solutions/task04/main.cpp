bool removeCheapestSamsung(Store& s) {
    if (s.size == 0)
        return false;

    int index = -1;
    double bestPrice = 1e18;

    for (size_t i = 0; i < s.size; i++) {
        if (s.items[i]->getBrand() == "Samsung") {
            double price = s.items[i]->getPrice();
            if (price < bestPrice) {
                bestPrice = price;
                index = i;
            }
        }
    }

    if (index == -1)
        return false; 

    
    s.usedBudget -= s.items[index]->getPrice();
    delete s.items[index];

    for (size_t j = index; j < s.size - 1; j++)
        s.items[j] = s.items[j + 1];

    s.size--;
    return true;
}

#include <iostream>
#include "Store.h"

int main() {
    Store s(2000); 

    s.add(new Phone("3310", "Nokia", 50));
    s.add(new Smartphone("S22", "Samsung", 600, "Android", 128));
    s.add(new Smartphone("A52", "Samsung", 300, "Android", 64));
    s.add(new Smartphone("iPhone 12", "Apple", 800, "iOS", 128));

    std::cout << "Store inventory:\n";
    s.print();

    std::cout << "\nRemoving cheapest Samsung...\n";
    removeCheapestSamsung(s);

    std::cout << "\nAfter removal:\n";
    s.print();

    std::cout << "\nRemaining budget: " << s.getRemainingBudget() << "\n";

    return 0;
}
