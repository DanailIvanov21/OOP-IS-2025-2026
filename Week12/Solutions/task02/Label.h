#pragma once
#include "Control.h"

class Label : public Control {
private:
    MyString text;

public:
    Label(int w, int h, int x, int y, const MyString& t);

    void setText(const MyString& t);
    const MyString& getText() const;

    void setDataDialog() override;
    void print() const override;
    Control* clone() const override;
};
