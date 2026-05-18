#include "Student.h"
#include <iostream>
#include <stdexcept>

Student::Student(const char* n, int fn)
    : Person(n), facultyNumber(fn) {
    if (fn <= 0) throw std::invalid_argument("Invalid faculty number");
}

int Student::getFN() const {
    return facultyNumber;
}

void Student::print() const {
    std::cout << "Student: " << name << ", FN=" << facultyNumber << "\n";
}
