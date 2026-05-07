#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
    int gears;
    bool hasLights;
    bool hasBell;

public:
    Bicycle();
    Bicycle(Color c, const MyString& b, int y, int s, int m,
            int g, bool lights, bool bell);

  
    //Bicycle(const Bicycle& other) = default;
    //Bicycle& operator=(const Bicycle& other) = default;
    //~Bicycle() = default;

    int getGears() const;
    bool getHasLights() const;
    bool getHasBell() const;

    void setGears(int g);
    void setHasLights(bool l);
    void setHasBell(bool b);

    friend std::ostream& operator<<(std::ostream& os, const Bicycle& b);
};
