#include "Worker.h"
#include <iostream>
#include <stdexcept>

Worker::Worker(const char* n, int a, double s, int m)
    : Employee(n, a, s), monthsWorked(m) {
    if (m < 0) throw std::invalid_argument("Invalid months");
}

int Worker::getMonthsWorked() const { return monthsWorked; }

void Worker::setMonthsWorked(int m) {
    if (m < 0) throw std::invalid_argument("Invalid months");
    monthsWorked = m;
}

void Worker::printType() const {
    std::cout << "Worker\n";
}

Employee* Worker::clone() const {
    return new Worker(*this);
}
