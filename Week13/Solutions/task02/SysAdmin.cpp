#include "SysAdmin.h"

SysAdmin::SysAdmin(const char* n, const char* ph, const char* addr,
                   int exp, double sal)
    : Employee(n, ph, addr, exp, sal) {}

void SysAdmin::increaseSalary() {
    salary += 250;
}

Employee* SysAdmin::clone() const {
    return new SysAdmin(*this);
}
