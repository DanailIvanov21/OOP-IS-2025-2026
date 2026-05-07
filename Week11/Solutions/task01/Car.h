#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
private:
    MyString model;
    int doors;
    int horsepower;

public:
    Car();
    Car(Color c, const MyString& b, int y, int s, int m,
        const MyString& model, int doors, int hp);

    //Car(const Car& other) = default;
    //Car& operator=(const Car& other) = default;
    //~Car() = default;

    const MyString& getModel() const;
    int getDoors() const;
    int getHorsepower() const;

    void setModel(const MyString& m);
    void setDoors(int d);
    void setHorsepower(int hp);

    friend std::ostream& operator<<(std::ostream& os, const Car& c);
};
