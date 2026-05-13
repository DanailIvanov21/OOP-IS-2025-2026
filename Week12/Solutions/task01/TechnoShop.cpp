#include "TechnoShop.h"
#include <cstring>
#include <stdexcept>

void TechnoShop::freeDynamic() {
    delete[] name;
    name = nullptr;

    if (devices) {
        for (size_t i = 0; i < size; i++)
            delete devices[i];
        delete[] devices;
    }
    devices = nullptr;
    size = 0;
    capacity = 0;
}

void TechnoShop::copyDynamic(const TechnoShop& other) {
    char* newName = nullptr;
    Device** newArr = nullptr;

    try {
        if (other.name) {
            newName = new char[std::strlen(other.name) + 1];
            std::strcpy(newName, other.name);
        }

        if (other.capacity > 0) {
            newArr = new Device*[other.capacity];
            size_t i = 0;
            try {
                for (; i < other.size; i++)
                    newArr[i] = other.devices[i]->clone();
            } catch (...) {
                for (size_t j = 0; j < i; j++)
                    delete newArr[j];
                delete[] newArr;
                delete[] newName;
                throw;
            }
        }
    } catch (...) {
        throw;
    }

    freeDynamic();
    name = newName;
    devices = newArr;
    size = other.size;
    capacity = other.capacity;
}

void TechnoShop::resize() {
    size_t newCap = (capacity == 0 ? 2 : capacity * 2);
    Device** newArr = new Device*[newCap];

    for (size_t i = 0; i < size; i++)
        newArr[i] = devices[i];

    delete[] devices;
    devices = newArr;
    capacity = newCap;
}

TechnoShop::TechnoShop()
    : name(nullptr), devices(nullptr), size(0), capacity(0) {}

TechnoShop::TechnoShop(const char* n)
    : name(nullptr), devices(nullptr), size(0), capacity(0) {
    setName(n);
}

TechnoShop::TechnoShop(const TechnoShop& other)
    : name(nullptr), devices(nullptr), size(0), capacity(0) {
    copyDynamic(other);
}

TechnoShop& TechnoShop::operator=(const TechnoShop& other) {
    if (this != &other)
        copyDynamic(other);
    return *this;
}

TechnoShop::~TechnoShop() {
    freeDynamic();
}

const char* TechnoShop::getName() const { return name; }

void TechnoShop::setName(const char* n) {
    if (!n)
        throw std::invalid_argument("Name cannot be null");

    char* newName = new char[std::strlen(n) + 1];
    std::strcpy(newName, n);

    delete[] name;
    name = newName;
}

bool TechnoShop::addDevice(const Device& d) {
    Device* cloned = nullptr;
    try {
        cloned = d.clone();
    } catch (...) {
        return false;
    }

    if (size == capacity) {
        try {
            resize();
        } catch (...) {
            delete cloned;
            throw;
        }
    }

    devices[size++] = cloned;
    return true;
}

bool TechnoShop::removeDevice(const char* m, const char* b) {
    if (!m || !b)
        throw std::invalid_argument("Null model/brand in removeDevice");

    for (size_t i = 0; i < size; i++) {
        if (std::strcmp(devices[i]->getModel(), m) == 0 &&
            std::strcmp(devices[i]->getBrand(), b) == 0) {

            delete devices[i];
            for (size_t j = i; j < size - 1; j++)
                devices[j] = devices[j + 1];
            size--;
            return true;
        }
    }
    return false;
}

void TechnoShop::printAll(std::ostream& os) const {
    os << "TechnoShop: " << (name ? name : "Unnamed") << "\n";
    for (size_t i = 0; i < size; i++) {
        devices[i]->print(os);
        os << "\n";
    }
}

void TechnoShop::saveToFile(std::ostream& os) const {
    os << (name ? name : "") << "\n";
    os << size << "\n";
    for (size_t i = 0; i < size; i++)
        devices[i]->saveToFile(os);
}

void TechnoShop::loadFromFile(std::istream& is) {
    freeDynamic();

    char buffName[256];
    if (!is.getline(buffName, 256))
        throw std::runtime_error("Failed to read shop name");

    setName(buffName);

    size_t count;
    if (!(is >> count))
        throw std::runtime_error("Failed to read devices count");
    is.ignore();

    capacity = count;
    devices = new Device*[capacity];
    size = 0;

    for (size_t i = 0; i < count; i++) {
        char type[32];
        if (!is.getline(type, 32))
            throw std::runtime_error("Failed to read device type");

        Device* d = nullptr;
        if (std::strcmp(type, "PHONE") == 0)
            d = new Phone();
        else if (std::strcmp(type, "LAPTOP") == 0)
            d = new Laptop();
        else
            throw std::runtime_error("Unknown device type");

        try {
            d->loadFromFile(is);
        } catch (...) {
            delete d;
            throw;
        }
        devices[size++] = d;
    }
}
