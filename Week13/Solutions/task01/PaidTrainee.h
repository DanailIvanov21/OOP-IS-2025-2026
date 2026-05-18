#pragma once
#include "Worker.h"
#include "Trainee.h"

class PaidTrainee : public Worker, public Trainee {
private:
    double rating;

public:
    PaidTrainee(const char* n = "", int a = 0, double s = 0,
                int months = 0, int days = 0, double r = 0);

    double getRating() const;
    void setRating(double r);

    void printType() const override;
    Employee* clone() const override;
};
