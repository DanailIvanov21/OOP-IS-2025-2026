#include "Person.h"
#include <cstring>
#include <stdexcept>

void Person::freeDynamic() {
    delete[] name;
    name = nullptr;
}

void Person::copyDynamic(const Person& other) {
    char* newName = new char[strlen(other.name) + 1];
    strcpy(newName, other.name);

    freeDynamic();
    name = newName;
}

Person::Person(const char* n) : name(nullptr) {
    if (!n) throw std::invalid_argument("Null name");
    setName(n);
}

Person::Person(const Person& other) : name(nullptr) {
    copyDynamic(other);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        Person temp(other);
        freeDynamic();
        name = temp.name;
        temp.name = nullptr;
    }
    return *this;
}

Person::~Person() {
    freeDynamic();
}

const char* Person::getName() const {
    return name;
}

void Person::setName(const char* n) {
    char* newName = new char[strlen(n) + 1];
    strcpy(newName, n);
    delete[] name;
    name = newName;
}
