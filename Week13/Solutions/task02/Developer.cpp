#include "Developer.h"

Developer::Developer(const char* n, const char* ph, const char* addr,
                     int exp, double sal)
    : Employee(n, ph, addr, exp, sal) {}

void Developer::increaseSalary() {
    salary += 500;
}

Employee* Developer::clone() const {
    return new Developer(*this);
}
