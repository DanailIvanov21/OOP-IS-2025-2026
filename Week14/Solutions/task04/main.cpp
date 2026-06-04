#include <iostream>
#include "Relation.hpp"

int main() {
    Relation<int> r1(2, 6, "is smaller than");
    Relation<int> r2(6, 3, "is divisible by");

    Relation<int> r3 = r1 * r2;

    r1.print(); // 2 is smaller than 6.
    r2.print(); // 6 is divisible by 3.
    r3.print(); // 2 is smaller than 6, which is divisible by 3.

    Relation<int> bad1(2, 6, "is smaller than");
    Relation<int> bad2(7, 3, "is divisible by");

    Relation<int> r4 = bad1 * bad2;
    r4.print(); // връща bad1

    return 0;
}
