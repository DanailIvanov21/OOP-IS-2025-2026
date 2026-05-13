#pragma once
#include "Device.h"
#include "Phone.h"
#include "Laptop.h"

class TechnoShop {
private:
    char* name;
    Device** devices;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const TechnoShop& other);
    void resize();

public:
    TechnoShop();
    TechnoShop(const char* name);
    TechnoShop(const TechnoShop& other);
    TechnoShop& operator=(const TechnoShop& other);
    ~TechnoShop();

    const char* getName() const;
    void setName(const char* n);

    bool addDevice(const Device& d);                 
    bool removeDevice(const char* model, const char* brand);

    void printAll(std::ostream& os) const;

    void saveToFile(std::ostream& os) const;
    void loadFromFile(std::istream& is);
};
