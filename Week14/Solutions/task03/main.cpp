#include <iostream>
#include "Sorted.hpp"

int main() {
    Sorted<int, 10> s;

    s.add(5);
    s.add(1);
    s.add(7);
    s.add(3);

    std::cout << "Sorted elements:\n";
    s.print();

    std::cout << "\nRemoving 5...\n";
    s.remove(5);

    s.print();

    return 0;
}
