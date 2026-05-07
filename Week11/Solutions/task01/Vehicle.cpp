#include "Vehicle.h"

Vehicle::Vehicle()
    : color(Color::Unknown), brand("Unknown"), year(0), seats(0), maxSpeed(0) {}

Vehicle::Vehicle(Color c, const MyString& b, int y, int s, int m)
    : color(c), brand(b), year(y), seats(s), maxSpeed(m) {}

Color Vehicle::getColor() const { return color; }
const MyString& Vehicle::getBrand() const { return brand; }
int Vehicle::getYear() const { return year; }
int Vehicle::getSeats() const { return seats; }
int Vehicle::getMaxSpeed() const { return maxSpeed; }

void Vehicle::setColor(Color c) { color = c; }
void Vehicle::setBrand(const MyString& b) { brand = b; }
void Vehicle::setYear(int y) { year = y; }
void Vehicle::setSeats(int s) { seats = s; }
void Vehicle::setMaxSpeed(int m) { maxSpeed = m; }

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << "Brand: " << v.brand
       << ", Year: " << v.year
       << ", Seats: " << v.seats
       << ", MaxSpeed: " << v.maxSpeed;
    return os;
}
