#include "Teacher.h"
#include <iostream>
#include <stdexcept>

Teacher::Teacher(const char* n, double sal)
    : Person(n), salary(sal) {
    if (sal < 0) throw std::invalid_argument("Invalid salary");
}

double Teacher::getSalary() const {
    return salary;
}

void Teacher::print() const {
    std::cout << "Teacher: " << name << ", salary=" << salary << "\n";
}
