#pragma once
#include "Phone.h"

class Smartphone : public Phone {
private:
    MyString os;
    int memoryGB;

public:
    Smartphone();
    Smartphone(const MyString& m, const MyString& b, double price,
               const MyString& os, int mem);

    Smartphone(const Smartphone& other) = default;
    Smartphone& operator=(const Smartphone& other) = default;
    ~Smartphone() = default;

   
    const MyString& getOS() const;
    int getMemory() const;

   
    void setOS(const MyString& o);
    void setMemory(int m);

   
    double getPrice() const override;

    friend std::ostream& operator<<(std::ostream& os, const Smartphone& s);
};
