#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero!";
    }

    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const char *msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}