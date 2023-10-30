#include <iostream>

int main() {
    int a = 10;
    float b = (float)a;
    float c = static_cast<float>(a);
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    const int d = 22;
    int* ptr = const_cast<int*>(&d);
    std::cout << *ptr << std::endl;
}
