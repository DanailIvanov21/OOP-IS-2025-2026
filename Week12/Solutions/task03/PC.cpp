#include "PC.h"

PC::PC(double cpu, const char* video, int psu, int ram)
    : Computer(cpu, video, psu, ram) {
    perCount = 4;
    peripherals = new MyString[4]{
        "Mouse", "Keyboard", "Microphone", "Headphones"
    };
}

void PC::printType() const {
    std::cout << "PC\n";
}

const MyString* PC::getPeripherals(size_t& count) const {
    count = perCount;
    return peripherals;
}

Computer* PC::clone() const {
    return new PC(*this);
}
