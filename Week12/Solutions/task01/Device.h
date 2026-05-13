#pragma once
#include <iostream>

class Device {
protected:
    char* model;
    char* brand;
    int price;

    void copyDynamic(const Device& other);
    void freeDynamic();

public:
    Device();
    Device(const char* model, const char* brand, int price);
    Device(const Device& other);
    Device& operator=(const Device& other);
    virtual ~Device();

    const char* getModel() const;
    const char* getBrand() const;
    int getPrice() const;

    void setModel(const char* m);
    void setBrand(const char* b);
    void setPrice(int p);

    virtual void print(std::ostream& os) const = 0;
    virtual void saveToFile(std::ostream& os) const = 0;
    virtual void loadFromFile(std::istream& is) = 0;
    virtual Device* clone() const = 0;
};
