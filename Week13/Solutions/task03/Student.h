#pragma once
#include "Person.h"

class Student : virtual public Person {
protected:
    int facultyNumber;

public:
    Student(const char* n, int fn);

    int getFN() const;

    void print() const override;
};
