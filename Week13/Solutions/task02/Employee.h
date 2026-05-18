#pragma once
#include <iostream>

class Employee {
protected:
    char* name;
    char* phone;
    char* address;
    int experienceYears;
    double salary;

    void freeDynamic();
    void copyDynamic(const Employee& other);

public:
    Employee(const char* n = "", const char* ph = "", const char* addr = "",
             int exp = 0, double sal = 0);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee();

    const char* getName() const;
    const char* getPhone() const;
    const char* getAddress() const;
    int getExperience() const;
    double getSalary() const;

    void setName(const char* n);
    void setPhone(const char* p);
    void setAddress(const char* a);
    void setExperience(int e);
    void setSalary(double s);

    virtual void increaseSalary() = 0;
    virtual Employee* clone() const = 0;
};
