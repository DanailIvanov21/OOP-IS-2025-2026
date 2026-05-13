#pragma once
#include "MyString.h"

class Computer {
protected:
    double cpuPower;
    char* videoModel;
    int psuPower;
    int ram;

    MyString* peripherals;
    size_t perCount;

    void freeDynamic();
    void copyDynamic(const Computer& other);

public:
    Computer(double cpu = 0, const char* video = "", int psu = 0, int ram = 0);
    Computer(const Computer& other);
    Computer& operator=(const Computer& other);
    virtual ~Computer();

    
    void setCpuPower(double p);
    void setVideoModel(const char* v);
    void setPsuPower(int p);
    void setRam(int r);

    
    double getCpuPower() const;
    const char* getVideoModel() const;
    int getPsuPower() const;
    int getRam() const;

    virtual void printType() const = 0;
    virtual const MyString* getPeripherals(size_t& count) const = 0;
    virtual Computer* clone() const = 0;
};
