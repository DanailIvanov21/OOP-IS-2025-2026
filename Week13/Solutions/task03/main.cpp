#include <iostream>
#include <fstream>
#include "Assistant.h"

int main() {
    Assistant a("Ivan Petrov", 12345, 1800);

    std::cout << "Name: " << a.getName() << "\n";
    std::cout << "FN: " << a.getFN() << "\n";
    std::cout << "Salary: " << a.getSalary() << "\n";

    std::ofstream ofs("assistant.txt");
    ofs << "Name: " << a.getName() << "\n";
    ofs << "FN: " << a.getFN() << "\n";
    ofs << "Salary: " << a.getSalary() << "\n";
    ofs.close();

    return 0;
}
