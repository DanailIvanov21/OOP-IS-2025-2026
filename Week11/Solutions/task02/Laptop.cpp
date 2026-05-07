#include "Laptop.h"
#include <iostream>

Laptop::Laptop()
    : Device("Unknown", DeviceType::Laptop), speedMHz(0) {}

Laptop::Laptop(const MyString& m, int speed)
    : Device(m, DeviceType::Laptop), speedMHz(speed) {}

int Laptop::getSpeed() const { return speedMHz; }
void Laptop::setSpeed(int s) { speedMHz = s; }

void Laptop::print() const {
    std::cout << "Laptop: " << manufacturer
              << ", Speed: " << speedMHz << " MHz\n";
}

int Laptop::get_perf() const {
    return speedMHz;
}
