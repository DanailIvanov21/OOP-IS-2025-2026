#pragma once
#include "Person.h"

class Teacher : virtual public Person {
protected:
    double salary;

public:
    Teacher(const char* n, double sal);

    double getSalary() const;

    void print() const override;
};
