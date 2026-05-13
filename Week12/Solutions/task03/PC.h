#pragma once
#include "Computer.h"

class PC : public Computer {
public:
    PC(double cpu, const char* video, int psu, int ram);

    void printType() const override;
    const MyString* getPeripherals(size_t& count) const override;
    Computer* clone() const override;
};
