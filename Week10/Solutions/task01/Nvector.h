#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>

class Nvector {
private:
    int* data;
    size_t size;

    void freeDynamic();
    void copyDynamic(const Nvector& other);

public:
    Nvector();
    Nvector(size_t n);
    Nvector(const Nvector& other);
    Nvector& operator=(const Nvector& other);
    ~Nvector();

    size_t getSize() const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    Nvector& operator+=(const Nvector& other);
    Nvector& operator-=(const Nvector& other);

    Nvector& operator*=(int scalar);

    double length() const;

    bool isParallel(const Nvector& other) const;
    bool isPerpendicular(const Nvector& other) const;

    friend Nvector operator+(const Nvector& lhs, const Nvector& rhs);
    friend Nvector operator-(const Nvector& lhs, const Nvector& rhs);
    friend Nvector operator*(const Nvector& lhs, int scalar);
    friend Nvector operator*(int scalar, const Nvector& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Nvector& v);
    friend std::istream& operator>>(std::istream& is, Nvector& v);
};
