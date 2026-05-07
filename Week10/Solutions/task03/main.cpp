#include <iostream>
#include "Cake.h"

int main() {
    Cake c(500, 300, 200);

    std::cout << c << "\n";

    c /= 4; // divide into 4 pieces
    std::cout << "After /4: " << c << "\n";

    c += 2; // add 2 pieces
    std::cout << "After +2: " << c << "\n";

    c -= 3; // remove 3 pieces
    std::cout << "After -3: " << c << "\n";

    Cake d(500, 300, 200);
    d /= 4;

    std::cout << "c == d ? " << (c == d) << "\n";

    return 0;
}
