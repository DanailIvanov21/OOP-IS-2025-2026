#include "Employee.h"
#include <cstring>
#include <stdexcept>

void Employee::freeDynamic() {
    delete[] name;
    name = nullptr;
}

void Employee::copyDynamic(const Employee& other) {
    char* newName = new char[strlen(other.name) + 1];
    strcpy(newName, other.name);

    freeDynamic();
    name = newName;
}

Employee::Employee(const char* n, int a, double s)
    : name(nullptr), age(a), salary(s) {
    if (a < 0) throw std::invalid_argument("Invalid age");
    if (s < 0) throw std::invalid_argument("Invalid salary");

    setName(n);
}

Employee::Employee(const Employee& other)
    : name(nullptr), age(other.age), salary(other.salary) {
    copyDynamic(other);
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        Employee temp(other);
        freeDynamic();
        name = temp.name;
        temp.name = nullptr;

        age = temp.age;
        salary = temp.salary;
    }
    return *this;
}

Employee::~Employee() {
    freeDynamic();
}

const char* Employee::getName() const { return name; }
int Employee::getAge() const { return age; }
double Employee::getSalary() const { return salary; }

void Employee::setName(const char* n) {
    if (!n) throw std::invalid_argument("Null name");

    char* newName = new char[strlen(n) + 1];
    strcpy(newName, n);

    delete[] name;
    name = newName;
}

void Employee::setAge(int a) {
    if (a < 0) throw std::invalid_argument("Invalid age");
    age = a;
}

void Employee::setSalary(double s) {
    if (s < 0) throw std::invalid_argument("Invalid salary");
    salary = s;
}
