#include "PaidTrainee.h"
#include <iostream>
#include <stdexcept>

PaidTrainee::PaidTrainee(const char* n, int a, double s,
                         int months, int days, double r)
    : Employee(n, a, s),
      Worker(n, a, s, months),
      Trainee(n, a, s, days),
      rating(r) {
    if (r < 0 || r > 100)
        throw std::invalid_argument("Invalid rating");
}

double PaidTrainee::getRating() const { return rating; }

void PaidTrainee::setRating(double r) {
    if (r < 0 || r > 100)
        throw std::invalid_argument("Invalid rating");
    rating = r;
}

void PaidTrainee::printType() const {
    std::cout << "PaidTrainee\n";
}

Employee* PaidTrainee::clone() const {
    return new PaidTrainee(*this);
}
