#include "Device.h"
#include <cstring>
#include <stdexcept>

void Device::freeDynamic() {
    delete[] model;
    delete[] brand;
    model = nullptr;
    brand = nullptr;
}

void Device::copyDynamic(const Device& other) {
    char* newModel = nullptr;
    char* newBrand = nullptr;

    if (other.model) {
        newModel = new char[std::strlen(other.model) + 1];
        std::strcpy(newModel, other.model);
    }
    if (other.brand) {
        newBrand = new char[std::strlen(other.brand) + 1];
        std::strcpy(newBrand, other.brand);
    }

    freeDynamic();
    model = newModel;
    brand = newBrand;
}

Device::Device()
    : model(nullptr), brand(nullptr), price(0) {}

Device::Device(const char* m, const char* b, int p)
    : model(nullptr), brand(nullptr), price(0) {
    try {
        setModel(m);
        setBrand(b);
        setPrice(p);
    } catch (...) {
        freeDynamic();
        throw;
    }
}

Device::Device(const Device& other)
    : model(nullptr), brand(nullptr), price(other.price) {
    try {
        copyDynamic(other);
    } catch (...) {
        freeDynamic();
        throw;
    }
}

Device& Device::operator=(const Device& other) {
    if (this != &other) {
        Device temp(other);      
        freeDynamic();           
        model = temp.model;      
        brand = temp.brand;
        price = temp.price;

        temp.model = nullptr;
        temp.brand = nullptr;
    }
    return *this;
}

Device::~Device() {
    freeDynamic();
}

const char* Device::getModel() const { return model; }
const char* Device::getBrand() const { return brand; }
int Device::getPrice() const { return price; }

void Device::setModel(const char* m) {
    if (!m)
        throw std::invalid_argument("Model cannot be null");

    char* newModel = new char[std::strlen(m) + 1];
    std::strcpy(newModel, m);

    delete[] model;
    model = newModel;
}

void Device::setBrand(const char* b) {
    if (!b)
        throw std::invalid_argument("Brand cannot be null");

    char* newBrand = new char[std::strlen(b) + 1];
    std::strcpy(newBrand, b);

    delete[] brand;
    brand = newBrand;
}

void Device::setPrice(int p) {
    if (p < 0)
        throw std::invalid_argument("Price cannot be negative");
    price = p;
}
