#include "Smartphone.h"

Smartphone::Smartphone()
    : Phone(), os("Unknown"), memoryGB(0) {}

Smartphone::Smartphone(const MyString& m, const MyString& b, double price,
                       const MyString& o, int mem)
    : Phone(m, b, price), os(o), memoryGB(mem) {}

const MyString& Smartphone::getOS() const { return os; }
int Smartphone::getMemory() const { return memoryGB; }

void Smartphone::setOS(const MyString& o) { os = o; }
void Smartphone::setMemory(int m) { memoryGB = m; }

double Smartphone::getPrice() const {
    return basePrice + memoryGB * 1.0; 
}

std::ostream& operator<<(std::ostream& os, const Smartphone& s) {
    os << s.brand << " " << s.model
       << " | OS: " << s.os
       << " | Memory: " << s.memoryGB << "GB"
       << " | Price: " << s.getPrice();
    return os;
}
