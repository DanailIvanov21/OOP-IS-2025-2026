#pragma once
#include "Phone.h"
#include "Smartphone.h"

class Store {
private:
    Phone** items;
    size_t size;
    const double budget;   
    double usedBudget;

    void freeDynamic();
    void copyDynamic(const Store& other);

public:
    Store(double initialBudget);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store();

    bool add(Phone* p);  
    bool remove(const MyString& brand, const MyString& model);

    void print() const;
    double getRemainingBudget() const;

    friend bool removeCheapestSamsung(Store& s);
};
