#pragma once
#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int** data;
    size_t rows;
    size_t cols;

    void freeDynamic();
    int** copyDynamic(const Matrix& other) const;

public:
    Matrix();
    Matrix(size_t r, size_t c);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    void init();

    size_t getRows() const;
    size_t getCols() const;

    int* operator[](size_t index);
    const int* operator[](size_t index) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(int scalar);
    Matrix& operator/=(int scalar);

    Matrix operator~() const;
    bool operator!() const;

    Matrix& operator++();     // prefix
    Matrix operator++(int);   // postfix

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, int scalar);
    friend Matrix operator*(int scalar, const Matrix& rhs);
    friend Matrix operator/(const Matrix& lhs, int scalar);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);

    bool isSymmetric() const;
};
