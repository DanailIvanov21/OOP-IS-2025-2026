#pragma once
#include "MyString.h" // Week 10

enum class DeviceType {
    Laptop,
    Car
};

class Device {
protected:
    MyString manufacturer;
    DeviceType type;

public:
    Device();
    Device(const MyString& m, DeviceType t);

    const MyString& getManufacturer() const;
    DeviceType getType() const;

    void setManufacturer(const MyString& m);
    void setType(DeviceType t);
};
