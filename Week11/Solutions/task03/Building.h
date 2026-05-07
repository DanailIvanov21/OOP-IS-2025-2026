#pragma once
#include <iostream>
#include "MyString.h"

class Building {
private:
    int height;       
    double area;       
    MyString address;  

public:
    Building();
    Building(int h, double a, const MyString& addr);

    
    //Building(const Building& other) = default;
    //Building& operator=(const Building& other) = default;
   // ~Building() = default;

    
    int getHeight() const;
    double getArea() const;
    const MyString& getAddress() const;

   
    void setHeight(int h);
    void setArea(double a);
    void setAddress(const MyString& addr);

    friend std::ostream& operator<<(std::ostream& os, const Building& b);
    friend std::istream& operator>>(std::istream& is, Building& b);
};
