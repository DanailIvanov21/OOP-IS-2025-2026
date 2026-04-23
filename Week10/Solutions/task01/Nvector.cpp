#include "Nvector.h"
#include <cmath>

void Nvector::freeDynamic() {
    delete[] data;
    data = nullptr;
}

int* Nvector::copyDynamic(const Nvector& other) const {
    int* newData = new int[other.size];
    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[i];
    return newData;
}

Nvector::Nvector() : data(nullptr), size(0) {}

Nvector::Nvector(size_t n) : data(nullptr), size(n) {
    if (n == 0)
        throw std::invalid_argument("Vector size cannot be zero");

    data = new int[n];
    for (size_t i = 0; i < n; i++)
        data[i] = 0;
}

Nvector::Nvector(const Nvector& other) : data(nullptr), size(other.size) {
    data = copyDynamic(other);
}

Nvector& Nvector::operator=(const Nvector& other) {
    if (this != &other) {
        int* newData = copyDynamic(other);  

        freeDynamic();
        data = newData;
        size = other.size;
    }
    return *this;
}

Nvector::~Nvector() {
    freeDynamic();
}

size_t Nvector::getSize() const {
    return size;
}

size_t Nvector::length() const {
    return size; 
}

int& Nvector::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

const int& Nvector::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

Nvector& Nvector::operator+=(const Nvector& other) {
    if (size != other.size)
        throw std::invalid_argument("Vector sizes must match");

    int* newData = new int[size]; 

    for (size_t i = 0; i < size; i++)
        newData[i] = data[i] + other.data[i];

    freeDynamic();
    data = newData;

    return *this;
}

Nvector& Nvector::operator-=(const Nvector& other) {
    if (size != other.size)
        throw std::invalid_argument("Vector sizes must match");

    int* newData = new int[size];

    for (size_t i = 0; i < size; i++)
        newData[i] = data[i] - other.data[i];

    freeDynamic();
    data = newData;

    return *this;
}

Nvector& Nvector::operator*=(int scalar) {
    int* newData = new int[size];

    for (size_t i = 0; i < size; i++)
        newData[i] = data[i] * scalar;

    freeDynamic();
    data = newData;

    return *this;
}

bool Nvector::isParallel(const Nvector& other) const {
    if (size != other.size)
        throw std::invalid_argument("Vector sizes must match");

    double ratio = 0;
    bool ratioSet = false;

    for (size_t i = 0; i < size; i++) {
        if (data[i] == 0 && other.data[i] == 0)
            continue;

        if (data[i] == 0 || other.data[i] == 0)
            return false;

        double currentRatio = (double)data[i] / other.data[i];

        if (!ratioSet) {
            ratio = currentRatio;
            ratioSet = true;
        } else if (std::abs(currentRatio - ratio) > 1e-9)
            return false;
    }
    return true;
}

bool Nvector::isPerpendicular(const Nvector& other) const {
    if (size != other.size)
        throw std::invalid_argument("Vector sizes must match");

    long long dot = 0;
    for (size_t i = 0; i < size; i++)
        dot += 1LL * data[i] * other.data[i];

    return dot == 0;
}

Nvector operator+(const Nvector& lhs, const Nvector& rhs) {
    Nvector result(lhs);
    result += rhs;
    return result;
}

Nvector operator-(const Nvector& lhs, const Nvector& rhs) {
    Nvector result(lhs);
    result -= rhs;
    return result;
}

Nvector operator*(const Nvector& lhs, int scalar) {
    Nvector result(lhs);
    result *= scalar;
    return result;
}

Nvector operator*(int scalar, const Nvector& rhs) {
    return rhs * scalar;
}

std::ostream& operator<<(std::ostream& os, const Nvector& v) {
    for (size_t i = 0; i < v.size; i++)
        os << v.data[i] << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Nvector& v) {
    for (size_t i = 0; i < v.size; i++)
        is >> v.data[i];
    return is;
}
