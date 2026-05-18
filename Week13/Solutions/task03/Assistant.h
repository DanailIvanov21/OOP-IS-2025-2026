#pragma once
#include "Student.h"
#include "Teacher.h"

class Assistant : public Student, public Teacher {
public:
    Assistant(const char* n, int fn, double sal);

    void print() const override;
};
