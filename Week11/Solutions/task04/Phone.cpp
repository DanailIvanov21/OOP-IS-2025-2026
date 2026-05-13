#include "Phone.h"

Phone::Phone() : model("Unknown"), brand("Unknown"), basePrice(0.0) {}

Phone::Phone(const MyString& m, const MyString& b, double price)
    : model(m), brand(b), basePrice(price) {}

const MyString& Phone::getModel() const { return model; }
const MyString& Phone::getBrand() const { return brand; }
double Phone::getBasePrice() const { return basePrice; }

void Phone::setModel(const MyString& m) { model = m; }
void Phone::setBrand(const MyString& b) { brand = b; }
void Phone::setBasePrice(double p) { basePrice = p; }

double Phone::getPrice() const {
    return basePrice;
}

std::ostream& operator<<(std::ostream& os, const Phone& p) {
    os << p.brand << " " << p.model << " | Price: " << p.getPrice();
    return os;
}
