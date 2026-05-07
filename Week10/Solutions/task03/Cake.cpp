#include "Cake.h"

Cake::Cake() : flour(0), water(0), sugar(0), pieces(0) {}

Cake::Cake(double f, double w, double s)
    : flour(f), water(w), sugar(s), pieces(0) {}

int Cake::getPieces() const {
    return pieces;
}

double Cake::pieceSize() const {
    if (pieces == 0) return 1.0; // whole cake
    return 1.0 / pieces;
}

Cake& Cake::operator/=(int n) {
    if (n <= 0)
        throw std::invalid_argument("Invalid number of pieces");

    if (pieces == 0) {
        // first division
        pieces = n;
        return *this;
    }

    if (n % pieces != 0)
        throw std::invalid_argument("New division must be multiple of previous");

    pieces = n;
    return *this;
}

Cake Cake::operator/(int n) const {
    Cake temp(*this);
    temp /= n;
    return temp;
}

Cake& Cake::operator+=(int n) {
    if (n < 0)
        throw std::invalid_argument("Cannot add negative pieces");

    if (pieces == 0)
        throw std::logic_error("Cake must be divided before adding pieces");

    if (pieces + n > pieces)
        pieces += n;

    return *this;
}

Cake Cake::operator+(int n) const {
    Cake temp(*this);
    temp += n;
    return temp;
}

Cake& Cake::operator-=(int n) {
    if (n < 0)
        throw std::invalid_argument("Cannot remove negative pieces");

    if (n > pieces)
        throw std::invalid_argument("Not enough pieces to remove");

    pieces -= n;
    return *this;
}

Cake Cake::operator-(int n) const {
    Cake temp(*this);
    temp -= n;
    return temp;
}

bool Cake::operator==(const Cake& other) const {
    return flour == other.flour &&
           water == other.water &&
           sugar == other.sugar &&
           pieces == other.pieces;
}

bool Cake::operator!=(const Cake& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Cake& c) {
    os << "Cake: flour=" << c.flour
       << "g, water=" << c.water
       << "ml, sugar=" << c.sugar
       << "g, pieces=" << c.pieces;
    return os;
}
