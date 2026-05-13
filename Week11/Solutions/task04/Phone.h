#pragma once
#include "MyString.h"
#include <iostream>

class Phone {
protected:
    MyString model;
    MyString brand;
    double basePrice;

public:
    Phone();
    Phone(const MyString& m, const MyString& b, double price);

    
    Phone(const Phone& other) = default;
    Phone& operator=(const Phone& other) = default;
    virtual ~Phone() = default;

    
    const MyString& getModel() const;
    const MyString& getBrand() const;
    double getBasePrice() const;

    
    void setModel(const MyString& m);
    void setBrand(const MyString& b);
    void setBasePrice(double p);

    virtual double getPrice() const;

    friend std::ostream& operator<<(std::ostream& os, const Phone& p);
};
