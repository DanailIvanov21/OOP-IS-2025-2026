#include "Car.h"

Car::Car()
    : Vehicle(Color::White, "Generic", 2005, 5, 180),
      model("Sedan"), doors(4), horsepower(100) {}

Car::Car(Color c, const MyString& b, int y, int s, int m,
         const MyString& mod, int d, int hp)
    : Vehicle(c, b, y, s, m),
      model(mod), doors(d), horsepower(hp) {}

const MyString& Car::getModel() const { return model; }
int Car::getDoors() const { return doors; }
int Car::getHorsepower() const { return horsepower; }

void Car::setModel(const MyString& m) { model = m; }
void Car::setDoors(int d) { doors = d; }
void Car::setHorsepower(int hp) { horsepower = hp; }

std::ostream& operator<<(std::ostream& os, const Car& c) {
    os << (const Vehicle&)c
       << ", Model: " << c.model
       << ", Doors: " << c.doors
       << ", HP: " << c.horsepower;
    return os;
}
