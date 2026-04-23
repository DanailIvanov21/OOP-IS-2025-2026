#include <iostream>
#include "MyString.h"

int main() {
    MyString a("Hello");
    MyString b("World");

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    MyString c = a + MyString(" ") + b;
    std::cout << "c = " << c << "\n";

    c[0] = 'h';
    std::cout << "modified c = " << c << "\n";

    std::cout << "Compare a < b: " << (a < b) << "\n";
    std::cout << "Compare a == b: " << (a == b) << "\n";

    return 0;
}
