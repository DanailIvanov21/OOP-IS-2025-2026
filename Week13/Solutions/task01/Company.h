#pragma once
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"

class Company {
private:
    Employee** arr;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const Company& other);
    void resize();
    void insertSorted(Employee* e);

public:
    Company();
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void addWorker(const Worker& w);
    void addTrainee(const Trainee& t);
    void addPaidTrainee(const PaidTrainee& pt);

    double averageSalary() const;
    bool TwoSum(double val) const;

    void print() const;
};
