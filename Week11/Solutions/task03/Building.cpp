#include "Building.h"

Building::Building()
    : height(0), area(0.0), address("Unknown") {}

Building::Building(int h, double a, const MyString& addr)
    : height(h), area(a), address(addr) {}

int Building::getHeight() const { return height; }
double Building::getArea() const { return area; }
const MyString& Building::getAddress() const { return address; }

void Building::setHeight(int h) { height = h; }
void Building::setArea(double a) { area = a; }
void Building::setAddress(const MyString& addr) { address = addr; }

std::ostream& operator<<(std::ostream& os, const Building& b) {
    os << "Height: " << b.height
       << " m, Area: " << b.area
       << " m2, Address: " << b.address;
    return os;
}

std::istream& operator>>(std::istream& is, Building& b) {
    is >> b.height >> b.area >> b.address;
    return is;
}
