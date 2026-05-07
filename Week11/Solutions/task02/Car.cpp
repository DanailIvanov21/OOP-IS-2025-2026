#include "Car.h"
#include <iostream>

Car::Car()
    : Device("Unknown", DeviceType::Car),
      horsepower(0), engineVolume(0) {}

Car::Car(const MyString& m, int hp, int vol)
    : Device(m, DeviceType::Car),
      horsepower(hp), engineVolume(vol) {}

int Car::getHorsepower() const { return horsepower; }
int Car::getEngineVolume() const { return engineVolume; }

void Car::setHorsepower(int hp) { horsepower = hp; }
void Car::setEngineVolume(int vol) { engineVolume = vol; }

void Car::print() const {
    std::cout << "Car: " << manufacturer
              << ", Power: " << horsepower << " kW"
              << ", Volume: " << engineVolume << " cm3\n";
}

int Car::get_perf() const {
    return horsepower;
}
