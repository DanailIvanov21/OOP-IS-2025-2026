#pragma once
#include "Device.h"

class Laptop : public Device {
private:
    int speedMHz;

public:
    Laptop();
    Laptop(const MyString& m, int speed);

    int getSpeed() const;
    void setSpeed(int s);

    void print() const;
    int get_perf() const;
};
