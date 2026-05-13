#pragma once
#include <iostream>

class Control {
protected:
    int width;
    int height;
    int x;
    int y;

public:
    Control(int w = 0, int h = 0, int x = 0, int y = 0);

    virtual ~Control() = default;

    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;

    void setSize(int w, int h);
    void setLocation(int nx, int ny);

    virtual void setDataDialog() = 0;
    virtual void print() const = 0;
    virtual Control* clone() const = 0;
};
