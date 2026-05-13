#include "Control.h"
#include <stdexcept>

Control::Control(int w, int h, int x, int y)
    : width(w), height(h), x(x), y(y) {
    if (w < 0 || h < 0)
        throw std::invalid_argument("Invalid control size");
    if (x < 0 || y < 0)
        throw std::invalid_argument("Invalid control location");
}

int Control::getWidth() const { return width; }
int Control::getHeight() const { return height; }
int Control::getX() const { return x; }
int Control::getY() const { return y; }

void Control::setSize(int w, int h) {
    if (w < 0 || h < 0)
        throw std::invalid_argument("Invalid size");
    width = w;
    height = h;
}

void Control::setLocation(int nx, int ny) {
    if (nx < 0 || ny < 0)
        throw std::invalid_argument("Invalid location");
    x = nx;
    y = ny;
}
