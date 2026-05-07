#include "Bicycle.h"

Bicycle::Bicycle()
    : Vehicle(Color::Black, "Generic", 2000, 1, 30),
      gears(1), hasLights(false), hasBell(false) {}

Bicycle::Bicycle(Color c, const MyString& b, int y, int s, int m,
                 int g, bool lights, bool bell)
    : Vehicle(c, b, y, s, m),
      gears(g), hasLights(lights), hasBell(bell) {}

int Bicycle::getGears() const { return gears; }
bool Bicycle::getHasLights() const { return hasLights; }
bool Bicycle::getHasBell() const { return hasBell; }

void Bicycle::setGears(int g) { gears = g; }
void Bicycle::setHasLights(bool l) { hasLights = l; }
void Bicycle::setHasBell(bool b) { hasBell = b; }

std::ostream& operator<<(std::ostream& os, const Bicycle& b) {
    os << (const Vehicle&)b
       << ", Gears: " << b.gears
       << ", Lights: " << b.hasLights
       << ", Bell: " << b.hasBell;
    return os;
}
