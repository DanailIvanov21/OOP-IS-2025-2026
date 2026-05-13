#include <iostream>
#include <fstream>
#include "TechnoShop.h"

int main() {
    TechnoShop shop("TechnoMax");

    Phone p("S22", "Samsung", 1200, 3, SecurityLockType::FaceRecognition);
    Laptop l("Legion5", "Lenovo", 2500, OSType::Windows, false, 4);

    shop.addDevice(p);
    shop.addDevice(l);

    std::cout << "Initial shop:\n";
    shop.printAll(std::cout);

    std::ofstream ofs("shop.txt");
    shop.saveToFile(ofs);
    ofs.close();

    TechnoShop loaded;
    std::ifstream ifs("shop.txt");
    loaded.loadFromFile(ifs);
    ifs.close();

    std::cout << "\nLoaded shop:\n";
    loaded.printAll(std::cout);

    loaded.removeDevice("S22", "Samsung");
    std::cout << "\nAfter removing S22 Samsung:\n";
    loaded.printAll(std::cout);

    return 0;
}
