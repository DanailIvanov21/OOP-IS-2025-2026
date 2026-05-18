#include "DeveloperSystemAdmin.h"

DeveloperSystemAdmin::DeveloperSystemAdmin(const char* n, const char* ph,
                                           const char* addr, int exp, double sal)
    : Employee(n, ph, addr, exp, sal),
      Developer(n, ph, addr, exp, sal),
      SysAdmin(n, ph, addr, exp, sal) {}

void DeveloperSystemAdmin::increaseSalary() {
    Developer::increaseSalary(); 
}

Employee* DeveloperSystemAdmin::clone() const {
    return new DeveloperSystemAdmin(*this);
}
