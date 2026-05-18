#pragma once
#include "Employee.h"

class Worker : virtual public Employee {
protected:
    int monthsWorked;

public:
    Worker(const char* n = "", int a = 0, double s = 0, int m = 0);

    int getMonthsWorked() const;
    void setMonthsWorked(int m);

    void printType() const override;
    Employee* clone() const override;
};
