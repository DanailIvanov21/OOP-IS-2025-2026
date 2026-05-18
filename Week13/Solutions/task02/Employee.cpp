#include "Employee.h"
#include <cstring>
#include <stdexcept>

void Employee::freeDynamic() {
    delete[] name;
    delete[] phone;
    delete[] address;

    name = nullptr;
    phone = nullptr;
    address = nullptr;
}

void Employee::copyDynamic(const Employee& other) {
    char* newName = new char[strlen(other.name) + 1];
    strcpy(newName, other.name);

    char* newPhone = new char[strlen(other.phone) + 1];
    strcpy(newPhone, other.phone);

    char* newAddr = new char[strlen(other.address) + 1];
    strcpy(newAddr, other.address);

    freeDynamic();
    name = newName;
    phone = newPhone;
    address = newAddr;
}

Employee::Employee(const char* n, const char* ph, const char* addr,
                   int exp, double sal)
    : name(nullptr), phone(nullptr), address(nullptr),
      experienceYears(exp), salary(sal) {
    if (exp < 0) throw std::invalid_argument("Invalid experience");
    if (sal < 0) throw std::invalid_argument("Invalid salary");

    setName(n);
    setPhone(ph);
    setAddress(addr);
}

Employee::Employee(const Employee& other)
    : name(nullptr), phone(nullptr), address(nullptr),
      experienceYears(other.experienceYears), salary(other.salary) {
    copyDynamic(other);
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        Employee temp(other);
        freeDynamic();

        name = temp.name;
        phone = temp.phone;
        address = temp.address;

        temp.name = nullptr;
        temp.phone = nullptr;
        temp.address = nullptr;

        experienceYears = temp.experienceYears;
        salary = temp.salary;
    }
    return *this;
}

Employee::~Employee() {
    freeDynamic();
}

const char* Employee::getName() const { return name; }
const char* Employee::getPhone() const { return phone; }
const char* Employee::getAddress() const { return address; }
int Employee::getExperience() const { return experienceYears; }
double Employee::getSalary() const { return salary; }

void Employee::setName(const char* n) {
    if (!n) throw std::invalid_argument("Null name");
    char* newName = new char[strlen(n) + 1];
    strcpy(newName, n);
    delete[] name;
    name = newName;
}

void Employee::setPhone(const char* p) {
    if (!p) throw std::invalid_argument("Null phone");
    char* newPhone = new char[strlen(p) + 1];
    strcpy(newPhone, p);
    delete[] phone;
    phone = newPhone;
}

void Employee::setAddress(const char* a) {
    if (!a) throw std::invalid_argument("Null address");
    char* newAddr = new char[strlen(a) + 1];
    strcpy(newAddr, a);
    delete[] address;
    address = newAddr;
}

void Employee::setExperience(int e) {
    if (e < 0) throw std::invalid_argument("Invalid experience");
    experienceYears = e;
}

void Employee::setSalary(double s) {
    if (s < 0) throw std::invalid_argument("Invalid salary");
    salary = s;
}
