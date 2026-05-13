#pragma once
#include "Control.h"

class RadioButton : public Control {
private:
    MyString* options;
    size_t count;
    size_t selected;

    void freeDynamic();
    void copyDynamic(const RadioButton& other);

public:
    RadioButton(int w, int h, int x, int y,
                const MyString* opts, size_t cnt, size_t sel);

    RadioButton(const RadioButton& other);
    RadioButton& operator=(const RadioButton& other);
    ~RadioButton();

    void setSelected(size_t s);
    size_t getSelected() const;

    void setDataDialog() override;
    void print() const override;
    Control* clone() const override;
};
