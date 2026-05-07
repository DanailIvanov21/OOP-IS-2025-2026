#include "Device.h"

Device::Device()
    : manufacturer("Unknown"), type(DeviceType::Laptop) {}

Device::Device(const MyString& m, DeviceType t)
    : manufacturer(m), type(t) {}

const MyString& Device::getManufacturer() const { return manufacturer; }
DeviceType Device::getType() const { return type; }

void Device::setManufacturer(const MyString& m) { manufacturer = m; }
void Device::setType(DeviceType t) { type = t; }
