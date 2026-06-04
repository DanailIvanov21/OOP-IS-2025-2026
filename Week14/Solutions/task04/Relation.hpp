#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>

template <typename T>
class Relation {
private:
    T subject;
    T object;
    char* relation;

    void freeDynamic();
    void copyDynamic(const Relation<T>& other);

public:
    Relation(const T& s, const T& o, const char* rel);
    Relation(const Relation<T>& other);
    Relation<T>& operator=(const Relation<T>& other);
    ~Relation();

    void print() const;

    Relation<T> operator*(const Relation<T>& other) const;
};

template <typename T>
void Relation<T>::freeDynamic() {
    delete[] relation;
    relation = nullptr;
}

template <typename T>
void Relation<T>::copyDynamic(const Relation<T>& other) {
    char* newRel = new char[strlen(other.relation) + 1];
    strcpy(newRel, other.relation);

    freeDynamic();
    relation = newRel;

    subject = other.subject;
    object = other.object;
}

template <typename T>
Relation<T>::Relation(const T& s, const T& o, const char* rel)
    : subject(s), object(o), relation(nullptr) 
{
    if (!rel) throw std::invalid_argument("Null relation string");

    relation = new char[strlen(rel) + 1];
    strcpy(relation, rel);
}

template <typename T>
Relation<T>::Relation(const Relation<T>& other)
    : subject(other.subject), object(other.object), relation(nullptr) 
{
    copyDynamic(other);
}

template <typename T>
Relation<T>& Relation<T>::operator=(const Relation<T>& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

template <typename T>
Relation<T>::~Relation() {
    freeDynamic();
}

template <typename T>
void Relation<T>::print() const {
    std::cout << subject << " " << relation << " " << object << ".\n";
}

template <typename T>
Relation<T> Relation<T>::operator*(const Relation<T>& other) const {
    if (object != other.subject)
        return *this;

    size_t len1 = strlen(relation);
    size_t len2 = strlen(other.relation);

    char* newRel = new char[len1 + len2 + 20];

    strcpy(newRel, relation);
    strcat(newRel, ", which ");
    strcat(newRel, other.relation);

    Relation<T> result(subject, other.object, newRel);

    delete[] newRel;

    return result;
}
