#include <iostream>
#include "Vehicle.h"
#include "Bicycle.h"
#include "Car.h"

int main() {
    Vehicle v(Color::Red, "Toyota", 2010, 5, 180);
    std::cout << v << "\n\n";

    Bicycle b(Color::Blue, "Cross", 2020, 1, 35, 21, true, true);
    std::cout << b << "\n\n";

    Car c(Color::Black, "BMW", 2018, 5, 250, "M3", 4, 420);
    std::cout << c << "\n\n";

    return 0;
}
