#include <iostream>

int main() {
    int a;
    std::cout << "Enter a number:";
    std::cin >> a;
    std::cout << "You entered: " << a << std::endl;

    // Standard Error Output
    std::cerr << "An error occurred." << std::endl;

    // Buffered
    std::clog << "Logging information." << std::endl;

    return 0;
}
