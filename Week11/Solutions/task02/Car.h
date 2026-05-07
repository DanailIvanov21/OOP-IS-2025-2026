#pragma once
#include "Device.h"

class Car : public Device {
private:
    int horsepower;
    int engineVolume;

public:
    Car();
    Car(const MyString& m, int hp, int vol);

    int getHorsepower() const;
    int getEngineVolume() const;

    void setHorsepower(int hp);
    void setEngineVolume(int vol);

    void print() const;
    int get_perf() const;
};
