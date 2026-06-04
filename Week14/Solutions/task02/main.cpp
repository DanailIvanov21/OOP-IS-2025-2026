#include <iostream>
#include "Queue.hpp"

int main() {
    Queue<int> q;

    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(10);

    std::cout << q.dequeue() << std::endl; // 3
    std::cout << q.dequeue() << std::endl; // 5
    std::cout << q.dequeue() << std::endl; // 10

    std::cout << q.isEmpty() << std::endl; // 1

    return 0;
}
