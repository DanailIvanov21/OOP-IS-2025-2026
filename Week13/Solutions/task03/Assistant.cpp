#include "Assistant.h"
#include <iostream>

Assistant::Assistant(const char* n, int fn, double sal)
    : Person(n), Student(n, fn), Teacher(n, sal) {}

void Assistant::print() const {
    std::cout << "Assistant: " << name
              << ", FN=" << facultyNumber
              << ", salary=" << salary << "\n";
}
