#include "House.h"

int House::counter = 0;

House::House()
    : Building(), floors(0), owner("Unknown"), people(0) {
    houseNumber = ++counter;
}

House::House(int h, double a, const MyString& addr,
             int f, const MyString& o, int p)
    : Building(h, a, addr),
      floors(f), owner(o), people(p) {
    houseNumber = ++counter;
}

int House::getFloors() const { return floors; }
const MyString& House::getOwner() const { return owner; }
int House::getPeople() const { return people; }
int House::getHouseNumber() const { return houseNumber; }

void House::setFloors(int f) { floors = f; }
void House::setOwner(const MyString& o) { owner = o; }
void House::setPeople(int p) { people = p; }

House& House::operator+=(int p) {
    if (p < 0) throw std::invalid_argument("Cannot add negative people");
    people += p;
    return *this;
}

House House::operator+(int p) const {
    House temp(*this);
    temp += p;
    return temp;
}

House& House::operator-=(int p) {
    if (p < 0) throw std::invalid_argument("Cannot remove negative people");
    if (p > people) throw std::invalid_argument("Not enough people to remove");
    people -= p;
    return *this;
}

House House::operator-(int p) const {
    House temp(*this);
    temp -= p;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const House& h) {
    os << (const Building&)h
       << ", Floors: " << h.floors
       << ", Owner: " << h.owner
       << ", People: " << h.people
       << ", HouseNumber: " << h.houseNumber;
    return os;
}

std::istream& operator>>(std::istream& is, House& h) {
    is >> (Building&)h >> h.floors >> h.owner >> h.people;
    return is;
}
