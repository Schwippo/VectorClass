#include <iostream>
#include "myVector.h"

int main() {
    myVector my;

    my.push_back(10);
    my.push_back(20);
    my.push_back(30);

    std::cout << "v[0] = " << my.at(0) << "\n";
    std::cout << "v[1] = " << my.at(1) << "\n";
    std::cout << "pop_back: " << my.pop_back() << "\n";
    std::cout << "pop_back: " << my.pop_back() << "\n";
    std::cout << "v[1] = " << my.at(1) << "\n";

    std::cout << "Größe: " << my.getSize() << ", Kapazität: " << my.getCapacity() << "\n";
    return 0;
}