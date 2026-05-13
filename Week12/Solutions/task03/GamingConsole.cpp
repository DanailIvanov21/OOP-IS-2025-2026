#include "GamingConsole.h"

GamingConsole::GamingConsole(double cpu, const char* video, int psu, int ram)
    : Computer(cpu, video, psu, ram) {
    perCount = 2;
    peripherals = new MyString[2]{
        "Joystick", "Monitor"
    };
}

void GamingConsole::printType() const {
    std::cout << "GamingConsole\n";
}

const MyString* GamingConsole::getPeripherals(size_t& count) const {
    count = perCount;
    return peripherals;
}

Computer* GamingConsole::clone() const {
    return new GamingConsole(*this);
}
