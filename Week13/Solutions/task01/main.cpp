#include <iostream>
#include "Company.h"

int main() {
    Company c;

    c.addWorker(Worker("Ivan", 30, 2000, 24));
    c.addTrainee(Trainee("Petar", 22, 900, 60));
    c.addPaidTrainee(PaidTrainee("Maria", 25, 1500, 12, 30, 88));

    c.print();

    std::cout << "Average salary: " << c.averageSalary() << "\n";

    std::cout << "TwoSum(2400): "
              << (c.TwoSum(2400) ? "YES" : "NO") << "\n";

    return 0;
}
