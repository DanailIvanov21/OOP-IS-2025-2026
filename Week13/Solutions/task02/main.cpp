#include <iostream>
#include "Developer.h"
#include "SysAdmin.h"
#include "DeveloperSystemAdmin.h"

int main() {
    Developer d("Ivan", "0888123456", "Sofia", 5, 2000);
    SysAdmin s("Petar", "0888999999", "Plovdiv", 3, 1800);
    DeveloperSystemAdmin ds("Maria", "0888777777", "Varna", 4, 2200);

    d.increaseSalary();
    s.increaseSalary();
    ds.increaseSalary();

    std::cout << d.getName() << " salary: " << d.getSalary() << "\n";
    std::cout << s.getName() << " salary: " << s.getSalary() << "\n";
    std::cout << ds.getName() << " salary: " << ds.getSalary() << "\n";

    return 0;
}
