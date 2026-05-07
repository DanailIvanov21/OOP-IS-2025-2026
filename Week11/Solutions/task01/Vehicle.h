#pragma once
#include <iostream>
#include "MyString.h" // Week 10
#include "Color.h"

class Vehicle {
private:
    Color color;
    MyString brand;
    int year;
    int seats;
    int maxSpeed;

public:
    Vehicle();
    Vehicle(Color c, const MyString& b, int y, int s, int m);

    //Vehicle(const Vehicle& other) = default;
    //Vehicle& operator=(const Vehicle& other) = default;
    //~Vehicle() = default;

    Color getColor() const;
    const MyString& getBrand() const;
    int getYear() const;
    int getSeats() const;
    int getMaxSpeed() const;

    void setColor(Color c);
    void setBrand(const MyString& b);
    void setYear(int y);
    void setSeats(int s);
    void setMaxSpeed(int m);

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
};
