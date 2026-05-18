#pragma once
#include "Employee.h"

class Trainee : virtual public Employee {
protected:
    int daysLeft;

public:
    Trainee(const char* n = "", int a = 0, double s = 0, int d = 0);

    int getDaysLeft() const;
    void setDaysLeft(int d);

    void printType() const override;
    Employee* clone() const override;
};
