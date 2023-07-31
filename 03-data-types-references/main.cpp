#include <iostream>

int main() {
    int number = 41;
    int &numberRef = number;

    std::cout << numberRef << std::endl;
}
