#pragma once
#include "Control.h"
#include "MyString.h"

class Form {
private:
    int width;
    int height;
    MyString name;

    Control** controls;
    size_t size;
    size_t capacity;

    void freeDynamic();
    void copyDynamic(const Form& other);
    void resize();

public:
    Form(int w = 0, int h = 0, const MyString& n = "");
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    void addControl(const Control& c);

    void change(size_t index);                
    void moveControl(size_t index, int newX, int newY);
    void resizeControl(size_t index, int w, int h);

    void setSize(int w, int h);                
    void print() const;
};
