#pragma once
#include "Employee.h"

class SysAdmin : virtual public Employee {
public:
    SysAdmin(const char* n = "", const char* ph = "", const char* addr = "",
             int exp = 0, double sal = 0);

    void increaseSalary() override; 
    Employee* clone() const override;
};
