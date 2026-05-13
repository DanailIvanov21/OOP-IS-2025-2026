#include "Label.h"
#include <iostream>

Label::Label(int w, int h, int x, int y, const MyString& t)
    : Control(w, h, x, y), text(t) {}

void Label::setText(const MyString& t) {
    text = t;
}

const MyString& Label::getText() const {
    return text;
}

void Label::setDataDialog() {
    std::cout << "Enter new label text: ";
    MyString newText;
    std::cin >> newText;
    text = newText;
}

void Label::print() const {
    std::cout << "Label [" << x << "," << y << "] "
              << width << "x" << height
              << " text=" << text << "\n";
}

Control* Label::clone() const {
    return new Label(*this);
}
