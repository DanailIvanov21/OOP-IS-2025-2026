#include "Trainee.h"
#include <iostream>
#include <stdexcept>

Trainee::Trainee(const char* n, int a, double s, int d)
    : Employee(n, a, s), daysLeft(d) {
    if (d < 0) throw std::invalid_argument("Invalid days");
}

int Trainee::getDaysLeft() const { return daysLeft; }

void Trainee::setDaysLeft(int d) {
    if (d < 0) throw std::invalid_argument("Invalid days");
    daysLeft = d;
}

void Trainee::printType() const {
    std::cout << "Trainee\n";
}

Employee* Trainee::clone() const {
    return new Trainee(*this);
}
