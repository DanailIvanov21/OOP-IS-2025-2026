#include "Laptop.h"

Laptop::Laptop(double cpu, const char* video, int psu, int ram)
    : Computer(cpu, video, psu, ram) {
    perCount = 3;
    peripherals = new MyString[3]{
        "MousePad", "Keyboard", "Monitor"
    };
}

void Laptop::printType() const {
    std::cout << "Laptop\n";
}

const MyString* Laptop::getPeripherals(size_t& count) const {
    count = perCount;
    return peripherals;
}

Computer* Laptop::clone() const {
    return new Laptop(*this);
}
