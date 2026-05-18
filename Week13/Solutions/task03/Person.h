#pragma once
#include <iostream>

class Person {
protected:
    char* name;

    void freeDynamic();
    void copyDynamic(const Person& other);

public:
    Person(const char* n);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    const char* getName() const;

    virtual void print() const = 0;
};
