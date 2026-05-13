#pragma once
#include "Computer.h"

class ComputerCollection {
private:
    Computer** items;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const ComputerCollection& other);
    void resize();

public:
    ComputerCollection();
    ComputerCollection(const ComputerCollection& other);
    ComputerCollection& operator=(const ComputerCollection& other);
    ~ComputerCollection();

    void add(const Computer& c);
    bool removeByVideo(const char* videoModel);
    void printAll() const;
};
