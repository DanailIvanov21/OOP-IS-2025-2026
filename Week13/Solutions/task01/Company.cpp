#include "Company.h"
#include <iostream>
#include <cstring>

void Company::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;

    arr = nullptr;
    size = 0;
    capacity = 0;
}

void Company::copyDynamic(const Company& other) {
    Employee** newArr = new Employee*[other.capacity];
    size_t i = 0;

    try {
        for (; i < other.size; i++)
            newArr[i] = other.arr[i]->clone();
    } catch (...) {
        for (size_t j = 0; j < i; j++)
            delete newArr[j];
        delete[] newArr;
        throw;
    }

    freeDynamic();
    arr = newArr;
    size = other.size;
    capacity = other.capacity;
}

void Company::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    Employee** newArr = new Employee*[newCap];

    for (size_t i = 0; i < size; i++)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
    capacity = newCap;
}

Company::Company()
    : arr(nullptr), size(0), capacity(0) {}

Company::Company(const Company& other)
    : arr(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

Company& Company::operator=(const Company& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

Company::~Company() {
    freeDynamic();
}

void Company::insertSorted(Employee* e) {
    if (size == capacity)
        resize();

    size_t pos = 0;
    while (pos < size && arr[pos]->getSalary() < e->getSalary())
        pos++;

    for (size_t i = size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = e;
    size++;
}

void Company::addWorker(const Worker& w) {
    insertSorted(w.clone());
}

void Company::addTrainee(const Trainee& t) {
    insertSorted(t.clone());
}

void Company::addPaidTrainee(const PaidTrainee& pt) {
    insertSorted(pt.clone());
}

double Company::averageSalary() const {
    if (size == 0) return 0;
    double sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += arr[i]->getSalary();
    return sum / size;
}

bool Company::TwoSum(double val) const {
    if (size < 2) return false;

    size_t l = 0, r = size - 1;

    while (l < r) {
        double sum = arr[l]->getSalary() + arr[r]->getSalary();
        if (sum == val) return true;
        if (sum < val) l++;
        else r--;
    }
    return false;
}

void Company::print() const {
    for (size_t i = 0; i < size; i++) {
        arr[i]->printType();
        std::cout << arr[i]->getName()
                  << " | salary: " << arr[i]->getSalary() << "\n";
    }
}
