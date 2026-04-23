#include <iostream>
#include "Nvector.h"

int main() {
    Nvector v1(4);
    std::cin >> v1;

    Nvector v2(4);
    std::cin >> v2;

    Nvector sum = v1 + v2;
    std::cout << "v1 + v2 = " << sum << std::endl;

    std::cout << "Length (count of elements) = " << v1.length() << std::endl;

    std::cout << "Parallel? " << v1.isParallel(v2) << std::endl;
    std::cout << "Perpendicular? " << v1.isPerpendicular(v2) << std::endl;

    return 0;
}
