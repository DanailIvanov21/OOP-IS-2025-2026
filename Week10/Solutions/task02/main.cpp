#include <iostream>
#include "Matrix.h"

int main() {
    Matrix A(2, 2);
    std::cout << "Enter matrix A:\n";
    std::cin >> A;

    Matrix B(2, 2);
    std::cout << "Enter matrix B:\n";
    std::cin >> B;

    std::cout << "\nA:\n" << A;
    std::cout << "\nB:\n" << B;

    Matrix C = A + B;
    std::cout << "\nA + B:\n" << C;

    Matrix D = A * B;
    std::cout << "\nA * B:\n" << D;

    ++A;
    std::cout << "\nA + I:\n" << A;

    Matrix T = ~A;
    std::cout << "\nTranspose of A:\n" << T;

    std::cout << "\nA symmetric? " << A.isSymmetric() << "\n";

    return 0;
}
