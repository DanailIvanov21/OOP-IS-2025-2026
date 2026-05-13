#include "RadioButton.h"
#include <iostream>

void RadioButton::freeDynamic() {
    delete[] options;
    options = nullptr;
    count = 0;
}

void RadioButton::copyDynamic(const RadioButton& other) {
    MyString* newArr = new MyString[other.count];
    for (size_t i = 0; i < other.count; i++)
        newArr[i] = other.options[i];

    freeDynamic();
    options = newArr;
    count = other.count;
    selected = other.selected;
}

RadioButton::RadioButton(int w, int h, int x, int y,
                         const MyString* opts, size_t cnt, size_t sel)
    : Control(w, h, x, y), options(nullptr), count(cnt), selected(sel) {
    options = new MyString[cnt];
    for (size_t i = 0; i < cnt; i++)
        options[i] = opts[i];
}

RadioButton::RadioButton(const RadioButton& other)
    : Control(other), options(nullptr), count(0), selected(0) {
    copyDynamic(other);
}

RadioButton& RadioButton::operator=(const RadioButton& other) {
    if (this != &other) {
        Control::operator=(other);
        copyDynamic(other);
    }
    return *this;
}

RadioButton::~RadioButton() {
    freeDynamic();
}

void RadioButton::setSelected(size_t s) {
    if (s >= count) throw "Invalid option index";
    selected = s;
}

size_t RadioButton::getSelected() const { return selected; }

void RadioButton::setDataDialog() {
    std::cout << "Choose option:\n";
    for (size_t i = 0; i < count; i++)
        std::cout << i << ": " << options[i] << "\n";

    size_t s;
    std::cin >> s;
    setSelected(s);
}

void RadioButton::print() const {
    std::cout << "RadioButton [" << x << "," << y << "] "
              << width << "x" << height
              << " selected=" << selected
              << " (" << options[selected] << ")\n";
}

Control* RadioButton::clone() const {
    return new RadioButton(*this);
}
