#include "Matrix.h"

void Matrix::freeDynamic() {
    if (!data) return;
    for (size_t i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
    data = nullptr;
}

int** Matrix::copyDynamic(const Matrix& other) const {
    int** newData = new int*[other.rows];
    for (size_t i = 0; i < other.rows; i++) {
        newData[i] = new int[other.cols];
        for (size_t j = 0; j < other.cols; j++)
            newData[i][j] = other.data[i][j];
    }
    return newData;
}

Matrix::Matrix() : rows(2), cols(2) {
    data = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
            data[i][j] = 0;
    }
}

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c) {
    if (r == 0 || c == 0)
        throw std::invalid_argument("Invalid matrix size");

    data = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
            data[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = copyDynamic(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        int** newData = copyDynamic(other); // strong exception safety

        freeDynamic();
        data = newData;
        rows = other.rows;
        cols = other.cols;
    }
    return *this;
}

Matrix::~Matrix() {
    freeDynamic();
}

void Matrix::init() {
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            std::cin >> data[i][j];
}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getCols() const { return cols; }

int* Matrix::operator[](size_t index) {
    if (index >= rows)
        throw std::out_of_range("Row index out of range");
    return data[index];
}

const int* Matrix::operator[](size_t index) const {
    if (index >= rows)
        throw std::out_of_range("Row index out of range");
    return data[index];
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match");

    int** newData = copyDynamic(*this);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newData[i][j] += other.data[i][j];

    freeDynamic();
    data = newData;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match");

    int** newData = copyDynamic(*this);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newData[i][j] -= other.data[i][j];

    freeDynamic();
    data = newData;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (cols != other.rows)
        throw std::invalid_argument("Invalid matrix multiplication");

    Matrix result(rows, other.cols);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < other.cols; j++)
            for (size_t k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];

    *this = result;
    return *this;
}

Matrix& Matrix::operator*=(int scalar) {
    int** newData = copyDynamic(*this);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newData[i][j] *= scalar;

    freeDynamic();
    data = newData;
    return *this;
}

Matrix& Matrix::operator/=(int scalar) {
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");

    int** newData = copyDynamic(*this);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newData[i][j] /= scalar;

    freeDynamic();
    data = newData;
    return *this;
}

Matrix Matrix::operator~() const {
    Matrix t(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            t.data[j][i] = data[i][j];
    return t;
}

bool Matrix::operator!() const {
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (data[i][j] != 0)
                return true;
    return false;
}

Matrix& Matrix::operator++() {
    if (rows != cols)
        throw std::invalid_argument("Identity matrix requires square matrix");

    for (size_t i = 0; i < rows; i++)
        data[i][i] += 1;

    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix old(*this);
    ++(*this);
    return old;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        return false;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (data[i][j] != other.data[i][j])
                return false;

    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    result += rhs;
    return result;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    result -= rhs;
    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    result *= rhs;
    return result;
}

Matrix operator*(const Matrix& lhs, int scalar) {
    Matrix result(lhs);
    result *= scalar;
    return result;
}

Matrix operator*(int scalar, const Matrix& rhs) {
    return rhs * scalar;
}

Matrix operator/(const Matrix& lhs, int scalar) {
    Matrix result(lhs);
    result /= scalar;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++)
            os << m.data[i][j] << " ";
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    for (size_t i = 0; i < m.rows; i++)
        for (size_t j = 0; j < m.cols; j++)
            is >> m.data[i][j];
    return is;
}

bool Matrix::isSymmetric() const {
    if (rows != cols)
        return false;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = i + 1; j < cols; j++)
            if (data[i][j] != data[j][i])
                return false;

    return true;
}
