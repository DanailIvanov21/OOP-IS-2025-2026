#include "CheckBox.h"
#include <iostream>

CheckBox::CheckBox(int w, int h, int x, int y, const MyString& t, bool c)
    : Control(w, h, x, y), text(t), checked(c) {}

void CheckBox::setChecked(bool c) { checked = c; }
bool CheckBox::isChecked() const { return checked; }

void CheckBox::setText(const MyString& t) { text = t; }
const MyString& CheckBox::getText() const { return text; }

void CheckBox::setDataDialog() {
    std::cout << "Toggle checkbox (0/1): ";
    int v;
    std::cin >> v;
    checked = (v != 0);
}

void CheckBox::print() const {
    std::cout << "CheckBox [" << x << "," << y << "] "
              << width << "x" << height
              << " text=" << text
              << " checked=" << (checked ? "true" : "false") << "\n";
}

Control* CheckBox::clone() const {
    return new CheckBox(*this);
}
