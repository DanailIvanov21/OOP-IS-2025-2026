#include "Form.h"
#include <iostream>
#include <stdexcept>

void Form::freeDynamic() {
    for (size_t i = 0; i < size; i++)
        delete controls[i];
    delete[] controls;

    controls = nullptr;
    size = 0;
    capacity = 0;
}

void Form::copyDynamic(const Form& other) {
    Control** newArr = new Control*[other.capacity];
    size_t i = 0;

    try {
        for (; i < other.size; i++)
            newArr[i] = other.controls[i]->clone();
    } catch (...) {
        for (size_t j = 0; j < i; j++)
            delete newArr[j];
        delete[] newArr;
        throw;
    }

    freeDynamic();
    controls = newArr;
    size = other.size;
    capacity = other.capacity;
}

void Form::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    Control** newArr = new Control*[newCap];

    for (size_t i = 0; i < size; i++)
        newArr[i] = controls[i];

    delete[] controls;
    controls = newArr;
    capacity = newCap;
}

Form::Form(int w, int h, const MyString& n)
    : width(w), height(h), name(n),
      controls(nullptr), size(0), capacity(0) {
    if (w < 0 || h < 0)
        throw std::invalid_argument("Invalid form size");
}

Form::Form(const Form& other)
    : width(other.width), height(other.height), name(other.name),
      controls(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        name = other.name;
        copyDynamic(other);
    }
    return *this;
}

Form::~Form() {
    freeDynamic();
}

void Form::addControl(const Control& c) {
    if (size == capacity)
        resize();
    controls[size++] = c.clone();
}

void Form::change(size_t index) {
    if (index >= size)
        throw std::out_of_range("Invalid control index");
    controls[index]->setDataDialog();
}

void Form::moveControl(size_t index, int newX, int newY) {
    if (index >= size)
        throw std::out_of_range("Invalid control index");

    Control* c = controls[index];

    if (newX < 0 || newY < 0)
        throw std::invalid_argument("Invalid location");

    if (newX + c->getWidth() > width ||
        newY + c->getHeight() > height)
        throw std::invalid_argument("Control goes outside form");

    c->setLocation(newX, newY);
}

void Form::resizeControl(size_t index, int w, int h) {
    if (index >= size)
        throw std::out_of_range("Invalid control index");

    controls[index]->setSize(w, h);
}

void Form::setSize(int w, int h) {
    if (w < 0 || h < 0)
        throw std::invalid_argument("Invalid form size");
    width = w;
    height = h;
}

void Form::print() const {
    std::cout << "Form: " << name
              << " (" << width << "x" << height << ")\n";

    for (size_t i = 0; i < size; i++)
        controls[i]->print();
}
