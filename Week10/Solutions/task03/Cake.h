#pragma once
#include <iostream>
#include <stdexcept>

class Cake {
private:
    double flour;   
    double water;   
    double sugar;   
    int pieces;     

public:
    Cake();
    Cake(double f, double w, double s);

    int getPieces() const;
    double pieceSize() const; // size of one piece

    Cake& operator/=(int n);
    Cake operator/(int n) const;

    Cake& operator+=(int n);  
    Cake operator+(int n) const;

    Cake& operator-=(int n);  
    Cake operator-(int n) const;

    bool operator==(const Cake& other) const;
    bool operator!=(const Cake& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Cake& c);
};
