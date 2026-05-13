#pragma once
#include "Control.h"

class CheckBox : public Control {
private:
    MyString text;
    bool checked;

public:
    CheckBox(int w, int h, int x, int y, const MyString& t, bool c);

    void setChecked(bool c);
    bool isChecked() const;

    void setText(const MyString& t);
    const MyString& getText() const;

    void setDataDialog() override;
    void print() const override;
    Control* clone() const override;
};
