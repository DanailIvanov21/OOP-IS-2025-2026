#pragma once
#include "Developer.h"
#include "SysAdmin.h"

class DeveloperSystemAdmin : public Developer, public SysAdmin {
public:
    DeveloperSystemAdmin(const char* n = "", const char* ph = "",
                         const char* addr = "", int exp = 0, double sal = 0);

    void increaseSalary() override; 
    Employee* clone() const override;
};
