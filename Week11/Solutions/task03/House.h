#pragma once
#include "Building.h"

class House : public Building {
private:
    int floors;
    MyString owner;
    int people;
    int houseNumber;        
    static int counter;     

public:
    House();
    House(int h, double a, const MyString& addr,
          int floors, const MyString& owner, int people);

    
    //House(const House& other) = default;
    //House& operator=(const House& other) = default;
    //~House() = default;

    
    int getFloors() const;
    const MyString& getOwner() const;
    int getPeople() const;
    int getHouseNumber() const;

    
    void setFloors(int f);
    void setOwner(const MyString& o);
    void setPeople(int p);

   
    House& operator+=(int p);   
    House operator+(int p) const;

    House& operator-=(int p);   
    House operator-(int p) const;

    friend std::ostream& operator<<(std::ostream& os, const House& h);
    friend std::istream& operator>>(std::istream& is, House& h);
};

