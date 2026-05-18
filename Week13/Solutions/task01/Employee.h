#pragma once
#include <iostream>

class Employee {
protected:
    char* name;
    int age;
    double salary;

    void copyDynamic(const Employee& other);
    void freeDynamic();

public:
    Employee(const char* n = "", int a = 0, double s = 0);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee();

    const char* getName() const;
    int getAge() const;
    double getSalary() const;

    void setName(const char* n);
    void setAge(int a);
    void setSalary(double s);

    virtual void printType() const = 0;
    virtual Employee* clone() const = 0;
};
