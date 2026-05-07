#include <iostream>
#include "House.h"

const House& findMostSpacious(const House* arr, size_t n) {
    if (n == 0)
        throw std::invalid_argument("Empty array");

    size_t best = 0;
    double bestRatio = (double)arr[0].getHeight() / arr[0].getFloors();

    for (size_t i = 1; i < n; i++) {
        double ratio = (double)arr[i].getHeight() / arr[i].getFloors();
        if (ratio > bestRatio) {
            bestRatio = ratio;
            best = i;
        }
    }
    return arr[best];
}


int main() {
    House arr[3] = {
        House(9, 120.5, "Sofia", 3, "Ivan", 4),
        House(12, 150.0, "Plovdiv", 4, "Maria", 5),
        House(15, 200.0, "Varna", 5, "Georgi", 6)
    };

    const House& best = findMostSpacious(arr, 3);

    std::cout << "Most spacious house:\n" << best << "\n";

    return 0;
}
