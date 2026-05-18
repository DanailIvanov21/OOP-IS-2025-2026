#pragma once
#include "Employee.h"

class Developer : virtual public Employee {
public:
    Developer(const char* n = "", const char* ph = "", const char* addr = "",
              int exp = 0, double sal = 0);

    void increaseSalary() override; 
    Employee* clone() const override;
};
