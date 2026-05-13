#pragma once
#include "Device.h"

enum class OSType {
    MacOS = 0,
    Linux = 1,
    Windows = 2
};

class Laptop : public Device {
private:
    OSType os;
    bool hasThunderbolt;
    int ports;

public:
    Laptop();
    Laptop(const char* model, const char* brand, int price,
           OSType os, bool thunderbolt, int ports);

    Laptop(const Laptop& other) = default;
    Laptop& operator=(const Laptop& other) = default;
    ~Laptop() override = default;

    OSType getOS() const;
    bool getHasThunderbolt() const;
    int getPorts() const;

    void setOS(OSType o);
    void setHasThunderbolt(bool h);
    void setPorts(int p);

    void print(std::ostream& os) const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;
    Device* clone() const override;
};
