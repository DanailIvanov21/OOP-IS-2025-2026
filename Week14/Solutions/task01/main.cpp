#include <iostream>
#include "Vector.hpp"

int main() {
    Vector<int> v;

    v.pushBack(10);
    v.pushBack(20);
    v.pushBack(30);

    v.pushAt(15, 1); // 10, 15, 20, 30

    v.popAt(2);      // 10, 15, 30

    v.popBack();     // 10, 15

    for (size_t i = 0; i < v.getSize(); i++)
        std::cout << v[i] << " ";

    std::cout << "\nEmpty? " << (v.empty() ? "yes" : "no") << "\n";

    v.clear();
    std::cout << "After clear, empty? " << (v.empty() ? "yes" : "no") << "\n";

    return 0;
}
